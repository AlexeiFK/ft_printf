/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:58:14 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/02 22:00:18 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag_u(t_specs *s, unsigned int num)
{
	return (print_uint(s, num));
}

int	print_flag_u_l(t_specs *s, unsigned long int num)
{
	return (print_uint(s, num));
}

int	print_flag_u_hh(t_specs *s, unsigned char num)
{
	return (print_uint(s, num));
}

int	print_flag_u_h(t_specs *s, unsigned short int num)
{
	return (print_uint(s, num));
}

int	print_flag_u_ll(t_specs *s, unsigned long long int num)
{
	return (print_uint(s, num));
}
