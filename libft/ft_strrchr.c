/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:47:59 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/24 21:57:18 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != c)
	{
		if (s[i] == s[0])
			return (NULL);
		i--;
	}
	return ((char *)(&s[i]));
}
