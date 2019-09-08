/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:29:18 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/08 19:39:55 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bignum.h"

static void	pos_power(int power, t_bignum *res)
{
	int		i;

	i = 1;
	if (power == 0)
	{
		str_to_big("1", res);
		return ;
	}
	str_to_big("2", res);
	res->dot = res->size;
	while (i < power)
	{
		big_num_sqr_p(res);
		i++;
	}
}

static void	neg_power(int power, t_bignum *res)
{
	int		i;

	i = 0;
	res->num[0] = 1;
	while (i < power)
	{
		big_num_div_two(res);
		i++;
	}
}

void		big_num_two_pow(int power, t_bignum *res)
{
	if (power < 0)
		neg_power(-power, res);
	else
		pos_power(power, res);
}
