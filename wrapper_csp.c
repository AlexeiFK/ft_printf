/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:17:59 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/02 22:01:17 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag_c(t_specs *s, unsigned char c)
{
	return (print_char(s, c));
}

int	print_flag_s(t_specs *s, char *str)
{
	return (print_string(s, str));
}

int	print_flag_p(t_specs *s, void *p)
{
	s->base = 16;
	s->sharp = 1;
	return (print_flag_x_ll(s, (unsigned long long int)p));
}
