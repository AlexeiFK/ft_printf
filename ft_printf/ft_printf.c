/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:46:07 by ccellado          #+#    #+#             */
/*   Updated: 2019/09/15 18:46:12 by ccellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static void	ft_null(t_specs *s, int *place, int *counter, int fd)
{
	specs_init(s);
	*place = 0;
	*counter = 0;
	s->fd = fd;
}

int			ft_vprintf(const char *format, va_list pars)
{
	int			place;
	int			len;
	t_specs		s;
	int			counter;

	ft_null(&s, &place, &counter, 1);
	len = ft_strlen(format);
	while (place < len)
	{
		if (format[place] == '%')
		{
			place += parse_all(format + place, &s);
			parse_type(pars, &s, &counter);
			specs_init(&s);
		}
		else
			write_n_count(&format[place], &counter);
		place++;
	}
	return (counter);
}

int			ft_printf(const char *format, ...)
{
	va_list		pars;
	int			counter;

	va_start(pars, format);
	counter = ft_vprintf(format, pars);
	va_end(pars);
	return (counter);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		pars;
	int			counter;

	va_start(pars, format);
	counter = ft_vdprintf(fd, format, pars);
	va_end(pars);
	return (counter);
}

int			ft_vdprintf(int fd, const char *format, va_list pars)
{
	int			place;
	int			len;
	t_specs		s;
	int			counter;

	ft_null(&s, &place, &counter, fd);
	len = ft_strlen(format);
	while (place < len)
	{
		if (format[place] == '%')
		{
			if (format[place + 1] == '%')
				write_n_count(&format[place++], &counter);
			else
			{
				place += parse_all(format + place, &s);
				parse_type(pars, &s, &counter);
				specs_init(&s);
			}
		}
		else
			write_n_count(&format[place], &counter);
		place++;
	}
	return (counter);
}
