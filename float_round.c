/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:48:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/10 18:24:14 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_bignum.h"

int			is_smth_after(t_bignum *b, int prec)
{
	int		i;
	int		ret;

	i = prec;
	while (i <= b->size)
	{
		if (b->num[i] != 0)
			return (1);
		++i;
	}
	return (0);
}

void		extra_round(t_bignum *b)
{
	int	i;
	int	carry;

	carry = 1;
	i = b->size;
	while (i >= 0)
	{
		b->num[i] += carry;
		carry = 0;
		if (b->num[i] >= 10)
		{
			carry = b->num[i] / 10;
			b->num[i] %= 10;
		}
		--i;
	}
}

void		bank_round(char *n1, int n2, int is_after)
{
	if (is_after == 0)
	{
		if (n2 >= 5 && ((*n1) % 2 != 0))
			(*n1)++;
	}
	else
	{
		if (n2 >= 5)
			(*n1)++;
	}
}

void		big_num_round(t_bignum *b, int prec, t_bignum *more)
{
	int		i;
	char	carry;

	carry = 0;
	i = prec;
	bank_round(&b->num[i], b->num[i + 1], is_smth_after(b, prec + 1));
	while (i >= b->dot)
	{
		b->num[i] += carry;
		carry = 0;
		if (b->num[i] >= 10)
		{
			carry = b->num[i] / 10;
			b->num[i] %= 10;
		}
		--i;
	}
	if (carry != 0)
		extra_round(more);
}

void		big_num_round_int(t_bignum *b, t_bignum *fr)
{
	int		i;
	int		carry;

	i = b->size;
	bank_round(&b->num[i], fr->num[fr->dot], is_smth_after(fr, 2));
	carry = 0;
	while (i >= 0)
	{
		b->num[i] += carry;
		carry = 0;
		if (b->num[i] >= 10)
		{
			carry = b->num[i] / 10;
			b->num[i] %= 10;
		}
		--i;
	}
}
