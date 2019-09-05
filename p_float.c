/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:19:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/05 22:52:20 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_bignum.h"

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

signed short int		get_exp(void *mem, int size)
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
	unsigned char			*str;
	int						i;
	unsigned long long int	mant;
	unsigned long long int	tmp[7];
	t_specs					s;

	i = 0;
	mant = 0;
	str = (unsigned char*)mem;
	specs_init(&s);
	s.base = 2;
	size -= 2;
//	ft_putchar('\n');
	while (size >= 0)
	{
//		print_flag_u_hh(&s, (str[size]));
		if (i == 0)
			tmp[i] = str[size] & 15;
		else
			tmp[i] = str[size];
	//	ft_putstr("i=");
	//	ft_putnbr(i);
	//	ft_putstr("|");
//		print_flag_u_ll(&s, tmp[i]);
//		ft_putchar('o');
		size--;
		i++;
	}
	mant = (tmp[6]) | (tmp[5] << 8) | (tmp[4] << 16)
		| (tmp[3] << 24) | (tmp[2] << 32) | (tmp[1] << 40) | (tmp[0] << 48);
	return (mant);
}

void			apply_exp(unsigned long long int mant,
				unsigned long long int *m_int,
				unsigned long long int *m_fra,
				signed short int exp)
{
	t_specs					s;
	unsigned long long int one;
	unsigned long long int mask;

	mask = 0x000fffffffffffff;
//	mask = 0xfff0000000000000;
//	mask = ~mask;
	one = 1;
	specs_init(&s);
	s.base = 2;
	mant = mant | (one << 52);
	*m_int = mant >> (52 - exp);
	*m_fra = mant << (1 + exp);
	*m_fra = *m_fra & mask;
// 	*m_fra = *m_fra >> (1 + exp);
//	ft_putstr("\nmask\n");
//	print_flag_u_ll(&s, mask);
//	ft_putstr("\nmask\n");
//	print_flag_u_ll(&s, mant);
}

int				print_double(t_specs *s, double f)
{
	long long int	num;
	unsigned long long int d;
	t_float			fbit;
	char	*str;
	t_floatd		fl;
	int				nnn;
	t_specs		s2;
//	unsigned char	*mem;

//	ft_print_mem(&f, sizeof(f), 2);
	ft_putchar('\n');
//	ft_print_mem(&f, sizeof(f), 16);
	fl.sign = get_sign(&f, sizeof(f));
	ft_putchar('\n');
	ft_putstr("\n==========================================\n");
	ft_putchar('\n');
	ft_putnbr(fl.sign);
	ft_putchar('\n');
	fl.exp = get_exp(&f, sizeof(f));
	specs_init(&s2);
	s2.base = 2;
	s2.width = 11;
	s2.zero = 1;
	print_flag_u_h(&s2, fl.exp);
	fl.mant = get_mant(&f, sizeof(f));
	ft_putchar('\n');
//	nnn = print_flag_u_ll(&s2, fl.mant);
//	ft_putstr("\n---------mant----------\n");
	apply_exp(fl.mant, &fl.mant_int, &fl.mant_fra,fl.exp - 1023);
	s2.width = 52;
	print_flag_u_ll(&s2, fl.mant);
//	ft_putstr("\n-\n");
//	ft_putnbr(nnn);
	ft_putstr("\n---------exp:");
	s2.width = -1;
	s2.zero = 0;
	s2.base = 10;
	print_flag_di_h(&s2, fl.exp - 1023);
//	ft_putstr("\n---------mant----------\n");
//	print_flag_u_ll(&s2, fl.mant);
//	ft_putstr("\n---------mant----------\n");
//	apply_exp(fl.mant, &fl.mant_int, &fl.mant_fra,fl.exp - 1023);
//	ft_putstr("\n---------final res----------\n");
	s2.base = 2;
//	ft_putstr("\n---------mantd----------\n");
//	print_flag_u_ll(&s2, fl.mant_int);
//	ft_putstr("\n---------mantf----------\n");
//	print_flag_u_ll(&s2, fl.mant_fra);
	s2.base = 10;
//	ft_putstr("\n---------mantd----------\n");
//	print_flag_u_ll(&s2, fl.mant_int);
//	ft_putstr("\n---------mantf----------\n");
//	print_flag_u_ll(&s2, fl.mant_fra);
//	fbit.f = f;
//	str = ft_itoa_base_u(fbit.d, 2 , 1);
//	ft_putstr(str);
//	d = f_bit.d & 
//	print_flag_x_ll(s, fbit.d << 12 >> 12);
//	write(1, &f, 64);
	ft_putchar('\n');
	t_bignum sbig1, sbig2, res;
	big_num_zero(&sbig1);
	str_to_big("123456789", &sbig1);
	big_num_print(&sbig1);
	ft_putchar('\n');
	big_num_zero(&sbig2);
	str_to_big("123456789", &sbig2);
	big_num_print(&sbig2);
	ft_putchar('\n');
	big_num_zero(&res);
	str_to_big("248328427348", &res);
	big_num_zero(&res);
//	big_num_add(&sbig1, &sbig2, &res);
	big_num_div_two(&sbig1);
	big_num_two_pow(102, &res);
//	big_num_sqr_p(&sbig1);
//	big_num_print(&sbig1);
	big_num_print(&res);
//	big_num_init("123456789", 100);

//	ft_putstr("\n");
//	ft_putstr(sbig);
//	ft_putstr("\n==========================================\n");
	return (0);
}

int		print_long_double(t_specs *s, long double f)
{
	return (0);
}
