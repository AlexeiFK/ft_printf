/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:09:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/13 15:43:43 by rjeor-mo         ###   ########.fr       */
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
	get_real_intl_o(&int_frac[0], str[0], fn.exp, fn.is_norm);
	get_real_fracl_o(&int_frac[1], str[0], fn.exp, fn.is_norm);
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
