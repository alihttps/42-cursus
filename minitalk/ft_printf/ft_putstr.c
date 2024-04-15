/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:09:42 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/29 23:09:46 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	countchr;

	countchr = 0;
	while (*str)
	{
		ft_putchar((int)*str);
		countchr++;
		str++;
	}
	return (countchr);
}
