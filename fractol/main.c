/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:45:49 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/03 15:45:52 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbort", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.title = av[1];
		fractal.julia_x = atodbl(av[2]);
		fractal.julia_y = atodbl(av[3]);
		fractol_init(&fractal);
		fractol_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		printf("please enter prompt as:\n\t"
			"\"./fractol mandelbort\" or \n\t"
			"\"fractol julia <real> <i>\"");
	}
	return (0);
}
