/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:19:29 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/13 15:46:35 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bignum.h"

void		ft_roundingl(t_bignum *in, t_bignum *fr, int prec)
{
	if (prec > MAX_LNDIGITS)
		prec = MAX_LNDIGITS;
	if (prec > 0)
		big_num_round(fr, prec, in);
	else
		big_num_round_int(in, fr);
}

static int	hidden_bit_int(int is_norm, int *exp, t_bignum *tmp, t_bignum *res)
{
	if (is_norm == 1 && ((*exp) >= 0))
	{
		big_num_two_pow(*exp, tmp);
		big_num_add_p(res, tmp);
		big_num_div_two(tmp);
		(*exp)--;
		return (1);
	}
	return (0);
}

void		get_real_intl_o(t_bignum *res, char *mant, int exp, int is_norm)
{
	int			i;
	t_bignum	tmp;
	int			flag;

	big_num_zerol(&tmp);
	exp -= 16383;
	i = 0;
	flag = 0;
	flag = hidden_bit_int(is_norm, &exp, &tmp, res);
	while (mant[i] != '\0' && exp >= 0)
	{
		if (mant[i] == '1' && flag == 1)
			big_num_add_p(res, &tmp);
		else if (mant[i] == '1' && flag == 0)
		{
			big_num_two_pow(exp, &tmp);
			big_num_add_p(res, &tmp);
			flag = 1;
		}
		big_num_div_two(&tmp);
		exp--;
		i++;
	}
	big_num_free(&tmp);
}

static int	hidden_bit(int is_norm, int *exp, t_bignum *tmp, t_bignum *res)
{
	if (is_norm == 1 && ((*exp) < 0))
	{
		big_num_two_pow(*exp, tmp);
		big_num_add_p(res, tmp);
		big_num_div_two(tmp);
		(*exp) -= is_norm;
		return (1);
	}
	(*exp) -= is_norm;
	return (0);
}

void		get_real_fracl_o(t_bignum *res, char *mant, int exp, int is_norm)
{
	int			i;
	t_bignum	tmp;
	int			flag;

	big_num_zerol(&tmp);
	exp -= 16383;
	i = 0;
	flag = 0;
	flag = hidden_bit(is_norm, &exp, &tmp, res);
	while (mant[i] != '\0')
	{
		if (mant[i] == '1' && exp < 0 && flag == 1)
			big_num_add_p(res, &tmp);
		else if (mant[i] == '1' && exp < 0 && flag == 0)
		{
			big_num_two_pow(exp, &tmp);
			big_num_add_p(res, &tmp);
			flag = 1;
		}
		big_num_div_two(&tmp);
		exp--;
		i++;
	}
	big_num_free(&tmp);
	res->dot = 1;
}
