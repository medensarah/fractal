#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		iterations;
	char	*name;
	int		active_julia;
	int		color_change;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	zoom;
	t_data	img;
}		t_fractal;

void	*init_img(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);
void	event_init(t_fractal *fractal);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


//handler
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
int		key_handler(int keycode, t_fractal *fractal);
int		close_handler(t_fractal *fractal);


//graphics
void	display_fractal(t_fractal *fractal);
void    display_pixel(t_fractal *fractal, int x, int y);


// maths

double	convert_range(double v, double max_src, double min_dst, double max_dst);

// parsing

int parsing(int argc, char **argv, t_fractal *fractal);
int ft_strcmp(const char *s1, const char *s2);

#endif
