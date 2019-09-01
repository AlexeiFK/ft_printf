/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:00 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/01 20:00:35 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	put_empty_symbols(unsigned char c, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
}

void	print_char(t_specs *s, unsigned char c)
{
	if (s->minus == 1)
		put_empty_symbols(' ', s->width - 1, s->fd);
	ft_putchar_fd(c, s->fd);
	if (s->minus == 0)
		put_empty_symbols(' ', s->width - 1, s->fd);
}

void	print_string(t_specs *s, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (s->prec < len)
		len = s->prec;
	if (s->minus == 1)
		put_empty_symbols(' ', s->width - len, s->fd);
	ft_putnstr_fd(str, s->fd, s->prec);
	if (s->minus == 0)
		put_empty_symbols(' ', s->width - len, s->fd);
}
