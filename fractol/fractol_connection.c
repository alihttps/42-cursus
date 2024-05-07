/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_connection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:29:25 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/02 22:29:29 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init_m(t_fractal *fractal)
{
	fractal->iterations = 42;
	fractal->escape_point = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	fractol_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, W, H,
			fractal->title);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, W, H);
	if (!fractal->image.image_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		malloc_error();
	}
	fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bits_per_pixel, &fractal->image.line_len,
			&fractal->image.endian);
	events_init(fractal);
	data_init_m(fractal);
}
