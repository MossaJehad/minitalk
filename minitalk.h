/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:25:00 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/24 19:43:34 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"
# define BUSY 0
# define READY 1

void		handler(int signum, siginfo_t *info, void *ucontext);
void		ack_handler(int signum);
int			send_msg(pid_t pid, char *msg);
char		*init_msg(void);
void		print_msg(pid_t c_pid);
char		*add_char_to_msg(char c);
void		cleanup_handler(int signum);

#endif