/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:00:53 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/06 18:00:57 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	malloc_error(void)
{
	perror("malloc problem");
	exit(EXIT_FAILURE);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && *s1 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
