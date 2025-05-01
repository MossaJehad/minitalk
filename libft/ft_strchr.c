/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:03:22 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/02 21:01:23 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	ch = c;
	i = ft_strlen(s);
	if (ch == '\0')
		return ((char *)(s) + i);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)(s) + i);
		i++;
	}
	return (0);
}
