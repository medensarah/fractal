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

