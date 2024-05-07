/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:11:49 by aait-bou          #+#    #+#             */
/*   Updated: 2024/05/07 20:11:52 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define W 800
# define H 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0xCCD5C0
# define DESTROYNOTIFY 17
# define BUTTONPRESS 4
# define BUTTON5 5
# define BUTTON4 4
# define ESCAPE 53
# define LEFT 123
# define RIGHT 124
# define UP 125
# define DOWN 126
# define PLUS 69
# define MINUS 78

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;

typedef struct s_image
{
	void	*image_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;

}			t_image;

typedef struct s_fractal
{
	char	*title;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	int		iterations;
	int		escape_point;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}			t_fractal;

void		data_init_b(t_fractal *fractal);
void		fractol_init(t_fractal *fractal);
void		my_pixel_put(int x, int y, t_image *img, int color);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		julia_or_mandelbrot(t_complex *z, t_complex *c, t_fractal *fractal);
double		rescale(double unscaled_num, double nmin, double nmax, double max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handle(int keysym, t_fractal *fractal);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
int			close_handle(t_fractal *fractal);
void		events_init(t_fractal *fractal);
int			ft_strncmp(char *s1, char *s2, int n);
void		malloc_error(void);
void		fractol_render_burningship(t_fractal *fractal);

#endif
