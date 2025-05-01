/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:38:10 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/24 19:04:28 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*init_msg(void)
{
	char	*g_msg;

	g_msg = malloc(1);
	if (!g_msg)
	{
		write(1, "Malloc failed\n", 14);
		exit(1);
	}
	g_msg[0] = '\0';
	return (g_msg);
}
