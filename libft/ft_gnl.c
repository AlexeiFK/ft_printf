/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 07:59:55 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/30 21:05:46 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char		*ft_strjoinfr(char **s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	if (!(*s1) || !s2)
		return (NULL);
	new = ft_strnew(ft_strlen(*s1) + ft_strlen(s2));
	if (new == NULL)
		return (NULL);
	while ((*s1)[i])
	{
		new[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	free(*s1);
	return (new);
}

static int		new_line_search(char *buffer, char **before, char **after)
{
	int		i;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
			return (0);
		i++;
	}
	if (!(*before = ft_strsub(buffer, 0, i)))
		return (-1);
	if (!(*after = ft_strsub(buffer, i + 1, (ft_strlen(buffer) - (i + 1)))))
		return (-1);
	free(buffer);
	return (1);
}

static int		gnl_reader(const int fd, char **line, char **content)
{
	int		num;
	int		test;
	char	*buffer;
	char	*before;

	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((num = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[num] = '\0';
		if ((test = new_line_search(buffer, &before, content)) == 1)
		{
			if (!(*line = ft_strjoinfr(line, before)))
				return (-1);
			free(before);
			return (1);
		}
		if (test == 0)
			if (!(*line = ft_strjoinfr(line, buffer)))
				return (-1);
		if (test == -1)
			return (-1);
	}
	free(buffer);
	return (num);
}

int				free_gnl(int flag, char *content)
{
	if (flag)
	{
		if (content)
			free(content);
		return (1);
	}
	return (0);
}

int				ft_gnl(const int fd, char **line, int flag)
{
	static char			*content = NULL;
	int					num;

	if (free_gnl(flag, content))
		return (0);
	if (!line || fd < 0)
		return (-1);
	if (!content)
		content = ft_strnew(BUFF_SIZE);
	if ((num = new_line_search(content, line, &content)) == 1)
		return (1);
	if (num == -1)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	ft_strcpy(*line, content);
	free(content);
	content = NULL;
	num = gnl_reader(fd, line, &content);
	if (num == 0 && *line[0] != '\0')
		return (1);
	if (num == 0)
		return (0);
	if (num == -1)
		return (-1);
	return (1);
}
