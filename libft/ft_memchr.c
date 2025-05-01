/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:03:34 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/04 19:46:11 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;

	x = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == x)
		{
			return ((unsigned char *)s + i);
		}
		i++;
	}
	return (NULL);
}
