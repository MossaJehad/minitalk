/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:36:14 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/09/21 20:31:25 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!dest && !src)
		return (0);
	s = (char *)src;
	d = dest;
	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
