/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:35:51 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/24 19:03:55 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg = NULL;

void	cleanup_handler(int signum)
{
	(void)signum;
	if (g_msg)
	{
		free(g_msg);
		g_msg = NULL;
	}
	exit(0);
}

void	print_msg(pid_t c_pid)
{
	if (g_msg)
	{
		ft_putstr_fd(g_msg, 1);
		ft_putchar_fd('\n', 1);
		free(g_msg);
		g_msg = NULL;
		if (c_pid > 0)
			kill(c_pid, SIGUSR2);
	}
}

char	*add_char_to_msg(char c)
{
	int		i;
	int		j;
	char	*new_msg;

	if (!g_msg)
		g_msg = init_msg();
	i = ft_strlen(g_msg);
	new_msg = malloc(i + 2);
	if (!new_msg)
	{
		free(g_msg);
		g_msg = NULL;
		write(1, "Malloc failed\n", 14);
		exit(1);
	}
	j = 0;
	while (j < i)
	{
		new_msg[j] = g_msg[j];
		j++;
	}
	new_msg[i] = c;
	new_msg[i + 1] = '\0';
	free(g_msg);
	return (new_msg);
}

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	static int		i = 0;
	static char		byte = 0;
	static pid_t	c_pid = 0;

	(void)ucontext;
	if ((c_pid == 0 || c_pid != info->si_pid))
	{
		c_pid = info->si_pid;
		free(g_msg);
		g_msg = NULL;
		byte = 0;
		i = 0;
	}
	if (signum == SIGUSR2)
		byte |= (1 << (7 - i));
	if (++i == 8)
	{
		if (byte == 0)
			print_msg(c_pid);
		else
			g_msg = add_char_to_msg(byte);
		i = 0;
		byte = 0;
	}
	kill(c_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	struct sigaction	sa_cleanup;

	pid = getpid();
	ft_putstr_fd("This is the server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sa_cleanup.sa_handler = cleanup_handler;
	sigemptyset(&sa_cleanup.sa_mask);
	sa_cleanup.sa_flags = 0;
	sigaction(SIGINT, &sa_cleanup, NULL);
	sigaction(SIGTERM, &sa_cleanup, NULL);
	while (1)
		pause();
	return (0);
}
