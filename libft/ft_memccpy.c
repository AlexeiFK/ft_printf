/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:40:32 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/26 01:04:55 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	int				nb;
	unsigned char	*dest;
	unsigned char	*sorc;

	dest = (unsigned char*)dst;
	sorc = (unsigned char*)src;
	i = 0;
	nb = n;
	while ((i < nb) && (sorc[i] != (unsigned char)c))
	{
		dest[i] = sorc[i];
		i++;
	}
	if (i == nb)
		return (NULL);
	else
	{
		dest[i] = sorc[i];
		return ((void*)&dest[i + 1]);
	}
}
