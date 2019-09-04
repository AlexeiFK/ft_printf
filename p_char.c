/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:00 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/04 16:36:02 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		put_empty_symbols(unsigned char c, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
	return (i);
}

int		print_char(t_specs *s, unsigned char c)
{
	int		n_printed;

	if (s->minus == 0)
		n_printed = put_empty_symbols(' ', s->width - 1, s->fd);
	ft_putchar_fd(c, s->fd);
	if (s->minus == 1)
		n_printed = put_empty_symbols(' ', s->width - 1, s->fd);
	return (n_printed + 1);
}

int		print_string(t_specs *s, char *str)
{
	int		len;
	int		tmp_len;
	int		n_printed;

	len = ft_strlen(str);
	tmp_len = len;
	if (s->prec != -1 && s->prec < len)
		len = s->prec;
	if (s->minus == 0)
		n_printed = put_empty_symbols(' ', s->width - len, s->fd);
	if (s->prec != -1)
		ft_putnstr_fd(str, s->fd, s->prec);
	else
		ft_putnstr_fd(str, s->fd, tmp_len);
	if (s->minus == 1)
		n_printed = put_empty_symbols(' ', s->width - len, s->fd);
	return (n_printed + len);
}
