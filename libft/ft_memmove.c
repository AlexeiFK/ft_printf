/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:57:57 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/25 22:39:11 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sorc;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
	{
		dest = (char*)dst;
		sorc = (char*)src;
		while (len--)
		{
			dest[len] = sorc[len];
		}
	}
	return (dst);
}
