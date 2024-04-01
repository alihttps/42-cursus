#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#define w 800
#define h 800 
// imaginary number struct
typedef struct s_complex
{
    double real;
    double i;
} t_complex;

// mlx shit + image + hook values 
typedef struct s_image
{
    void *image_ptr; //pointer to imahge struct
    char *pixels_ptr; //pointer to pixels
    int bits_per_pixel;
    int endian;
    int line_len;

} t_image;

typedef struct s_fractal
{
    char* title;
    //mlx
    void *mlx_connection; //mlx_init();
    void *mlx_window; //mlx_new_window();
    //image
    t_image image;
    //data
    int iterations;
    int escape_point;

} t_fractal;

void data_init (t_fractal *fractal)
{
    fractal->iterations = 42;
    fractal->escape_point = 4;
}
void malloc_error(void)
{
    perror("malloc problem");
    exit(1);
}

double rescale(double unscaled_num, double nmin, double nmax, double max) 
{
  return ((nmax - nmin) * (unscaled_num) / (max) + nmin);
}

t_complex sum_complex (t_complex z1, t_complex z2)
{
    t_complex result;
    result.real = z1.real + z2.real;
    result.i = z1.i + z2.i;
    return result;
}

t_complex square_complex (t_complex z)
{
    t_complex result;

    result.real = (z.real * z.real) - (z.i * z.i);
    result.i = 2 * z.real * z.i;
    return result;
}
void handle_pixel (int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;

    z.real = 0;
    z.i = 0;

    c.real = rescale(x, -2, +2, w);
    c.i = rescale(y, +2, -2, h);
    //how many times can i iterate mandelbort before the point escapes 
    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.real * z.real) + (z.i * z.i) > fractal->escape_point)
        {
            color = 
            my_pixel_put();
            return;
        }
    }
    
}

void fractol_init (t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (!fractal->mlx_connection)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, w, h, fractal->title);
    if (!fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free (fractal->mlx_connection);
        malloc_error();
    }
    fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, w, h);
    if (!fractal->image.image_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free (fractal->mlx_connection);
        malloc_error();
    }
    fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.image_ptr, &fractal->image.bits_per_pixel, 
                                                    &fractal->image.line_len, &fractal->image.endian);
    //events_init(fractal);
    data_init(fractal);
}

void fractol_render (t_fractal *fractal)
{
     int x;
     int y;

     y = -1;
     while (++y < h)
        {
            x = -1;
            while (++x < w)
            {
                handle_pixel(x, y, fractal);
            }
        }
}

int ft_strncmp (char* s1, char* s2, int n)
{
    if (!s1 || !s2 || n <= 0)
        return 0;
    while (*s1 == *s2 && *s1 && n > 0)
    {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}

int main (int ac , char** av)
{
    t_fractal fractal;
    if ((ac == 2 && ft_strncmp (av[1] , "mandelbrot", 10)) 
        || (ac == 4 && ft_strncmp(av[1], "julia", 5)))
    {
        fractal.title = av[1];
        fractol_init(&fractal);
        fractol_render(&fractal);
        mlx_loop(fractal.mlx_connection);


    }

    else
    {
        printf ("please enter prompt as:\n\t\"./fractol mandelbort\" or \n\t\"fractol julia <real> <i>\"");
    }

}   
