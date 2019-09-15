/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:55:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/13 15:13:14 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>
#include <float.h>

#include <math.h>
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
//	char		*find;
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
int		main(void)
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
/*
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
	specs_init(&s);
	s.prec = 10;
	s.width = 20;
	ft_putchar('\n');
	print_int(&s, lli9);
	ft_putchar('\n');
//	itoa = ft_itoa_base(lli9, 10, 1);
	printf("%20.10lld\n",lli9);
	ft_putstr(itoa);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	c = 'k';
	s.fd = 1;
	s.minus = 1;
	s.width = 10;
	s.prec = 3;
	s.base = 16;
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
//	printf("%#p\n", p);
//	printf("%llo\n", lli2);
//	print_uint(&s, p);
	ft_putchar('\n');
	ft_putchar('\n');
	printf("%d\n", printf("%#x", 255));
	*/
	// START TEST
	t_specs		s;
	char	c255 = 127;
	unsigned char	u_c = 255;
	char	c = 'g';
	int im;
	int ip;
	int lli9 = 12379;
	void	*p = &im;
	void	*p0 = NULL;
	specs_init(&s);
	s.prec = 5;
	s.width = 10;
	s.plus = 0;
	s.minus = 1;
	im = print_flag_x(&s, lli9);
	printf("\n");
	ip = printf("%-10.5x", lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	im = print_flag_p(&s, p);
	printf("\n");
	ip = printf("%p", p);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	im = print_flag_p(&s, p0);
	printf("\n");
	ip = printf("%p", p0);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	im = print_flag_x(&s, lli9);
	printf("\n");
	ip = printf("%x", lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 5;
	s.width = 20;
	s.plus = 0;
	s.minus = 0;
	s.sharp = 1;
	im = print_flag_x(&s, lli9);
	printf("\n");
	ip = printf("%#20.5x", lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 5;
	s.width = 20;
	s.plus = 0;
	s.zero = 1;
	s.minus = 0;
	s.sharp = 1;
	im = print_flag_x(&s, lli9);
	printf("\n");
	ip = printf("%0#20.5x", lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = -1;
	s.width = 20;
	s.plus = 0;
	s.zero = 1;
	s.minus = 0;
	s.sharp = 0;
	im = print_flag_di(&s, -lli9);
	printf("\n");
	ip = printf("%020d", -lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = -1;
	s.width = 20;
	s.plus = 0;
	s.zero = 1;
	s.minus = 0;
	s.sharp = 0;
	im = print_flag_di(&s, lli9);
	printf("\n");
	ip = printf("%020d", lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 20;
	s.width = 5;
	s.plus = 0;
	s.minus = 0;
	s.sharp = 1;
//	im = print_flag_x_big_hh(&s, lli9);
//	printf("\n");
	//ip = printf("%#5.20hhX", lli9);
//	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 20;
	s.width = 5;
	s.plus = 0;
	s.minus = 0;
	s.sharp = 0;
	im = print_flag_di(&s, lli9);
	printf("\n");
	ip = printf("%5.20d", lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 20;
	s.width = 5;
	s.plus = 1;
	s.minus = 1;
	s.sharp = 0;
	im = print_flag_di(&s, lli9);
	printf("\n");
	ip = printf("%+-5.20d", lli9);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 5;
	s.width = 15;
	s.space = 1;
	s.plus = 0;
	s.minus = 0;
	s.sharp = 0;
//	im = print_flag_di_ll(&s, lli9);
//	printf("\n");
//	ip = printf("% 15.5lld", lli9);
//	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
//	s.prec = 5;
	s.width = 10;
//	s.space = 1;
//	s.plus = 0;
	s.minus = 1;
//	s.sharp = 0;
//	s.zero = 1;
	im = print_flag_c(&s, c);
	printf("\n");
	ip = printf("%-10c", c);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
//	s.prec = 5;
	s.width = 40;
//	s.space = 1;
//	s.plus = 0;
	s.minus = 1;
//	s.sharp = 0;
	im = print_flag_s(&s, "hello world");
	printf("\n");
	ip = printf("%-40s", "hello world");
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 40;
//	s.width = 40;
//	s.space = 1;
//	s.plus = 0;
	s.minus = 1;
//	s.sharp = 0;
	im = print_flag_s(&s, "hello world");
	printf("\n");
	ip = printf("%-.40s", "hello world");
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 3;
	im = print_flag_s(&s, "hello world");
	printf("\n");
	ip = printf("%-.3s", "hello world");
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 3;
	im = print_flag_s(&s, NULL);
	printf("\n");
	ip = printf("%-.3s", NULL);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.width = 100;
	im = print_flag_s(&s, NULL);
	printf("\n");
	ip = printf("%100s", NULL);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 40;
	s.width = 4;
//	s.space = 1;
//	s.plus = 0;
//	s.minus = 1;
//	s.sharp = 0;
	im = print_flag_s(&s, "hello world");
	printf("\n");
	ip = printf("%4.40s", "hello world");
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	s.prec = 3;
	s.width = 40;
//	s.space = 1;
//	s.plus = 0;
//	s.minus = 1;
//	s.sharp = 0;
	im = print_flag_s(&s, "hello world");
	printf("\n");
	ip = printf("%40.3s", "hello world");
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
//	s.prec = 3;
//	s.width = 40;
//	s.space = 1;
//	s.plus = 0;
//	s.minus = 1;
//	s.sharp = 0;
	im = print_flag_x_big_hh(&s, u_c);
	printf("\n");
	ip = printf("%hhX", u_c);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
//	s.prec = 3;
//	s.width = 40;
//	s.space = 1;
//	s.plus = 0;
//	s.minus = 1;
//	s.sharp = 0;
	im = print_flag_x_big(&s, c255);
	printf("\n");
	ip = printf("%X", c255);
	printf("\n-----%d-----------%d--------\n", im, ip);
//	double fl123 = DBL_MIN;
//	double fl123 = 0.41231342446455678;	
//	double fl123 = -INFINITY;
//	double fl123 = -1.0 / INFINITY;
//	double fl123 = 0.0 / 0.0;
//	double fl123 = 0x2p-1040;
//	print_mem(&fl123, sizeof(fl123));
	
	specs_init(&s);

	double fl123 = DBL_MAX;
	s.sharp = 1;
	s.width = 100;
	s.prec = 500;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.500f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = DBL_MIN;
	s.sharp = 1;
	s.width = 100;
	s.prec = 1500;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.1500f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 9999999.6895454;
	s.sharp = 1;
	s.width = 100;
	s.prec = 1500;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.1500f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 1;
	s.sharp = 1;
	s.width = -1;
	s.prec = 0;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = -INFINITY;
	s.sharp = 1;
	s.width = -1;
	s.prec = 2;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.2f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = INFINITY;
	s.sharp = 1;
	s.width = -1;
	s.prec = 2;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.2f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 0.0 / 0.0;
	s.sharp = 1;
	s.width = -1;
	s.prec = 2;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.2f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = -1 / INFINITY;
	s.sharp = 1;
	s.width = -1;
	s.prec = 2;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%.2f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 123.432;
	s.sharp = 1;
	s.width = 100;
	s.prec = 20;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%#100.20f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 123.432;
	s.sharp = 1;
	s.width = -1;
	s.prec = 20;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.20f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	//END OF TEST
	//t_specs s;
//	double fl123 = DBL_MAX;
	long double ld123 = LDBL_MAX;
	//int	ip, im;
	
	s.minus = 0;
	s.plus = 0;
	s.space = 0;
	s.sharp = 0;
	s.zero = 0;
	s.width = -1;
	s.prec = -1;
	s.is_upper = 0;
	s.base = 10;
	s.fd = 1;
	specs_init(&s);
	s.prec = 40;
	s.width = 4;
//	s.space = 1;
//	s.plus = 0;
//	s.minus = 1;
//	s.sharp = 0;
	im = print_flag_s(&s, "hello world");
	printf("\n");
	ip = printf("%4.40s", "hello world");
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 123.432;
	s.sharp = 1;
	s.width = -1;
	s.prec = 3;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.3f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 123432.9;
	s.sharp = 1;
	s.width = -1;
	s.prec = 0;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.0f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 2.5000000000000001;
	s.sharp = 1;
	s.width = -1;
	s.prec = 0;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.0f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 2.5000000000000001;
	s.sharp = 1;
	s.width = -1;
	s.prec = 15;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.15f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 2.500000000000001;
	s.sharp = 1;
	s.width = -1;
	s.prec = 15;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.15f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 99999.999999;
	s.sharp = 1;
	s.width = -1;
	s.prec = 500;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.500f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);	
	specs_init(&s);
	fl123 = DBL_MIN;
	s.sharp = 1;
	s.width = -1;
	s.prec = 1500;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.1500f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 9.9;
	s.width = 100;
	s.minus = 1;
	s.prec = 0;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%-100.f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 9.9;
	s.plus = 1;
	s.minus = 1;
	s.width = 50;
	s.prec = 10;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%+-50.10f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 9.9;
	s.space = 1;
	s.minus = 1;
	s.width = 50;
	s.prec = 10;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("% -50.10f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = INFINITY;
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 10;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%050.10f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 123.456;
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 10;
	im = print_double(&s, fl123);
	printf("\n");
	ip = printf("%050.10f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	printf("kek\n");
	ld123 = LDBL_MIN;
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 17000;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%050.17000Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = 999999999999 + (-1.0 / 3.0);
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 10;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%050.10Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = -INFINITY;
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 10;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%050.10Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = INFINITY;
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 10;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%050.10Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = -1.0 / 3.0;
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 1000;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%050.1000Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = 2;
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 10;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%050.10Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = 0 / -1.0;
	s.space = 0;
	s.minus = 1;
	s.zero = 0;
	s.width = 50;
	s.prec = 10;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%-50.10Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = -INFINITY / INFINITY; //nan
	s.space = 0;
	s.zero = 1;
	s.width = 50;
	s.prec = 10;
	im = print_long_double(&s, ld123);
	printf("\n");
	ip = printf("%050.10Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = 123.4567895444;
	s.zero = 1;
	im = print_flag_f_l(&s, ld123);
	printf("\n");
	ip = printf("%0Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 123.4567895444;
	s.zero = 1;
	im = print_flag_f(&s, fl123);
	printf("\n");
	ip = printf("%0f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = LDBL_MAX;
	s.zero = 1;
	im = print_flag_f_l(&s, ld123);
	printf("\n");
	ip = printf("%0Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = DBL_MAX;
	s.zero = 1;
	im = print_flag_f(&s, fl123);
	printf("\n");
	ip = printf("%0f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = 5.88e-39;
	s.zero = 1;
	s.prec = 2000;
	im = print_flag_f_l(&s, ld123);
	printf("\n");
	ip = printf("%0.2000Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	ld123 = -5.88e-39;
	s.zero = 1;
	s.prec = 2000;
	im = print_flag_f_l(&s, ld123);
	printf("\n");
	ip = printf("%0.2000Lf", ld123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	specs_init(&s);
	fl123 = 2.22509e-308;
	s.zero = 1;
	s.prec = 500;
	im = print_flag_f(&s, fl123);
	printf("\n");
	ip = printf("%0.500f", fl123);
	printf("\n-----%d-----------%d--------\n", im, ip);
	
//	printf("\nMAX_EXP_D = %d, MIX_EXP_D = %d, MAX_EXP_LD=%d, MIX_EXP_LD%d\n", DBL_MAX_EXP, DBL_MIN_EXP, LDBL_MAX_EXP, LDBL_MIN_EXP);
	return (0);
}
