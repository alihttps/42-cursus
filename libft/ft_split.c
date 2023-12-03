/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 02:35:21 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/20 23:55:35 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char sep)
{
	int		is_word;
	size_t	counter;

	counter = 0;
	is_word = 0;
	while (*str)
	{
		if (*str == sep)
			is_word = 0;
		else
		{
			if (is_word == 0)
			{
				is_word = 1;
				counter++;
			}
		}
		str++;
	}
	return (counter);
}

static char	*allocate(char const **s, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while ((*s)[i] && (*s)[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while ((*s)[i] && (*s)[i] != sep)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = '\0';
	*s += i + 1;
	return (word);
}

static void	free_split(char **s, int n)
{
	if (!s)
		return ;
	while (n--)
		free(s[n]);
	free(s);
}

char	**ft_split(char const *s, char sep)
{
	char	**splitted;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, sep);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == sep)
			s++;
		if (*s && *s != sep)
		{
			splitted[i] = allocate(&s, sep);
			if (!splitted[i])
				free_split(splitted, i);
		}
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}
