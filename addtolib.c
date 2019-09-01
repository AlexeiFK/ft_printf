/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtolib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:49:27 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/01 22:18:56 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_putnstr_fd(char const *s, int fd, int n)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (*s && i < n)
	{
		ft_putchar_fd(*s, fd);
		s++;
		i++;
	}
}

static int	ft_numl(long long int n, int base)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

static int	ft_numl_u(unsigned long long int n, int base)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char		*ft_itoa_base(long long int n, int base, int is_upper_case)
{
	int							len;
	long long int				tmp;
	char						*new;
	unsigned long long int		num;

	len = ft_numl(n, base) - 1;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	tmp = n;
	if (n < 0)
		n = n * -1;
	num = n;
	while (len >= 0)
	{
		new[len] = '0' + (num % base);
		if (new[len] > '9' && is_upper_case == 0)
			new[len] += 39;
		else if (new[len] > '9' && is_upper_case == 1)
			new[len] += 7;
		num = num / base;
		len--;
	}
	if (tmp < 0)
		new[0] = '-';
	return (new);
}

char		*ft_itoa_base_u(unsigned long long int n, int base, int is_upper_case)
{
	int							len;
	char						*new;

	len = ft_numl_u(n, base) - 1;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	while (len >= 0)
	{
		new[len] = '0' + (n % base);
		if (new[len] > '9' && is_upper_case == 0)
			new[len] += 39;
		else if (new[len] > '9' && is_upper_case == 1)
			new[len] += 7;
		n = n / base;
		len--;
	}
	return (new);
}
