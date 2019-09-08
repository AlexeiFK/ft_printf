/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:19:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/08 23:25:14 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "ft_bignum.h"

void	get_sign_mant_exp(t_floatd *fn, double f)
{
	fn->sign = get_sign(&f, sizeof(f));
	fn->manti = get_mant(&f, sizeof(f));
	fn->exp = get_exp(&f, sizeof(f));
	if (fn->exp == 0)
		fn->is_norm = 0;
	else
		fn->is_norm = 1;
}

int		print_double_special(t_floatd *fn, t_specs *s)
{
	if (fn->exp == 0x7ff)
	{
		s->prec = -1;
		if (fn->manti == 0)
		{
			if (fn->sign == 1)
				return (print_flag_s(s, "-inf"));
			else
				return (print_flag_s(s, "inf"));
		}
		else
			return (print_flag_s(s, "nan"));
	}
	return (0);
}

int		print_float_sign(int sign, t_specs *s)
{
	if (sign == 1)
	{
		ft_putchar_fd('-', s->fd);
		return (1);
	}
	return (0);
}

int		print_float_dot(t_specs	*s)
{
	if (s->prec > 0)
		ft_putchar_fd('.', s->fd);
	return (1);
}

/*
 ** add to lib
*/ 

char	*ft_dtoa_special(t_floatd *fn)
{
	if (fn->exp == 0x7ff)
	{
		if (fn->manti == 0)
		{
			if (fn->sign == 1)
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("inf"));
		}
		else
			return (ft_strdup("nan"));
	}
	return (NULL);
}

char	*ft_dtoa(double f, int prec)
{
	t_bignum				be_dot;
	t_bignum				af_dot;
	t_floatd				fn;
	char					*mant;
	char					*str1;
	char					*str2;
	char					*str3;

	big_num_zero(&be_dot);
	big_num_zero(&af_dot);
	get_sign_mant_exp(&fn, f);
	if ((str1 = ft_dtoa_special(&fn)) != NULL)
		return (str1);
//	printed += print_float_sign(fn.sign, s);
	mant = ft_itoa_base_u_zero(fn.manti, 2, 1, 51);
	get_real_int(&af_dot, mant, fn.exp, fn.is_norm);
	get_real_frac(&be_dot, mant, fn.exp, fn.is_norm);
//	printed += big_num_print(&af_dot, af_dot.size);
//	printed += print_float_dot(s);
//	printed += big_num_print(&be_dot, s->prec);
	af_dot.dot = af_dot.size;
	if (prec > 0)
		str1 = big_to_str(&af_dot, af_dot.size, 1);
	else
		str1 = big_to_str(&af_dot, af_dot.size, 0);
	str2 = big_to_str(&be_dot, prec, 0);
	str3 = ft_strjoin(str1, str2);
//	printf("\nstr1:%s\nstr2:%s\nstrjoin:%s\n", str1, str2, str3);
	big_num_free(&af_dot);
	big_num_free(&be_dot);
	free(mant);
	return (str3);
}

int		print_double(t_specs *s, double f)
{
	t_bignum				be_dot;
	t_bignum				af_dot;
	t_floatd				fn;
	char					*mant;
	char					*str1;
	char					*str2;
	char					*str3;
	int						printed;

	big_num_zero(&be_dot);
	big_num_zero(&af_dot);
	str3 = ft_dtoa(f, s->prec);
	printf("\nstrdtoa:%s\n", str3);
	get_sign_mant_exp(&fn, f);
	if ((printed = print_double_special(&fn, s)) != 0)
		return (printed);
	printed += print_float_sign(fn.sign, s);
	mant = ft_itoa_base_u_zero(fn.manti, 2, 1, 51);
	get_real_int(&af_dot, mant, fn.exp, fn.is_norm);
	get_real_frac(&be_dot, mant, fn.exp, fn.is_norm);
	printed += big_num_print(&af_dot, af_dot.size);
	printed += print_float_dot(s);
	printed += big_num_print(&be_dot, s->prec);
	af_dot.dot = af_dot.size;
	if (s->prec > 0)
		str1 = big_to_str(&af_dot, af_dot.size, 1);
	else
		str1 = big_to_str(&af_dot, af_dot.size, 0);
//	str2 = big_to_str(&be_dot, s->prec, 0);
//	str3 = ft_strjoin(str1, str2);
//	printf("\nstr1:%s\nstr2:%s\nstrjoin:%s\n", str1, str2, str3);
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
