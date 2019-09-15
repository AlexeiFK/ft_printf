/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 07:42:33 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/28 13:07:27 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_numl(int n)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*new;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numl(n);
	if (!(new = ft_strnew(len)))
		return (NULL);
	len--;
	tmp = n;
	if (n < 0)
		n = n * -1;
	while (len >= 0)
	{
		new[len] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	if (tmp < 0)
		new[0] = '-';
	return (new);
}
