/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:14:23 by smedenec          #+#    #+#             */
/*   Updated: 2025/10/11 18:15:35 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, "fractol");
	fractal->img.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length, &fractal->img.endian);
}
