/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:48:29 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/18 23:52:09 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int	counter;
	int	sign;

	counter = 0;
	sign = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char		*arg;
	int			len;
	long long	nb;

	len = count_digits(n);
	if (n < 0)
		len++;
	nb = (long long)n * ((n > 0) - (n < 0));
	arg = (char *)malloc((len + 1) * sizeof(char));
	if (!arg)
		return (NULL);
	arg[len] = '\0';
	while (len-- != 0)
	{
		arg[len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		arg[0] = '-';
	return (arg);
}
