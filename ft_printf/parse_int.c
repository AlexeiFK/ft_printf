/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:15:49 by ccellado          #+#    #+#             */
/*   Updated: 2019/09/13 16:49:45 by ccellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_type_di(va_list pars, t_specs *s)
{
	int	type_count;

	if (s->size == 1)
		type_count = print_flag_di_l(s, va_arg(pars, long int));
	else if (s->size == 2)
		type_count = print_flag_di_ll(s, va_arg(pars, long long int));
	else if (s->size == 3)
		type_count = print_flag_di_h(s, (short int)va_arg(pars, int));
	else if (s->size == 4)
		type_count = print_flag_di_hh(s, (signed char)va_arg(pars, int));
	else
		type_count = print_flag_di(s, va_arg(pars, int));
	return (type_count);
}

int		parse_type_o(va_list pars, t_specs *s)
{
	int	type_count;

	if (s->size == 1)
		type_count = print_flag_o_l(s, va_arg(pars, unsigned long int));
	else if (s->size == 2)
		type_count = print_flag_o_ll(s, va_arg(pars, unsigned long long int));
	else if (s->size == 3)
		type_count = print_flag_o_h(s,
				(unsigned short int)va_arg(pars, unsigned int));
	else if (s->size == 4)
		type_count = print_flag_o_hh(s,
				(unsigned char)va_arg(pars, unsigned int));
	else
		type_count = print_flag_o(s, va_arg(pars, unsigned int));
	return (type_count);
}

int		parse_type_u(va_list pars, t_specs *s)
{
	int	type_count;

	if (s->size == 1)
		type_count = print_flag_u_l(s, va_arg(pars, unsigned long int));
	else if (s->size == 2)
		type_count = print_flag_u_ll(s, va_arg(pars, unsigned long long int));
	else if (s->size == 3)
		type_count = print_flag_u_h(s,
				(unsigned short int)va_arg(pars, unsigned int));
	else if (s->size == 4)
		type_count = print_flag_u_hh(s,
				(unsigned char)va_arg(pars, unsigned int));
	else
		type_count = print_flag_u(s, va_arg(pars, unsigned int));
	return (type_count);
}
