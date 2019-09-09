/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:19:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/09 23:39:49 by rjeor-mo         ###   ########.fr       */
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
				return (ft_strdup("inf"));
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
	t_bignum				int_frac[2];
	t_floatd				fn;
	char					*str[3];

	get_sign_mant_exp(&fn, f);
	if ((str[1] = ft_dtoa_special(&fn)) != NULL)
		return (str[1]);
	big_num_zero(&int_frac[0]);
	big_num_zero(&int_frac[1]);
	str[0] = ft_itoa_base_u_zero(fn.manti, 2, 1, 51);
	get_real_int(&int_frac[0], str[0], fn.exp, fn.is_norm);
	get_real_frac(&int_frac[1], str[0], fn.exp, fn.is_norm);
	free(str[0]);
	int_frac[0].dot = int_frac[0].size;
	if (prec > 0)
	{
		big_num_round(&int_frac[1], prec, &int_frac[0]);
		str[1] = big_to_str(&int_frac[0], int_frac[0].size, 1);
	}
	else
	{
		big_num_round_int(&int_frac[0]);
		str[1] = big_to_str(&int_frac[0], int_frac[0].size, 0);
	}
	str[2] = big_to_str(&int_frac[1], prec, 0);
	str[0] = ft_strjoin(str[1], str[2]);
//	str_round(is_smth_after(&int_frac[1], prec), prec, str[0]);
	free(str[1]);
	free(str[2]);
	big_num_free(&int_frac[0]);
	big_num_free(&int_frac[1]);
	return (str[0]);
}

int		print_double(t_specs *s, double f)
{
	int						printed;
	char					*dtoa_out;

	printed = 0;
	printed += print_float_sign(get_sign(&f, sizeof(f)), s);
	dtoa_out = ft_dtoa(f, s->prec);
	printed += ft_strlen(dtoa_out);
	ft_putstr_fd(dtoa_out, s->fd);
	free(dtoa_out);
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
