/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:17:25 by ccellado          #+#    #+#             */
/*   Updated: 2019/09/14 21:29:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	parse_type(va_list pars, t_specs *s, int *count)
{
	if (s->width < -1)
		s->width = -1;
	if (s->prec < -1)
		s->prec = -1;
	if (s->type == 'c')
		*count += print_flag_c(s, (char)va_arg(pars, int));
	else if (s->type == 's')
		*count += print_flag_s(s, (char*)va_arg(pars, long int));
	else if (s->type == '%')
		*count += print_flag_perc(s);
	else if (s->type == 'p')
		*count += print_flag_p(s, (void*)va_arg(pars, long int));
	else if (s->type == 'd' || s->type == 'i')
		*count += parse_type_di(pars, s);
	else if (s->type == 'o')
		*count += parse_type_o(pars, s);
	else if (s->type == 'u')
		*count += parse_type_u(pars, s);
	else if (s->type == 'x')
		*count += parse_type_x(pars, s);
	else if (s->type == 'X')
		*count += parse_type_x_big(pars, s);
	else if (s->type == 'f')
		*count += parse_type_f(pars, s);
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == '0'
			|| c == ' ' || c == '#')
		return (1);
	else
		return (0);
}

void	write_n_count(const char *c, int *count)
{
	write(1, c, 1);
	(*count)++;
}
