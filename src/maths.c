#include "../fractol.h"

double	convert_range(double v, double max_src, double min_dst, double max_dst)
{
	return (min_dst + v * (max_dst - min_dst) / max_src);
}
