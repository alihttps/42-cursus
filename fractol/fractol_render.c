/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:17:44 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/03 15:17:47 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_or_mandelbrot(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->title, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->i = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (rescale(x, -2, +2, W) * fractal->zoom) + fractal->shift_x;
	z.i = (rescale(y, +2, -2, H) * fractal->zoom) + fractal->shift_y;
	julia_or_mandelbrot(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.i * z.i) > fractal->escape_point)
		{
			color = rescale(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->image, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->image, GREEN);
}

void	fractol_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
