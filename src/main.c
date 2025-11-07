/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:49:49 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/08 00:14:14 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, t_point p, int color)
{
	char	*dst;

	dst = data->addr + (p.y * data->line_length + p.x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	display_fractal(t_fractal *fractal)
{
	t_point	p;

	p.x = 0;
	while (p.x < WIDTH)
	{
		p.y = 0;
		while (p.y < HEIGHT)
		{
			display_pixel(fractal, p);
			p.y++;
		}
		p.x++;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 1)
	{
		write(1, "Available parameters :\n", 24);
		write(1, "mandelbrot\n", 11);
		write(1, "julia <float> <float>\n", 22);
		return (1);
	}
	if (!parsing(argc, argv, &fractal))
		return (0);
	fractal_init(&fractal);
	init_img(&fractal);
	event_init(&fractal);
	display_fractal(&fractal);
	mlx_put_image_to_window(fractal.mlx_ptr, fractal.mlx_win,
		fractal.img.img, 0, 0);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
