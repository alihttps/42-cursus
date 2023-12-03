/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:31:43 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/19 00:43:20 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	inset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && inset(s1[start], set))
		start++;
	end = 0;
	while (s1[start + end])
		end++;
	while (end > 0 && inset(s1[start + end - 1], set))
		end--;
	trimmed = (char *)malloc(end + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < end)
		trimmed[i++] = s1[start++];
	trimmed[end] = '\0';
	return (trimmed);
}
