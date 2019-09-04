/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:02:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/04 16:08:25 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		print_flag_x(t_specs *s, unsigned int num)
{
	s->base = 16;
	s->is_upper = 0;
	return (print_uint(s, num));
}

int		print_flag_x_l(t_specs *s, unsigned long int num)
{
	s->base = 16;
	s->is_upper = 0;
	return (print_uint(s, num));
}

int		print_flag_x_hh(t_specs *s, unsigned char num)
{
	s->base = 16;
	s->is_upper = 0;
	return (print_uint(s, num));
}

int		print_flag_x_h(t_specs *s, unsigned short int num)
{
	s->base = 16;
	s->is_upper = 0;
	return (print_uint(s, num));
}

int		print_flag_x_ll(t_specs *s, unsigned long long int num)
{
	s->base = 16;
	s->is_upper = 0;
	return (print_uint(s, num));
}
