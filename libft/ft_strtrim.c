/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:46:24 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/04 18:00:48 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ifitsthere(char ourtext, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ourtext)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*asmar;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ifitsthere(s1[start], set))
		start++;
	while (start <= end && ifitsthere(s1[end], set))
		end--;
	asmar = (char *)malloc(end - start + 2);
	if (!asmar)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		asmar[i] = s1[start + i];
		i++;
	}
	asmar[i] = '\0';
	return (asmar);
}
