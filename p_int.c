/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:11:14 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/01 22:57:14 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	print_int(t_specs *s, long long int c)
{
	char		empty;
	int			n_digits;
	char		*itoa_out;

	n_digits = 1;//number_of_digs_decs(c);
	//suda i v sosednuu funkciu itoa pered vsemi chto bi strlen bil
	//+ dobavit precison
	if (s->zero == 1)
		empty = '0';
	else if (s->zero == 0)
		empty = ' ';
	if (s->minus == 1)
		put_empty_symbols(empty, s->width - 1/*strlen*/, s->fd);
	if ((s->plus == 1) && (c >= 0))
		ft_putchar_fd('+', s->fd);
	if ((s->space == 1) && (c >= 0) && (s->plus != 1))
		ft_putchar_fd(' ', s->fd);
	itoa_out = ft_itoa_base(c, s->base, s->is_upper);
	ft_putstr_fd(itoa_out, s->fd);
	free(itoa_out);
	if (s->minus == 0)
		put_empty_symbols(empty, s->width - n_digits, s->fd);
}

void	print_uint(t_specs *s, unsigned long long int c)
{
	char		empty;
	char		*itoa_out;
	int			n_digits;

	n_digits = 1;//number_of_digs_decu(c);
	if (s->zero == 1)
		empty = '0';
	else if (s->zero == 0)
		empty = ' ';
	if (s->minus == 1)
		put_empty_symbols(empty, s->width - 1/*str len*/, s->fd);
	itoa_out = ft_itoa_base_u(c, s->base, s->is_upper);
	ft_putstr_fd(itoa_out, s->fd);
	free(itoa_out);
	if (s->minus == 0)
		put_empty_symbols(empty, s->width - n_digits, s->fd);
}
