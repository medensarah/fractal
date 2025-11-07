/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:51:42 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/07 20:51:44 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	convert_range(double v, double max_src, double min_dst, double max_dst)
{
	return (min_dst + v * (max_dst - min_dst) / max_src);
}
