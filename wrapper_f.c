/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:22:36 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 22:29:09 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag_f(t_specs *s, double c)
{
	if (s->prec == -1)
		s->prec = 6;
	return (print_double(s, c));
}

int	print_flag_f_l(t_specs *s, long double c)
{
	if (s->prec == -1)
		s->prec = 6;
	return (print_long_double(s, c));
}
