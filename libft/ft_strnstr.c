/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:05:27 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/04 19:45:23 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (i < len && big[i])
	{
		c = 0;
		while (big[i + c] == little[c] && (i + c) < len && big[i + c])
			c++;
		if (little[c] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
