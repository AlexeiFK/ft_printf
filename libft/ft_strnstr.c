/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:38:41 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/28 18:39:25 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	pos;
	int				i;
	int				j;

	if (needle[0] == '\0')
		return ((char *)(haystack));
	pos = 0;
	j = len;
	while (haystack[pos] != '\0' && j)
	{
		j = len;
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i])
			{
				i++;
			}
			if (needle[i] == '\0' && ((pos + i) <= len))
				return ((char *)(&haystack[pos]));
		}
		pos++;
	}
	return (NULL);
}
