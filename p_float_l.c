/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:37:55 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/10 19:30:18 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "ft_bignum.h"

char	*ft_ldtoa(double f, int prec)
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

int		print_long_double(t_specs *s, long double f)
{
	int						printed;
	char					*dtoa_out;

	printed = 0;
	printed += print_float_sign(get_sign(&f, sizeof(f)), s);
	dtoa_out = ft_ldtoa(f, s->prec);
	printed += ft_strlen(dtoa_out);
	ft_putstr_fd(dtoa_out, s->fd);
	free(dtoa_out);
	return (printed);
}
