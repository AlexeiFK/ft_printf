/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:03:11 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 22:04:13 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bignum.h"

void	ft_rounding(t_bignum *in, t_bignum *fr, int prec)
{
	if (prec > MAX_NDIGITS)
		prec = MAX_NDIGITS;
	if (prec > 0)
		big_num_round(fr, prec, in);
	else
		big_num_round_int(in, fr);
}
