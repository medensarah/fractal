/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:49:49 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/09 01:00:27 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
		return (1);
	fractal_init(&fractal);
	init_img(&fractal);
	event_init(&fractal);
	display_fractal(&fractal);
	mlx_put_image_to_window(fractal.mlx_ptr, fractal.mlx_win,
		fractal.img.img, 0, 0);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
