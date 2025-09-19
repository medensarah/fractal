/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:59:31 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 22:35:45 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_libft/ft_libft.h"
#include "../ft_printf/ft_printf.h"
#include "fractol.h"

int	test(int le)
{
	ft_printf("c'est ok\n");
	return (le);
}

int	main(void)
{
	int	le;

	le = 1;
	test(le);
	return (0);
}
