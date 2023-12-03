/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:03:45 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/16 20:55:53 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*last_occ;

	i = 0;
	last_occ = NULL;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (const char)c)
		{
			last_occ = &str[i];
			break ;
		}
		i--;
	}
	return ((char *)last_occ);
}
