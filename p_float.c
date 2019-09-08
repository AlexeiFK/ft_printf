/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:19:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/08 19:42:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "ft_bignum.h"

int		print_double(t_specs *s, double f)
{
	t_bignum				be_dot;
	t_bignum				af_dot;
	int						exp;
	unsigned long long int	manti;
	char					sign;
	int						is_norm;
	char					*mant;
	int						printed;

	printed = 0;
	is_norm = 1;
	big_num_zero(&be_dot);
	big_num_zero(&af_dot);
	sign = get_sign(&f, sizeof(f));
	manti = get_mant(&f, sizeof(f));
	exp = get_exp(&f, sizeof(f));
	if ((exp == 0x7ff) && (manti == 0))
	{
		if (sign == 1)
		{
			return (print_flag_s(s, "-inf"));
		}
		else if (sign == 0)
		{
			return (print_flag_s(s, "inf"));
		}
	}
	if (sign == 1)
	{
		ft_putchar_fd('-', s->fd);
		printed++;
	}
	mant = ft_itoa_base_u_zero(manti, 2, 1, 51);
	af_dot.dot = 1;
	if (exp == 0)
	{
		ft_putstr("sub\n");
		is_norm = 0;
	}
	get_real_int(&af_dot, mant, exp, is_norm);
	get_real_frac(&be_dot, mant, exp, is_norm);
	big_num_print(&af_dot, s->prec);
	ft_putchar_fd('.', s->fd);
	big_num_print(&be_dot, s->prec);
	big_num_free(&af_dot);
	big_num_free(&be_dot);
	free(mant);
	return (printed);
}

void	get_real_int(t_bignum *res, char *mant, int exp, int is_norm)
{
	int			i;
	t_bignum	tmp;

	big_num_zero(&tmp);
	exp -= 1023;
	i = 0;
	if (is_norm == 1 && exp >= 0)
	{
		big_num_two_pow(exp, &tmp);
		big_num_add_p(res, &tmp);
		exp--;
	}
	while (mant[i] != '\0' && exp >= 0)
	{
		if (mant[i] == '1')
		{
			big_num_bzero(&tmp);
			big_num_two_pow(exp, &tmp);
			big_num_add_p(res, &tmp);
		}
		exp--;
		i++;
	}
	big_num_free(&tmp);
	res->dot = res->size;
}

void	get_real_frac(t_bignum *res, char *mant, int exp, int is_norm)
{
	int			i;
	t_bignum	tmp;

	big_num_zero(&tmp);
	exp -= 1023;
	i = 0;
	if (is_norm == 1 && exp < 0)
	{
		big_num_two_pow(exp, &tmp);
		big_num_add_p(res, &tmp);
	}
	exp -= is_norm;
	while (mant[i] != '\0')
	{
		if (mant[i] == '1' && exp < 0)
		{
			big_num_bzero(&tmp);
			big_num_two_pow(exp, &tmp);
			big_num_add_p(res, &tmp);
		}
		exp--;
		i++;
	}
	big_num_free(&tmp);
	res->dot = 1;
}
