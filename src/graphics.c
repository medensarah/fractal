/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:43:30 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/07 21:01:58 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

typedef struct s_complex
{
	float	r;
	float	i;
}				t_complex;

int	close_handler(t_fractal *fractal)
{
	if (fractal->img.img)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img.img);
	if (fractal->mlx_win)
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_ptr);
	if (fractal->mlx_ptr)
		free(fractal->mlx_ptr);
	exit(0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	printf("keycode:%d\n", keycode);
	if (keycode == XK_Escape)
		close_handler(fractal);
	else if (keycode == XK_Left || keycode == 65361)
		fractal->shift_x -= (0.2 * fractal->zoom);
	else if (keycode == XK_Right || keycode == 65363)
		fractal->shift_x += (0.2 * fractal->zoom);
	else if (keycode == XK_Up || keycode == 65362)
		fractal->shift_y -= (0.2 * fractal->zoom);
	else if (keycode == XK_Down || keycode == 65364)
		fractal->shift_y += (0.2 * fractal->zoom);
	else if (keycode == XK_plus || keycode == 65451)
		fractal->iterations += 5;
	else if (keycode == XK_minus || keycode == 65453)
		fractal->iterations -= 5;
	else if (keycode == 101)
		fractal->color_change += 50;
	display_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win,
		fractal->img.img, 0, 0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	x += 0;
	y += 0;
	if (button == Button5)
		fractal->zoom *= 1.25;
	else if (button == Button4)
		fractal->zoom *= 0.75;
	display_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->mlx_win, fractal->img.img, 0, 0);
	return (0);
}

t_complex	square_complex(t_complex nb)
{
	t_complex	res;

	res.r = nb.r * nb.r + -((nb.i) * (nb.i));
	res.i = 2 * nb.r * nb.i;
	return (res);
}

t_complex	add_complex(t_complex nb1, t_complex nb2)
{
	t_complex	res;

	res.r = nb1.r + nb2.r;
	res.i = nb1.i + nb2.i;
	return (res);
}

int	get_color_iteration(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	display_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			limit;
	int			color;
	double		t;

	i = 0;
	limit = 100;
	if (!strcmp(fractal->name, "mandelbrot"))
	{
		c.r = convert_range(x, WIDTH, -1.5, 0.5)
			* fractal->zoom + fractal->shift_x;
		c.i = convert_range(y, HEIGHT, -1, 1)
			* fractal->zoom + fractal->shift_y;
		z.r = c.r;
		z.i = c.i;
	}
	if (!strcmp(fractal->name, "julia"))
	{
		c.r = fractal->julia_x;
		c.i = fractal->julia_y;
		z.r = convert_range(x, WIDTH, -1.5, 1.5)
			* fractal->zoom + fractal->shift_x;
		z.i = convert_range(y, HEIGHT, -1.5, 1.5)
			* fractal->zoom + fractal->shift_y;
	}
	while ((z.r * z.r + z.i * z.i) < 4)
	{
		i++;
		if (i >= limit)
		{
			my_mlx_pixel_put(&fractal->img, x, y, 0x000000);
			return ;
		}
		z = add_complex(square_complex(z), c);
	}
	t = (double)i / limit;
	color = get_color_iteration(t);
	my_mlx_pixel_put(&fractal->img, x, y, color);
}
//diviser en deux
