/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:12:25 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/30 18:12:30 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_addbase(unsigned long nbr)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nbr < 16)
	{
		count += ft_putchar(base[nbr]);
	}
	else
	{
		count += ft_print_addbase(nbr / 16);
		count += ft_print_addbase(nbr % 16);
	}
	return (count);
}

int	ft_putadd(void *ptr)
{
	int				count;
	unsigned long	nbr;

	count = 0;
	nbr = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_print_addbase(nbr);
	return (count);
}
