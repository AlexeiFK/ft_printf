/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:48:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/09 23:44:42 by rjeor-mo         ###   ########.fr       */
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

void		extra_round_prikol(t_bignum *b)
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

void		big_num_round(t_bignum *b, int prec, t_bignum *more)
{
	int		i;
	char	carry;

	carry = 0;
	i = prec;
	if (is_smth_after(b, prec + 1) == 0)
	{
		if (b->num[i + 1] >= 5 && (b->num[i] % 2 != 0))
			b->num[i]++;
	}
	else
	{
		if (b->num[i + 1] >= 5)
			b->num[i]++;
	}
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
		extra_round_prikol(more);
}

int			get_last_num(t_bignum *b)
{
	return (b->num[b->size]); // 0.[0]00000000043 change it
}

void		big_num_round_int(t_bignum *b, t_bignum *fr)
{
	int		i;
	int		carry;

	if (get_last_num)
}

void		str_round(int is_after, int prec, char *str)
{
	int		len;
	int		i;
	int		carry;

	i = 0;
	if (prec > 0)
	{
		while (str[i] != '.')
			i++;
		printf("\nstr=%s\nprec=%d\n", &str[i], prec);
	}
	else
		return ;
	i += prec;
	len = ft_strlen(str);
	carry = 0;
	if (is_after == 1)
	{
		if (str[i + 1] >= '5' && (str[i] % 2 != 0))
			str[i]++;
	}
	else
	{
		if (str[i + 1] >= '5')
			str[i]++;
	}
	if (str[i] > '9')
	{
		carry = str[i] / 10;
		str[i] %= 10;
	}
	printf("\nstr=%s\nprec=%d\nisafter%d\n", &str[i], prec, is_after);
	while (i >= 0)
	{
		if (str[i] == '.')
		{
			--i;
			continue ;
		}
		str[i] += carry;
		carry = 0;
		if (str[i] > '9')
		{
			carry = str[i] / 10;
			str[i] %= 10;
		}
		--i;
	}
}












