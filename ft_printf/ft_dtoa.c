/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:58:53 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 22:04:52 by rjeor-mo         ###   ########.fr       */
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
	ft_rounding(&int_frac[0], &int_frac[1], prec);
	str[1] = big_to_str_dot(&int_frac[0], prec);
	str[2] = big_to_str(&int_frac[1], prec, 0);
	str[0] = ft_free_strjoin(str[1], str[2]);
	big_num_free(&int_frac[0]);
	big_num_free(&int_frac[1]);
	return (str[0]);
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
