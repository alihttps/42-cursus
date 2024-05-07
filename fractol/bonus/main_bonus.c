/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:13:24 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/07 20:13:26 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "burningship", 12))
	{
		fractal.title = av[1];
		fractol_init(&fractal);
		fractol_render_burningship(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		printf("please enter prompt as:\n\t\"./fractol burningship\"");
	}
	return (0);
}
