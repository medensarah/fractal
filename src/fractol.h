/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:12:41 by smedenec          #+#    #+#             */
/*   Updated: 2025/09/19 22:13:13 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

# define GREEN		"\033[0;38;2;142;194;121m"
# define LIGREEN	"\033[0;38;2;142;255;105m"
# define RED		"\033[0;38;2;235;76;76;49m"
# define LIRED		"\033[0;38;2;247;14;21;49m"
# define NONE		"\033[0m"

typedef struct s_list {
	int				nbr;
	struct s_list	*next;
}	t_list;

int	test(int le);

#endif
