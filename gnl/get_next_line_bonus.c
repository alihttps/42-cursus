/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:09:21 by aait-bou          #+#    #+#             */
/*   Updated: 2023/12/24 20:09:24 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*process_left(char *result)
{
	int		i;
	char	*line;

	i = 0;
	if (!result || !result[i])
		return (NULL);
	while (result[i] != '\0' && result[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1 + (result[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (result[i] && result[i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	if (result[i] == '\n')
	{
		line[i] = result[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*process_right(char *result)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (!result[i])
		return (free(result), NULL);
	line = malloc((ft_strlen(result) - i + 1) * sizeof(char));
	if (!line)
		return (free(line), NULL);
	i++;
	j = 0;
	while (result[i])
		line[j++] = result[i++];
	line[j] = '\0';
	free(result);
	return (line);
}

static char	*read_til_newline(int fd, char *result)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(result, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*result[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result[fd] = read_til_newline(fd, result[fd]);
	if (!result[fd])
		return (NULL);
	line = process_left(result[fd]);
	result[fd] = process_right(result[fd]);
	return (line);
}
