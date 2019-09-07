/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:52:16 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/07 20:58:53 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
