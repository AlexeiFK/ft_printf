/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 04:34:08 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/26 06:09:03 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start,
		size_t len)
{
	int		i;
	int		j;
	int		ilen;
	char	*new;

	ilen = len;
	if (!s)
		return (NULL);
	i = start;
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	j = 0;
	while (s[i] && (j < ilen))
	{
		new[j] = s[i];
		j++;
		i++;
	}
	return (new);
}
