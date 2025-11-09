/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:51:42 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/09 00:23:24 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	convert_range(double v, double max_src, double min_dst, double max_dst)
{
	return (min_dst + v * (max_dst - min_dst) / max_src);
}

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

// ./fractol julia 0.285 0.01
// ./fractol julia 0.0 0.7
