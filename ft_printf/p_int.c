/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:11:14 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 22:59:16 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int			print_int(t_specs *s, long long int c)
{
	char		empty;
	int			n_digits;
	char		*itoa_out;
	int			n_printed;

	itoa_out = ft_itoa_base(c, s->base, s->is_upper);
	n_digits = 0;
	if (s->prec != 0 || c != 0)
		n_digits = ft_strlen(itoa_out);
	if (s->prec != -1 && n_digits <= s->prec && s->prec != 0)
		int_prec_set(&itoa_out, &n_digits, s->prec);
	else if (s->prec == -1 && s->zero == 1 &&
			s->width > n_digits && s->minus == 0)
		int_prec_set(&itoa_out, &n_digits, s->width - 1);
	empty = choose_empty_symbol(s);
	n_digits += get_sign_int(s, c);
	if (s->minus == 0)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	print_sign_int(s, c);
	if (s->prec != 0 || c != 0)
		ft_putstr_fd(itoa_out, s->fd);
	free(itoa_out);
	if (s->minus == 1)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	return (n_printed + n_digits);
}

static int	print_uint_extra(t_specs *s,
		unsigned long long c, int n_digits, char *itoa_out)
{
	char		empty;
	int			n_printed;

	n_printed = 0;
	empty = choose_empty_symbol(s);
	if (s->minus == 0)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	if (s->prec != 0 || c != 0 ||
			(c == 0 && s->prec == 0 && s->sharp == 1 && s->base == 8))
		ft_putstr_fd(itoa_out, s->fd);
	free(itoa_out);
	if (s->minus == 1)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	return (n_printed);
}

int			print_uint(t_specs *s, unsigned long long int c)
{
	char		*itoa_out;
	int			n_digits;
	int			n_printed;
	int			tmp_dig;

	itoa_out = ft_itoa_base_u(c, s->base, s->is_upper);
	n_digits = 0;
	if (s->prec != 0 || c != 0 ||
			(c == 0 && s->prec == 0 && s->sharp == 1 && s->base == 8))
		n_digits = ft_strlen(itoa_out);
	tmp_dig = n_digits;
	if (s->prec != -1 && n_digits < s->prec)
		int_prec_set(&itoa_out, &n_digits, s->prec);
	else if (s->prec == -1 && s->zero == 1 &&
			s->width > n_digits && s->minus == 0)
		int_prec_set(&itoa_out, &n_digits, s->width - b_c(s));
	if ((c != 0 || s->prec != 0))
		if (!(c == 0 && s->base == 16 && s->sharp == 1))
			append_spec_c(&itoa_out, s, &n_digits, tmp_dig);
	n_printed = print_uint_extra(s, c, n_digits, itoa_out);
	return (n_printed + n_digits);
}
