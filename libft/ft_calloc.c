/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:06:37 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/03 18:28:50 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmem, size_t size)
{
	char	*result;
	size_t	fullsize;
	size_t	i;

	i = 0;
	fullsize = nmem * size;
	result = (char *)malloc(fullsize);
	if (result == NULL)
		return (NULL);
	while (i < fullsize)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
