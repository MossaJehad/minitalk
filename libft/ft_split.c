/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:54:09 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/05 23:07:28 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int finish)
{
	char	*word;
	int		i;

	word = (char *)malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	extract_words(char **split, const char *s, char c, int *index)
{
	int	i;
	int	start;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			split[*index] = word_dup(s, start, i);
			if (!split[*index])
			{
				return (0);
			}
			(*index)++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		index;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	index = 0;
	if (!extract_words(split, s, c, &index))
	{
		while (index > 0)
			free(split[--index]);
		free(split);
		return (NULL);
	}
	split[index] = NULL;
	return (split);
}
