/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:35:45 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/05/01 17:56:05 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_status = BUSY;

void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		g_status = READY;
	else if (signum == SIGUSR2)
	{
		write(1, "Msg printed succesfully!\n", 25);
		return ;
	}
}

char	*encrypt_msg(char *msg)
{
	int		i;
	int		j;
	int		k;
	int		bit;
	char	*enc_msg;

	i = 0;
	j = 0;
	enc_msg = malloc((8 * ft_strlen(msg)) + 1);
	if (!enc_msg)
		return (NULL);
	while (msg[i] != '\0')
	{
		k = 8;
		while (k--)
		{
			bit = ((msg[i] >> k) & 1) + '0';
			enc_msg[j++] = bit;
		}
		i++;
	}
	enc_msg[j] = '\0';
	return (enc_msg);
}

int	end_msg(pid_t pid)
{
	int	i;
	int	res;

	i = 8;
	while (i > 0)
	{
		res = kill(pid, SIGUSR1);
		if (res != 0)
			return (-1);
		while (g_status == BUSY)
			usleep(42);
		g_status = BUSY;
		i--;
	}
	return (0);
}

int	send_msg(pid_t pid, char *msg)
{
	int	i;
	int	res;

	i = 0;
	while (msg[i] != '\0')
	{
		if ((msg[i] - '0') == 0)
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		if (res != 0)
			return (-1);
		while (g_status == BUSY)
			;
		g_status = BUSY;
		i++;
	}
	res = end_msg(pid);
	if (res != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*msg;
	struct sigaction	sa;

	if (argc == 3)
	{
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sa.sa_handler = ack_handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
			exit(0);
		msg = encrypt_msg(argv[2]);
		if (!msg)
			return (1);
		if (send_msg(server_pid, msg) != 0)
			write(1, "Failed to send the msg!\n", 24);
		free(msg);
		sleep(1);
	}
	else
		write(1, "Usage: ./client [server PID] [message]\n", 40);
}
