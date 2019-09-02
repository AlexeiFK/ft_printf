/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:52:08 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/02 21:55:37 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag_di(t_specs *s, int num)
{
	return (print_int(s, num));
}

int	print_flag_di_l(t_specs *s, long int num)
{
	return (print_int(s, num));
}

int	print_flag_di_hh(t_specs *s, signed char num)
{
	return (print_int(s, num));
}

int	print_flag_di_h(t_specs *s, short int num)
{
	return (print_int(s, num));
}

int	print_flag_di_ll(t_specs *s, long long int num)
{
	return (print_int(s, num));
}
