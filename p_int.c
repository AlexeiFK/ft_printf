/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:11:14 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 21:40:27 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static int	get_sign_int(t_specs *s, long long int c)
{
	if ((s->plus == 1) && (c >= 0) && (s->zero != 1))
		return (1);
	if ((s->space == 1) && (c >= 0) && (s->plus != 1) && (s->zero != 1))
		return (1);
	return (0);
}

static void	print_sign_int(t_specs *s, long long int c)
{
	if ((s->plus == 1) && (c >= 0) && (s->zero != 1))
		ft_putchar_fd('+', s->fd);
	if ((s->space == 1) && (c >= 0) && (s->plus != 1) && (s->zero != 1))
		ft_putchar_fd(' ', s->fd);
}

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
	else if (s->prec == -1 && s->zero == 1 && s->width > n_digits && s->minus == 0)
		int_prec_set(&itoa_out, &n_digits, s->width - 1);
	empty = choose_empty_symbol(s);
	n_digits += get_sign_int(s, c);
	if (s->minus == 0)
		n_printed = put_empty_symbols(empty, s->width - n_digits, s->fd);
	print_sign_int(s, c);
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
