/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_percent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:11:37 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 21:32:52 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print_percent(t_specs *s)
{
	int		n_printed;
	char	empty;

	if (s->zero == 1 && s->minus == 0)
		empty = '0';
	else if (s->zero == 0)
		empty = ' ';
	if (s->minus == 0)
		n_printed = put_empty_symbols(empty, s->width - 1, s->fd);
	ft_putchar_fd('%', s->fd);
	if (s->minus == 1)
		n_printed = put_empty_symbols(empty, s->width - 1, s->fd);
	return (n_printed + 1);
}

int			print_flag_perc(t_specs *s)
{
	return (print_percent(s));
}
