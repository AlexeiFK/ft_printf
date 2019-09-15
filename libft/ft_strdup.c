/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:48:25 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/24 19:01:16 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*new;

	len = ft_strlen(s1);
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}
