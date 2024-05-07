/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:00:03 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/06 18:00:06 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == ESCAPE)
		close_handle(fractal);
	if (keysym == LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == PLUS)
		fractal->iterations += 10;
	else if (keysym == MINUS)
		fractal->iterations -= 10;
	fractol_render_burningship(fractal);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == BUTTON5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == BUTTON4)
	{
		fractal->zoom *= 1.05;
	}
	fractol_render_burningship(fractal);
	return (0);
}

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_handle, fractal);
	mlx_hook(fractal->mlx_window, BUTTONPRESS, 0, mouse_handle, fractal);
	mlx_hook(fractal->mlx_window, DESTROYNOTIFY, 0, close_handle, fractal);
}
