/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:47:38 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/06 18:07:47 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char		*dest;
	const unsigned char	*src;

	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	if (dest == src)
		return (dest);
	if (!destination && !source)
		return (NULL);
	while (num--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (destination);
}
