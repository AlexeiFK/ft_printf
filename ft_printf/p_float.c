/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:19:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 19:53:02 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "ft_bignum.h"

int		print_dot(t_specs *s, char *dtoa)
{
	if (dtoa[0] == 'i' || dtoa[0] == 'n')
		return (0);
	if (s->sharp == 1 && s->prec == 0)
	{
		ft_putchar_fd('.', s->fd);
		return (1);
	}
	return (0);
}

int		print_float_sign(int sign, t_specs *s, char *dtoa)
{
	if (dtoa[0] == 'n')
	{
		return (0);
	}
	if (sign == 1)
	{
		ft_putchar_fd('-', s->fd);
		return (1);
	}
	if (s->plus == 1)
	{
		ft_putchar_fd('+', s->fd);
		return (1);
	}
	if (s->space == 1)
	{
		ft_putchar_fd(' ', s->fd);
		return (1);
	}
	return (0);
}

int		get_float_sign(int sign, t_specs *s, char *dtoa)
{
	if (dtoa[0] == 'n')
		return (0);
	if (sign == 1)
		return (1);
	if (s->plus == 1)
		return (1);
	if (s->space == 1)
		return (1);
	return (0);
}

int		print_double(t_specs *s, double f)
{
	int						printed;
	int						n_digits;
	char					empty;
	char					*dtoa_out;
	int						sign;

	printed = 0;
	dtoa_out = ft_dtoa(f, s->prec);
	n_digits = ft_strlen(dtoa_out);
	empty = choose_empty_symbolf(s, dtoa_out);
	sign = get_float_sign(get_sign(&f, sizeof(f)), s, dtoa_out);
	if (s->zero == 1 && empty == '0')
		sign = print_float_sign(get_sign(&f, sizeof(f)), s, dtoa_out);
	if (s->minus == 0)
		printed += put_empty_symbols(empty, s->width - n_digits - sign, s->fd);
	if (s->zero == 0 || (s->zero == 1 && empty != '0'))
		sign = print_float_sign(get_sign(&f, sizeof(f)), s, dtoa_out);
	ft_putstr_fd(dtoa_out, s->fd);
	n_digits += print_dot(s, dtoa_out);
	printed += put_empty_symbols('0', s->prec - MAX_NDIGITS, s->fd);
	if (s->minus == 1)
		printed += put_empty_symbols(' ', s->width - n_digits - sign, s->fd);
	free(dtoa_out);
	return (printed + n_digits + sign);
}
