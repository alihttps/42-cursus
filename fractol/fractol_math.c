/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:16:45 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/03 15:16:48 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	rescale(double unscaled_num, double nmin, double nmax, double max)
{
	return ((nmax - nmin) * (unscaled_num) / (max) + nmin);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = (z1.real + z2.real);
	result.i = (z1.i + z2.i);
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = ((z.real * z.real) - (z.i * z.i));
	result.i = (2 * z.real * z.i);
	return (result);
}
