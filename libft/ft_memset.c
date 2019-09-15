/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:03:55 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/25 21:28:26 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*str;
	int		nb;

	nb = len;
	str = (char*)b;
	i = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
