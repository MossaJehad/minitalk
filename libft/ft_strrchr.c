/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:40:22 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/02 21:02:10 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	ch = c;
	i = ft_strlen(s);
	if (!ch)
		return ((char *)(s) + i);
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)(s) + i);
		i--;
	}
	if (s[0] == ch)
		return ((char *)(s) + i);
	return (0);
}
