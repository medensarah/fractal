/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:09:32 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/09 18:11:12 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
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

typedef struct t_fractal
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*name;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	zoom;
	t_data	img;
}			t_fractal;

typedef struct s_complex
{
	float	r;
	float	i;
}				t_complex;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

void		*init_img(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		event_init(t_fractal *fractal);
void		my_mlx_pixel_put(t_data *data, t_point p, int color);

//handler
int			mouse_wrapper(int button, int x, int y, void *param);
int			mouse_handler(int button, t_point p, t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);

//graphics
void		display_fractal(t_fractal *fractal);
void		display_pixel(t_fractal *fractal, t_point p);
void		draw_pixel(t_fractal *fractal, t_complex *c,
				t_complex *z, t_point p);

//maths
double		convert_range(double v, double max_src,
				double min_dst, double max_dst);
t_complex	add_complex(t_complex nb1, t_complex nb2);
t_complex	square_complex(t_complex nb);

//parsing
double		atoi_double(char *str);
int			is_number(char *str);
int			parsing(int argc, char **argv, t_fractal *fractal);
int			ft_strcmp(const char *s1, const char *s2);
int			strlong(char *str);

#endif
