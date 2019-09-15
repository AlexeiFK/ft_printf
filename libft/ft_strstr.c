/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:23:09 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/26 00:24:40 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	pos;
	unsigned int	i;

	if (needle[0] == '\0')
		return ((char *)(haystack));
	pos = 0;
	while (haystack[pos] != '\0')
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)(&haystack[pos]));
		}
		pos++;
	}
	return (NULL);
}
