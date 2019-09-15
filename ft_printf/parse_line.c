/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:17:35 by ccellado          #+#    #+#             */
/*   Updated: 2019/09/14 20:16:57 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char *tmp, int *i, t_specs *s_specs)
{
	if (tmp[*i] == '-')
	{
		s_specs->minus = 1;
		(*i)++;
	}
	if (tmp[*i] == '+')
	{
		s_specs->plus = 1;
		(*i)++;
	}
	if (tmp[*i] == ' ')
	{
		s_specs->space = 1;
		(*i)++;
	}
	if (tmp[*i] == '#')
	{
		s_specs->sharp = 1;
		(*i)++;
	}
	if (tmp[*i] == '0')
	{
		s_specs->zero = 1;
		(*i)++;
	}
}

int		parse_width_prec(char *tmp, int i, t_specs *s_specs)
{
	char	num[MAX_W];
	char	num1[MAX_W];
	int		j;

	j = 0;
	if (tmp[i] != '.')
	{
		while (ft_isdigit(tmp[i]))
			num[j++] = tmp[i++];
		num[j] = '\0';
		s_specs->width = ft_atoll(num);
	}
	j = 0;
	if (tmp[i] == '.')
	{
		i++;
		while (ft_isdigit(tmp[i]))
			num1[j++] = tmp[i++];
		num1[j] = '\0';
		s_specs->prec = ft_atoll(num1);
	}
	return (i);
}

int		parse_size_l(char *tmp, int i, t_specs *s_specs)
{
	if (tmp[i] == 'l')
	{
		if (tmp[i + 1] == 'l')
		{
			s_specs->size = SIZE_LL;
			i += 2;
		}
		else
		{
			s_specs->size = SIZE_L;
			i++;
		}
	}
	else if (tmp[i] == 'L')
	{
		s_specs->size = SIZE_FL;
		i++;
	}
	return (i);
}

int		parse_size_h(char *tmp, int i, t_specs *s_specs)
{
	if (tmp[i] == 'h')
	{
		if (tmp[i + 1] == 'h')
		{
			s_specs->size = SIZE_HH;
			i += 2;
		}
		else
		{
			s_specs->size = SIZE_H;
			i++;
		}
	}
	return (i);
}

int		parse_all(const char *place, t_specs *s_specs)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tmp = (char*)place;
	while (is_flag(tmp[i]))
		parse_flags(tmp, &i, s_specs);
	i = parse_width_prec(tmp, i, s_specs);
	i = parse_size_l(tmp, i, s_specs);
	i = parse_size_h(tmp, i, s_specs);
	s_specs->type = tmp[i];
	return (i);
}
