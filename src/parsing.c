/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:49:17 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/09 02:25:20 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	parsing(int argc, char **argv, t_fractal *fractal)
{
	if (!argv || argc == 0)
		return (0);
	if (((!ft_strcmp(argv[1], "mandelbrot")) && (argc == 2))
		|| ((!ft_strcmp(argv[1], "julia")) && argv[2] && argv[3]
			&& (argc == 4)))
	{
		fractal->name = argv[1];
		if (!ft_strcmp(argv[1], "julia") && (argc == 4))
		{
			if (is_number(argv[2]) && is_number(argv[3])
				&& strlong(argv[2]) && strlong(argv[3]))
			{
				fractal->julia_x = atoi_double(argv[2]);
				fractal->julia_y = atoi_double(argv[3]);
				return (1);
			}
			write(1,
				"Wrong input:\nJulia requires numbers between"
				" -10.0 and 10.0, using a decimal point.\n", 83);
			return (0);
		}
		return (1);
	}
	write(1, "Wrong input\n", 12);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

double	atoi_double(char *str)
{
	double	integer_part;
	double	float_part;
	double	power;
	int		neg;

	integer_part = 0;
	float_part = 0;
	power = 1;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (*str != '.' && (*str >= '0' && *str <= '9'))
		integer_part = (*str++ - 48) + (integer_part * 10);
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		power /= 10;
		float_part += (*str++ - 48) * power;
	}
	return ((integer_part + float_part) * neg);
}

int	is_number(char *str)
{
	int	i;
	int	sign;
	int	point;

	i = 0;
	sign = 0;
	point = 0;
	if (!str)
		return (0);
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if ((str[i] != '+') && (str[i] != '-') && (str[i] != '.')
			&& !(str[i] >= '0' && str[i] <= '9'))
			return (0);
		if ((str[i] == '+') && (str[i] == '-'))
			sign++;
		if (str[i] == '.')
			point++;
		i++;
	}
	if (point != 1 || sign >= 2)
		return (0);
	return (1);
}

int	strlong(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' && (str[i] == '-'))
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] && (str[i] != '.'))
		i++;
	if (str[i] == '.' && !(str[i + 1]))
		return (0);
	if (str[i + 1] && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (0);
	if (i >= 2)
		return (0);
	return (1);
}
