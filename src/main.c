/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:49:49 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/07 20:49:52 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	display_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			display_pixel(fractal, x, y);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 1)
	{
		printf("Available parameters :\n");
		printf("mandelbrot\n");
		printf("julia <float> <float>\n");
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
