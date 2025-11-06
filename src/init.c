#include "../fractol.h"


void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win,
		KeyPress,
		KeyPressMask,
		key_handler,
		fractal);
	mlx_hook(fractal->mlx_win,
		ButtonPress,
		ButtonPressMask,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->iterations = 10;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
	fractal->color_change = 0;
}

void	*init_img(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!(fractal->mlx_ptr))
		return (NULL);
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr,
		WIDTH, HEIGHT, "fractol");
	if (!(fractal->mlx_win))
		return (close_handler(fractal), NULL);
	fractal->img.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!(fractal->img.img))
		return (close_handler(fractal), NULL);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length, &fractal->img.endian);
	if (!(fractal->img.addr))
		return (close_handler(fractal), NULL);
	return (fractal);
}
