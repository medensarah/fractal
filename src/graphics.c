/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:43:30 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/07 23:34:10 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

void	display_pixel(t_fractal *fractal, t_point p)
{
	t_complex	c;
	t_complex	z;

	if (!strcmp(fractal->name, "mandelbrot"))
	{
		c.r = convert_range(p.x, WIDTH, -1.5, 0.5)
			* fractal->zoom + fractal->shift_x;
		c.i = convert_range(p.y, HEIGHT, -1, 1)
			* fractal->zoom + fractal->shift_y;
		z.r = c.r;
		z.i = c.i;
	}
	if (!strcmp(fractal->name, "julia"))
	{
		c.r = fractal->julia_x;
		c.i = fractal->julia_y;
		z.r = convert_range(p.x, WIDTH, -1.5, 1.5)
			* fractal->zoom + fractal->shift_x;
		z.i = convert_range(p.y, HEIGHT, -1.5, 1.5)
			* fractal->zoom + fractal->shift_y;
	}
	draw_pixel(fractal, &c, &z, p);
}

void	draw_pixel(t_fractal *fractal, t_complex *c, t_complex *z, t_point p)
{
	int			i;
	int			limit;
	double		t;
	int			color;

	i = 0;
	limit = 100;
	while ((z->r * z->r + z->i * z->i) < 4)
	{
		i++;
		if (i >= limit)
		{
			my_mlx_pixel_put(&fractal->img, p, 0x000000);
			return ;
		}
		*z = add_complex(square_complex(*z), *c);
	}
	t = (double)i / limit;
	color = get_color_iteration(t);
	my_mlx_pixel_put(&fractal->img, p, color);
}
