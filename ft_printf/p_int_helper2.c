/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_int_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:05:56 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 22:59:22 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	choose_empty_symbol(t_specs *s)
{
	if (s->prec == -1 && s->minus == 0)
	{
		if (s->zero == 1)
			return ('0');
		else if (s->zero == 0)
			return (' ');
	}
	return (' ');
}

int		b_c(t_specs *s)
{
	if (s->base == 8)
		return (1);
	if (s->base == 16)
		return (2);
	return (0);
}

int		get_sign_int(t_specs *s, long long int c)
{
	if ((s->plus == 1) && (c >= 0))
		return (1);
	if ((s->space == 1) && (c >= 0) && (s->plus != 1))
		return (1);
	return (0);
}

void	print_sign_int(t_specs *s, long long int c)
{
	if ((s->plus == 1) && (c >= 0))
		ft_putchar_fd('+', s->fd);
	if ((s->space == 1) && (c >= 0) && (s->plus != 1))
		ft_putchar_fd(' ', s->fd);
}
