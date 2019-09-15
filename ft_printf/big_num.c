/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:16:07 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 21:53:31 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_bignum.h"

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
	b->num = ft_strnew(b->size + 1);
	ft_memset(b->num, 0, b->size);
}

void		big_num_zerol(t_bignum *b)
{
	b->size = MAX_LNDIGITS;
	b->num = ft_strnew(b->size + 1);
	ft_memset(b->num, 0, b->size);
}
