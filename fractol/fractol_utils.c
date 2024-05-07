/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:18:32 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/03 15:18:35 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("malloc problem");
	exit(1);
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

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	atodbl(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	if (!str)
		return (0);
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
		nb = (nb * 10.0) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i++] - '0') * div);
		div *= 0.1;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * is_neg);
}
