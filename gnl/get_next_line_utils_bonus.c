/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:11:11 by aait-bou          #+#    #+#             */
/*   Updated: 2023/12/24 20:11:14 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0' && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *result, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!result)
	{
		result = (char *)malloc(1 * sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
	}
	if (!result || !buffer)
		return (NULL);
	line = malloc(ft_strlen(result) + ft_strlen(buffer) + 1);
	if (!line)
		return (NULL);
	i = -1;
	j = 0;
	while (result[++i] != '\0')
		line[i] = result[i];
	while (buffer[j] != '\0')
		line[i++] = buffer[j++];
	line[ft_strlen(result) + ft_strlen(buffer)] = '\0';
	free(result);
	return (line);
}
