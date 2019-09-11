/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:37:55 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 21:41:03 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "ft_bignum.h"

void	get_sign_mant_expl(t_floatd *fn, long double f)
{
	fn->sign = get_signl(&f, 10);
	fn->manti = get_mantl(&f, 10);
	fn->exp = get_expl(&f, 10);
	if (fn->exp == 0)
		fn->is_norm = 0;
	else
		fn->is_norm = 1;
}

char	*ft_ldtoa_special(t_floatd *fn)
{
	if (fn->exp == 0x7fff)
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

void	ft_roundingl(t_bignum *in, t_bignum *fr, int prec)
{
	if (prec > MAX_LNDIGITS)
		prec = MAX_LNDIGITS;
	if (prec > 0)
		big_num_round(fr, prec, in);
	else
		big_num_round_int(in, fr);
}

char	*ft_ldtoa(long double f, int prec)
{
	t_bignum				int_frac[2];
	t_floatd				fn;
	char					*str[3];

	get_sign_mant_expl(&fn, f);
	if ((str[1] = ft_ldtoa_special(&fn)) != NULL)
		return (str[1]);
	big_num_zerol(&int_frac[0]);
	big_num_zerol(&int_frac[1]);
	str[0] = ft_itoa_base_u_zero(fn.manti, 2, 1, 62);
	get_real_intl(&int_frac[0], str[0], fn.exp, fn.is_norm);
	get_real_fracl(&int_frac[1], str[0], fn.exp, fn.is_norm);
	free(str[0]);
	int_frac[0].dot = int_frac[0].size;
	ft_roundingl(&int_frac[0], &int_frac[1], prec);
	str[1] = big_to_str_dot(&int_frac[0], prec);
	str[2] = big_to_str(&int_frac[1], prec, 0);
	str[0] = ft_free_strjoin(str[1], str[2]);
	big_num_free(&int_frac[0]);
	big_num_free(&int_frac[1]);
	return (str[0]);
}

int		print_long_double(t_specs *s, long double f)
{
	int						printed;
	int						n_digits;
	char					empty;
	char					*dtoa_out;
	int						sign;

	printed = 0;
	dtoa_out = ft_ldtoa(f, s->prec);
	n_digits = ft_strlen(dtoa_out);
	empty = choose_empty_symbolf(s, dtoa_out);
	sign = get_float_sign(get_signl(&f, 10), s);
	if (s->minus == 0)
		printed += put_empty_symbols(empty, s->width - n_digits - sign, s->fd);
	n_digits += print_float_sign(get_signl(&f, 10), s);
	ft_putstr_fd(dtoa_out, s->fd);
	printed += put_empty_symbols('0', s->prec - MAX_LNDIGITS, s->fd);
	if (s->minus == 1)
		printed += put_empty_symbols(empty, s->width - n_digits, s->fd);
	free(dtoa_out);
	return (printed + n_digits);
}

void	get_real_intl(t_bignum *res, char *mant, int exp, int is_norm)
{
	int			i;
	t_bignum	tmp;

	big_num_zerol(&tmp);
	exp -= 16383;
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

void	get_real_fracl(t_bignum *res, char *mant, int exp, int is_norm)
{
	int			i;
	t_bignum	tmp;

	big_num_zerol(&tmp);
	exp -= 16383;
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
