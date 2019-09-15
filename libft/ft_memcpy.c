/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:31:33 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/25 21:54:27 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	int		nb;
	char	*dest;
	char	*sorc;

	dest = (char*)dst;
	sorc = (char*)src;
	i = 0;
	nb = n;
	while (i < nb)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}
