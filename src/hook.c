/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:43:30 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/09 02:17:25 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	if (keycode == XK_Escape)
		close_handler(fractal);
	else if (keycode == XK_Left || keycode == 65361)
		fractal->shift_x -= (0.2 * fractal->zoom);
	else if (keycode == XK_Right || keycode == 65363)
		fractal->shift_x += (0.2 * fractal->zoom);
	else if (keycode == XK_Up || keycode == 65362)
		fractal->shift_y += (0.2 * fractal->zoom);
	else if (keycode == XK_Down || keycode == 65364)
		fractal->shift_y -= (0.2 * fractal->zoom);
	else if (keycode == XK_plus || keycode == 65451)
		fractal->iterations += 5;
	else if (keycode == XK_minus || keycode == 65453)
		fractal->iterations -= 5;
	display_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win,
		fractal->img.img, 0, 0);
	return (0);
}

int	mouse_handler(int button, t_point p, t_fractal *fractal)
{
	(void)p;
	if (button == Button5)
		fractal->zoom *= 1.25;
	else if (button == Button4)
		fractal->zoom *= 0.75;
	display_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->mlx_win, fractal->img.img, 0, 0);
	return (0);
}

int	mouse_wrapper(int button, int x, int y, void *param)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (mouse_handler(button, p, (t_fractal *)param));
}
