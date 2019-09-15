/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:16:57 by ccellado          #+#    #+#             */
/*   Updated: 2019/09/13 16:51:19 by ccellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_type_x(va_list pars, t_specs *s)
{
	int	type_count;

	if (s->size == 1)
		type_count = print_flag_x_l(s, va_arg(pars, unsigned long int));
	else if (s->size == 2)
		type_count = print_flag_x_ll(s, va_arg(pars, unsigned long long int));
	else if (s->size == 3)
		type_count = print_flag_x_h(s,
				(unsigned short int)va_arg(pars, unsigned int));
	else if (s->size == 4)
		type_count = print_flag_x_hh(s,
				(unsigned char)va_arg(pars, unsigned int));
	else
		type_count = print_flag_x(s, va_arg(pars, unsigned int));
	return (type_count);
}

int		parse_type_x_big(va_list pars, t_specs *s)
{
	int	type_count;

	if (s->size == 1)
		type_count = print_flag_x_big_l(s,
				va_arg(pars, unsigned long int));
	else if (s->size == 2)
		type_count = print_flag_x_big_ll(s,
				va_arg(pars, unsigned long long int));
	else if (s->size == 3)
		type_count = print_flag_x_big_h(s,
				(unsigned short int)va_arg(pars, unsigned int));
	else if (s->size == 4)
		type_count = print_flag_x_big_hh(s,
				(unsigned char)va_arg(pars, unsigned int));
	else
		type_count = print_flag_x_big(s, va_arg(pars, unsigned int));
	return (type_count);
}
