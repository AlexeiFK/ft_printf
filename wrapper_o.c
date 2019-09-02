/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:10:16 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/02 22:02:09 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		print_flag_o(t_specs *s, unsigned int num)
{
	s->base = 8;
	s->is_upper = 0;
	if (s->sharp == 1)
	{
		ft_putstr_fd("0", s->fd);
		return (print_uint(s, num) + 1);
	}
	return (print_uint(s, num));
}

int		print_flag_o_l(t_specs *s, unsigned long int num)
{
	s->base = 8;
	s->is_upper = 0;
	if (s->sharp == 1)
	{
		ft_putstr_fd("0", s->fd);
		return (print_uint(s, num) + 1);
	}
	return (print_uint(s, num));
}

int		print_flag_o_hh(t_specs *s, unsigned char num)
{
	s->base = 8;
	s->is_upper = 0;
	if (s->sharp == 1)
	{
		ft_putstr_fd("0", s->fd);
		return (print_uint(s, num) + 1);
	}
	return (print_uint(s, num));
}

int		print_flag_o_h(t_specs *s, unsigned short int num)
{
	s->base = 8;
	s->is_upper = 0;
	if (s->sharp == 1)
	{
		ft_putstr_fd("0", s->fd);
		return (print_uint(s, num) + 1);
	}
	return (print_uint(s, num));
}

int		print_flag_o_ll(t_specs *s, unsigned long long int num)
{
	s->base = 8;
	s->is_upper = 0;
	if (s->sharp == 1)
	{
		ft_putstr_fd("0", s->fd);
		return (print_uint(s, num) + 1);
	}
	return (print_uint(s, num));
}
