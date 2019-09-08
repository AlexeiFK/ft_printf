/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:52:16 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/08 19:32:58 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

char		*ft_itoa_base_u_zero(unsigned long long int n,
		int base, int is_upper_case, int zeros)
{
	int							len;
	char						*new;

	len = zeros;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	while (len >= 0)
	{
		new[len] = '0' + (n % base);
		if (new[len] > '9' && is_upper_case == 0)
			new[len] += 39;
		else if (new[len] > '9' && is_upper_case == 1)
			new[len] += 7;
		n = n / base;
		len--;
	}
	return (new);
}

unsigned char	get_sign(void *mem, int size)
{
	unsigned char	*str;
	unsigned char	bit;

	str = (unsigned char*)mem;
	bit = str[size - 1] >> 7;
	return (bit);
}

signed short int		get_exp(void *mem, int size)
{
	unsigned char		*str;
	unsigned short int	exp;
	unsigned short int	tmp;

	str = (unsigned char*)mem;
	exp = 0;
	exp = str[size - 1] & 127;
	tmp = (str[size - 2] >> 4);
	exp = (exp << 4) | tmp;
	return (exp);
}

unsigned long long int	get_mant(void *mem, int size)
{
	unsigned char			*str;
	int						i;
	unsigned long long int	mant;
	unsigned long long int	tmp[7];
	t_specs					s;

	i = 0;
	mant = 0;
	str = (unsigned char*)mem;
	specs_init(&s);
	s.base = 2;
	size -= 2;
	while (size >= 0)
	{
		if (i == 0)
			tmp[i] = str[size] & 15;
		else
			tmp[i] = str[size];
		size--;
		i++;
	}
	mant = (tmp[6]) | (tmp[5] << 8) | (tmp[4] << 16)
		| (tmp[3] << 24) | (tmp[2] << 32) | (tmp[1] << 40) | (tmp[0] << 48);
	return (mant);
}

