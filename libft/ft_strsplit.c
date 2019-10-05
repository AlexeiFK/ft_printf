/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 05:18:32 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/10/05 17:39:42 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count_w(const char *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i + 1] == c && s[i] != c)
			count++;
		if (s[i + 1] == '\0' && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int		ft_count_l(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void		ft_clear_top(int index, char ***str)
{
	index--;
	while (index >= 0)
	{
		free(*(str + index));
		index--;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = ft_count_w(s, c);
	i = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		while (*s == c && s)
			s++;
		if (!(new[i] = ft_strsub(s, 0, ft_count_l(s, c))))
		{
			ft_clear_top(i, &new);
			free(new);
			return (NULL);
		}
		s = s + ft_count_l(s, c);
		i++;
	}
	new[i] = NULL;
	return (new);
}
