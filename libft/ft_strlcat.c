/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:28:18 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/16 20:46:27 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	dest_len;
	size_t	src_len;

	if (dest_size == 0 && dest == NULL)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= dest_size)
		return (src_len + dest_size);
	else
	{
		dest_size = dest_size - dest_len;
		ft_strlcpy(dest + dest_len, src, dest_size);
	}
	return (dest_len + src_len);
}
