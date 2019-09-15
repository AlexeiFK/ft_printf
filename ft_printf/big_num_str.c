/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:53:11 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 21:53:30 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_bignum.h"

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

char		*big_to_str_dot(t_bignum *b, int prec)
{
	if (prec > 0)
		return (big_to_str(b, b->size, 1));
	else
		return (big_to_str(b, b->size, 0));
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
	return (new);
}
