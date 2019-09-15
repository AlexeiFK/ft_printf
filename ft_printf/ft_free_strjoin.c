/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:12:38 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 22:13:13 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_free_strjoin(char *str1, char *str2)
{
	char	*new;

	new = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (new);
}
