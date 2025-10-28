/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:59:31 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/28 18:49:44 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	int	i;
	int	y;
	t_fractal	fractal;

	init(&fractal);
	i = 200;
	y = 200;
	while (i < 251)
	{
		my_mlx_pixel_put(&fractal.img, i, y, 0xFFFFFF);
		while (y < 251)
		{
			my_mlx_pixel_put(&fractal.img, i, y, 0xFFFFAA);
			y++;
		}
		y = 200;
		i++;
	}
	mlx_put_image_to_window(fractal.mlx_ptr, fractal.mlx_win,
		fractal.img.img, 0, 0);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
// https://github.com/42paris/minilibx-linux
