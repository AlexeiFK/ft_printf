/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float_l_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:24:30 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 19:24:27 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

signed short int		get_expl(void *mem, int size)
{
	unsigned char		*str;
	unsigned short int	exp;
	unsigned short int	tmp;
	int					i;

	i = 0;
	str = (unsigned char*)mem;
	exp = 0;
	exp = str[size - 1] & 127;
	tmp = (str[size - 2]);
	exp = (exp << 8)| tmp;
	return (exp);
}

unsigned long long int	get_mantl(void *mem, int size)
{
	unsigned char			*str;
	int						i;
	unsigned long long int	mant;
	unsigned long long int	tmp[8];

	i = 0;
	mant = 0;
	str = (unsigned char*)mem;
	size -= 3;
	while (size >= 0)
	{
		if (i == 0)
			tmp[i] = str[size] & 127;
		else
			tmp[i] = str[size];
		size--;
		i++;
	}
	mant = (tmp[7]) | (tmp[6] << 8) | (tmp[5] << 16) | (tmp[4] << 24)
		| (tmp[3] << 32) | (tmp[2] << 40) | (tmp[1] << 48) | (tmp[0] << 56);
	return (mant);
}

unsigned char			get_signl(void *mem, int size)
{
	unsigned char	*str;
	unsigned char	bit;

	str = (unsigned char*)mem;
	bit = str[size - 1] >> 7;
	return (bit);
}
