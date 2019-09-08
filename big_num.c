/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:16:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/08 23:06:36 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_bignum.h"

/*
 ** calc power in int b4 overflow opti
*/

void		big_num_bzero(t_bignum *b)
{
	ft_memset(b->num, 0, b->size);
}

void		big_num_free(t_bignum *b)
{
	free(b->num);
}

void		big_num_zero(t_bignum *b)
{
	b->size = MAX_NDIGITS;
	b->num = ft_strnew(b->size);
	ft_memset(b->num, 0, b->size);
}

int			big_num_print(t_bignum *b, int prec)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while ((b->num[i] == 0) && (i != b->dot))
		i++;
	while (i <= b->size && i <= prec)
	{
		ft_putnbr(b->num[i]);
		i++;
		p++;
	}
	return (p);
}

void		str_to_big(char *str, t_bignum *b)
{
	int		i;
	int		j;

	i = b->size;
	j = ft_strlen(str) - 1;
	while (i >= 0 && j >= 0)
	{
		b->num[i] = str[j] - '0';
		--i;
		--j;
	}
}

char		*big_to_str(t_bignum *b, int prec, int dot)
{
	int		i;
	int		start;
	char	*new;
	int		len;

	i = 0;
	while ((b->num[i] == 0) && (i != b->dot))
		i++;
	start = i;
	while (i <= b->size && i <= prec)
	{
		b->num[i] += '0';
		i++;
	}
	b->num[i] = '\0';
	len = ft_strlen(b->num + start) + 1;
	new = ft_strnew(len);
	ft_strcpy(new, b->num + start);
	if (dot == 1)
	{
		new[len - 1] = '.';
		new[len] = '\0';
	}
//	new = ft_strdup(b->num + start);
	return (new);
}
