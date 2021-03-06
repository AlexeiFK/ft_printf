/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_x_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:07:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/04 16:08:08 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		print_flag_x_big(t_specs *s, unsigned int num)
{
	s->base = 16;
	s->is_upper = 1;
	return (print_uint(s, num));
}

int		print_flag_x_big_l(t_specs *s, unsigned long int num)
{
	s->base = 16;
	s->is_upper = 1;
	return (print_uint(s, num));
}

int		print_flag_x_big_hh(t_specs *s, unsigned char num)
{
	s->base = 16;
	s->is_upper = 1;
	return (print_uint(s, num));
}

int		print_flag_x_big_h(t_specs *s, unsigned short int num)
{
	s->base = 16;
	s->is_upper = 1;
	return (print_uint(s, num));
}

int		print_flag_x_big_ll(t_specs *s, unsigned long long int num)
{
	s->base = 16;
	s->is_upper = 1;
	return (print_uint(s, num));
}
