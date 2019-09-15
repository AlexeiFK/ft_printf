/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:12:30 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 20:14:26 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	int				i;
	int				sign;
	long long		res;

	sign = 1;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' ||
				str[i] == '\r' || str[i] == '\n' ||
				str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * res);
}
