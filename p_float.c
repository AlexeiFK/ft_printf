/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:19:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/04 20:19:08 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

unsigned char reverse_bit(unsigned char mem)
{
	unsigned char	new;

	new = 0;
	new |= mem << 7;
	new |= mem >> 1 << 6;
	new |= mem >> 2 << 5;
	new |= mem >> 3 << 4;
	new |= mem >> 4 << 3;
	new |= mem >> 5 << 2;
	new |= mem >> 6 << 1;
	new |= mem >> 7;
	return (new);
}

void	ft_print_mem(void *mem, int size, int hex_bin)
{
	unsigned char	*str;
//	int		i;
	t_specs s;

	str = (unsigned char*)mem;
	if (hex_bin == 2)
	{
		specs_init(&s);
		s.base = 2;
		size--;
		while (size >= 0)
		{
			print_flag_u_hh(&s, (str[size]));
			ft_putchar('.');
			size--;
		}
	}
	else if (hex_bin == 16)
	{
		specs_init(&s);
		s.base = 16;
		s.sharp = 1;
		size--;
		while (size >= 0)
		{
			print_flag_x_hh(&s, (str[size]));
			s.sharp = 0;
			size--;
		}
	}
}

unsigned char	get_sign(void *mem, int size)
{
	unsigned char	*str;
	unsigned char	bit;

	str = (unsigned char*)mem;
	bit = str[size - 1] >> 7;
	return (bit);
}

unsigned short int		get_exp(void *mem, int size)
{
	unsigned char		*str;
	unsigned short int	exp;
	unsigned short int	tmp;

	str = (unsigned char*)mem;
	exp = 0;
	exp = str[size - 1] & 127;
	tmp = (str[size - 2] >> 4);
	exp = (exp << 4) | tmp;
	return (exp);
}

unsigned long long int	get_mant(void *mem, int size)
{

}

int				print_double(t_specs *s, double f)
{
	long long int	num;
	unsigned long long int d;
	t_float			fbit;
	char	*str;
	t_floatd		fl;
	t_specs		s2;
//	unsigned char	*mem;

	ft_print_mem(&f, sizeof(f), 2);
	ft_putchar('\n');
	ft_print_mem(&f, sizeof(f), 16);
	fl.sign = get_sign(&f, sizeof(f));
	ft_putchar('\n');
	ft_putnbr(fl.sign);
	ft_putchar('\n');
	fl.exp = get_exp(&f, sizeof(f));
	specs_init(&s2);
	s2.base = 2;
	print_flag_u_h(&s2, fl.exp);
//	fbit.f = f;
//	str = ft_itoa_base_u(fbit.d, 2 , 1);
//	ft_putstr(str);
//	d = f_bit.d & 
//	print_flag_x_ll(s, fbit.d << 12 >> 12);
//	write(1, &f, 64);
}

int		print_long_double(t_specs *s, long double f)
{
}
