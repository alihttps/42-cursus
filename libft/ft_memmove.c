/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:10:46 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/09 15:26:28 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = dest;
	source = src;
	if (!destination && !source)
		return (NULL);
	if (destination < source)
	{
		ft_memcpy(destination, source, len);
	}
	else
	{
		while (len--)
		{
			destination[len] = source[len];
		}
	}
	return (dest);
}
