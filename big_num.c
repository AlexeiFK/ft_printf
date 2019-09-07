/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:16:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/07 22:55:01 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_bignum.h"

void		big_num_add(t_bignum *n1, t_bignum *n2, t_bignum *res)
{
	int		i1;
	int		i2;
	char	carry;

	carry = 0;
	i1 = n1->size;
	i2 = n2->size;
	while (i1 >= 0 && i2 >= 0)
	{
		res->num[i1] = n1->num[i1] + n2->num[i2];
		res->num[i1] += carry;
		carry = 0;
		if (res->num[i1] >= 10)
		{
			carry = res->num[i1] / 10;
			res->num[i1] = res->num[i1] % 10;
		}
		--i1;
		--i2;
	}
}

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
		n1->num[i1] +=  n2->num[i2];
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

/*
 ** calc power in int b4 overflow opti
*/

static void pos_power(int power, t_bignum *res)
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

void		big_num_bzero(t_bignum *b)
{
	ft_memset(b->num, 0, b->size);
}

void		big_num_free(t_bignum *b)
{
	ft_memset(b->num, 0, b->size);
}

void		big_num_zero(t_bignum *b)
{
	b->size = MAX_NDIGITS;
	b->num = ft_strnew(b->size);
	ft_memset(b->num, 0, b->size);
}

void		big_num_print(t_bignum *b, int prec)
{
	int		i;

	i = 0;
	while ((b->num[i] == 0) && (i != b->dot))
		i++;
	while (i < b->size && i <= prec)
	{
		ft_putnbr(b->num[i]);
		i++;
	}
}

void		str_to_big(char *str, t_bignum *b)
{
	int		i;
	int		j;


	i = b->size - 1;
	j = ft_strlen(str) - 1;
	while (i >= 0 && j >= 0)
	{
		b->num[i] = str[j] - '0';
		--i;
		--j;
	}
}
