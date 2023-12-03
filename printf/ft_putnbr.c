/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:09:11 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/29 23:09:15 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base, char spec)
{
	char	*x_upper;
	char	*x_lower;
	int		countchr;

	x_upper = "0123456789ABCDEF";
	x_lower = "0123456789abcdef";
	countchr = 0;
	if (n < 0)
	{
		countchr += ft_putchar('-');
		n = -n;
	}
	if (n < base)
	{
		if (spec == 'X')
			countchr += ft_putchar(x_upper[n]);
		else
			countchr += ft_putchar(x_lower[n]);
	}
	else
	{
		countchr += ft_putnbr(n / base, base, spec);
		countchr += ft_putnbr(n % base, base, spec);
	}
	return (countchr);
}
