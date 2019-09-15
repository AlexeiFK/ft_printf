/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:16:42 by ccellado          #+#    #+#             */
/*   Updated: 2019/09/13 19:31:02 by ccellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_type_f(va_list pars, t_specs *s)
{
	int	type_count;

	if (s->size == 5)
		type_count = print_flag_f_l(s, va_arg(pars, long double));
	else
		type_count = print_flag_f(s, va_arg(pars, double));
	return (type_count);
}
