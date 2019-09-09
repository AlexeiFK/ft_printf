/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:28:39 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/09 21:07:51 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bignum.h"

void		big_num_add_p(t_bignum *n1, t_bignum *n2)
{
	int		i1;
	int		i2;
	char	carry;

	carry = 0;
	i1 = n1->size;
	i2 = n2->size;
	while (i1 >= 0 && i2 >= 0)
	{
		n1->num[i1] += n2->num[i2];
		n1->num[i1] += carry;
		carry = 0;
		if (n1->num[i1] >= 10)
		{
			carry = n1->num[i1] / 10;
			n1->num[i1] %= 10;
		}
		--i1;
		--i2;
	}
}

void		big_num_sqr_p(t_bignum *b)
{
	int		i;
	char	carry;

	carry = 0;
	i = b->size;
	while (i >= 0)
	{
		b->num[i] *= 2;
		b->num[i] += carry;
		carry = 0;
		if (b->num[i] >= 10)
		{
			carry = b->num[i] / 10;
			b->num[i] = b->num[i] % 10;
		}
		--i;
	}
}

void		big_num_div_two(t_bignum *b)
{
	int		i;
	char	to_div;
	char	rem;

	i = 0;
	rem = 0;
	to_div = 0;
	while (b->num[i] == 0)
		i++;
	while (i < b->size)
	{
		to_div = b->num[i] + rem * 10;
		b->num[i] = to_div / 2;
		rem = to_div % 2;
		i++;
	}
}
