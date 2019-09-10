/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:11:14 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/10 21:07:11 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int		print_int(t_specs *s, long long int c)
{
	char		empty;
	int			n_digits;
	char		*itoa_out;
	int			n_printed;

	itoa_out = ft_itoa_base(c, s->base, s->is_upper);
	n_digits = ft_strlen(itoa_out);
	if (s->prec != -1 && n_digits < s->prec)
		int_prec_set(&itoa_out, &n_digits, s->prec);
	empty = choose_empty_symbol(s);
	if ((s->plus == 1) && (c >= 0))
		n_digits++;
	if ((s->space == 1) && (c >= 0) && (s->plus != 1))
		n_digits++;
	if (s->minus == 0)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	if ((s->plus == 1) && (c >= 0))
		ft_putchar_fd('+', s->fd);
	if ((s->space == 1) && (c >= 0) && (s->plus != 1))
		ft_putchar_fd(' ', s->fd);
	ft_putstr_fd(itoa_out, s->fd);
	free(itoa_out);
	if (s->minus == 1)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	return (n_printed + n_digits);
}

int		print_uint(t_specs *s, unsigned long long int c)
{
	char		empty;
	char		*itoa_out;
	int			n_digits;
	int			n_printed;

	itoa_out = ft_itoa_base_u(c, s->base, s->is_upper);
	n_digits = ft_strlen(itoa_out);
	if (s->prec != -1 && n_digits < s->prec)
		int_prec_set(&itoa_out, &n_digits, s->prec);
	append_spec_c(&itoa_out, s, &n_digits);
	empty = choose_empty_symbol(s);
	if (s->minus == 0)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	ft_putstr_fd(itoa_out, s->fd);
	free(itoa_out);
	if (s->minus == 1)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	return (n_printed + n_digits);
}
