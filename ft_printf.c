/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:55:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/01 22:57:21 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

#include <stdio.h>

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
	/*
	char c = 'k';
	int  i = 123456789;
	unsigned u = 123456789;
	char *s = "123456789s";
	int num = 14506;
	printf("c = %-10c\n", c);
	printf("c = %10c\n", c);
//	printf("c = %+c\n", c);
//	printf("c = %#c\n", c);
//	printf("c = %0c\n", c);
//	printf("c = % c\n", c);
//	printf("c = %c\n", c);

	printf("s = %-50s\n", s);
//	printf("s = %+s\n", s);
//	printf("s = %#s\n", s);
//	printf("s = %0s\n", s);
//	printf("s = % s\n", s);
	printf("s = %50s\n", s);


	printf("i = %-4d\n", i);
	printf("i = %+4d\n", 0);
	printf("i = %015d\n", i);
	printf("i = % d\n", i);
	printf("i = %1d\n", i);
	printf("i = %10d\n", i);
	printf("i = %-10d\n", i);
	printf("i = %+10d\n", i);
	
	printf("u = %-4u\n", i);
	printf("u = %015u\n", i);
	printf("u = %1u\n", i);
	printf("u = %10u\n", i);
	printf("u = %-10u\n", i);

	printf("ihh = %-4hhd\n", c);
//	printf("ihh = %#hhd\n", c);
	printf("ihh = %010hhd\n", c);
	printf("ihh = %1hhd\n", c);
	printf("ihh = %10hhd\n", c);
	printf("ihh = %-10hhd\n", c);

	printf("------------%d\n", p);
	printf("------------%-15p\n", p);
	printf("------------%15p\n", p);

	//ft_printf("hello = %c int = %d\n", c, 14506);
	*/

	t_specs		s;
	char		c;
	long long int lli = LLONG_MIN;
	unsigned long long int ulli = ULLONG_MAX;
	long long int lli1 = 0xabcdef;
	long long int lli2 = 0123;
	long long int lli9 = 9999;
	void		*p;
	char		*str = "hello";
	char		*itoa;
	char		*itoa_u;

	itoa = ft_itoa_base(lli, 10, 1);
	itoa_u = ft_itoa_base_u(ulli, 10, 1);
	printf("ftitoa = %s\nllitoa = %llu\n", itoa_u, ulli);	
	printf("itoa9 = %s\nitoa9 = %.5lld\n", itoa, lli9);
	ft_putstr(itoa);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	c = 'k';
	s.fd = 1;
	s.minus = 1;
	s.width = 10;
	s.prec = 3;
	s.base = 10;
	s.is_upper = 1;
	print_char(&s, c);
	ft_putchar('\n');
	print_string(&s, str);
	ft_putchar('\n');
	s.minus = 0;
	print_char(&s, c);
	ft_putchar('\n');
	print_string(&s, str);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	print_int(&s, lli);
	ft_putchar('\n');
	print_uint(&s, lli);
	ft_putchar('\n');
	return (0);
}
