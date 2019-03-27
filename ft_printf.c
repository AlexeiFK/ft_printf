/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:55:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/27 20:03:28 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_putnstr(const char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (i < n))
	{
		ft_putchar(str[i]);
		++i;
	}
}

void	ft_putstrn(const char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
		++i;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		++i;
	}
}

int		ft_putstrbefore(const char *str, char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
		++i;
	while ((str[i] != '\0') && (str[i] != c))
	{
		ft_putchar(str[i]);
		++i;
	}
	return (i + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		pars;
	char		*find;
	char		c1;
	int			i1;
	int			place;
	int			len;

	va_start(pars, format);
//	find = ft_strchr(format, '%');
//	ft_putnstr(format, format - find);
//	ft_putstr("\n");
	place = 0;
	len = ft_strlen(format);
	while (place < len)
	{
		place = ft_putstrbefore(format, '%', place);
//		ft_putnbr(place);
		if (format[place] == 'c')
		{
			c1 = (char)va_arg(pars, int);
			ft_putchar(c1);
			place++;
		}
		if (format[place] == 'd')
		{
			i1 = va_arg(pars, int);
			ft_putnbr(i1);
			place++;
		}
	}
//	ft_putstr("|");
//	ft_putstrn(format, format - find);
	va_end(pars);
	return (0);
}

/**************************/
int		main(int argc, char **argv)
{
	char c = 'k';
	int num = 14506;
	ft_printf("hello = %c int = %d\n", c, 14506);
	return (0);
}
