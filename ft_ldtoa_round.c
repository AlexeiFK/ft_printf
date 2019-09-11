/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:19:29 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 22:20:34 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bignum.h"

void	ft_roundingl(t_bignum *in, t_bignum *fr, int prec)
{
	if (prec > MAX_LNDIGITS)
		prec = MAX_LNDIGITS;
	if (prec > 0)
		big_num_round(fr, prec, in);
	else
		big_num_round_int(in, fr);
}
