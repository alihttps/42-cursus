/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:14:44 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/12 22:42:55 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_len;
	char	*result;
	char	*result_start;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(str_len + 1);
	if (!result)
		return (NULL);
	result_start = result;
	while (*s1)
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2)
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (result_start);
}
