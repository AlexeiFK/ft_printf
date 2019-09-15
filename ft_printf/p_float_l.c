/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:37:55 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 19:56:04 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "ft_bignum.h"

int		print_long_double(t_specs *s, long double f)
{
	int						printed;
	int						n_digits;
	char					empty;
	char					*dtoa_out;
	int						sign;

	printed = 0;
	dtoa_out = ft_ldtoa(f, s->prec);
	n_digits = ft_strlen(dtoa_out);
	empty = choose_empty_symbolf(s, dtoa_out);
	sign = get_float_sign(get_signl(&f, 10), s, dtoa_out);
	if (s->zero == 1 && empty == '0')
		sign = print_float_sign(get_sign(&f, 10), s, dtoa_out);
	if (s->minus == 0)
		printed += put_empty_symbols(empty, s->width - n_digits - sign, s->fd);
	if (s->zero == 0 || (s->zero == 1 && empty != '0'))
		sign = print_float_sign(get_sign(&f, 10), s, dtoa_out);
	ft_putstr_fd(dtoa_out, s->fd);
	n_digits += print_dot(s, dtoa_out);
	printed += put_empty_symbols('0', s->prec - MAX_LNDIGITS, s->fd);
	if (s->minus == 1)
		printed += put_empty_symbols(' ', s->width - n_digits - sign, s->fd);
	free(dtoa_out);
	return (printed + n_digits + sign);
}
