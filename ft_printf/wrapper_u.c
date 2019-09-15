/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:58:14 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 21:08:34 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag_u(t_specs *s, unsigned int num)
{
	if (s->sharp == 1)
		s->sharp = 0;
	return (print_uint(s, num));
}

int	print_flag_u_l(t_specs *s, unsigned long int num)
{
	if (s->sharp == 1)
		s->sharp = 0;
	return (print_uint(s, num));
}

int	print_flag_u_hh(t_specs *s, unsigned char num)
{
	if (s->sharp == 1)
		s->sharp = 0;
	return (print_uint(s, num));
}

int	print_flag_u_h(t_specs *s, unsigned short int num)
{
	if (s->sharp == 1)
		s->sharp = 0;
	return (print_uint(s, num));
}

int	print_flag_u_ll(t_specs *s, unsigned long long int num)
{
	if (s->sharp == 1)
		s->sharp = 0;
	return (print_uint(s, num));
}
