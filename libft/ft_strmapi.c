/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:41:13 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/13 23:01:09 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	if (f == NULL)
	{
		ft_strlcpy(new_str, s, len + 1);
		return (new_str);
	}
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
