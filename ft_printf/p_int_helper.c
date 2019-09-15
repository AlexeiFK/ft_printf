/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_int_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:22:04 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/14 22:59:47 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void		strnsetz(char *str, char c, int n, int is_minus)
{
	int		i;

	i = 0;
	if (is_minus == 1)
	{
		str[i] = c;
		n++;
		i++;
	}
	while ((i < n))
	{
		str[i] = '0';
		i++;
	}
}

void		int_prec_set(char **itoa_out, int *n_digits, int prec)
{
	char		*tmp;

	if (*itoa_out[0] != '-')
	{
		tmp = ft_strnew(prec);
		strnsetz(tmp, '-', prec - *n_digits, 0);
		ft_strcat(tmp, *itoa_out);
	}
	else
	{
		tmp = ft_strnew(prec + 1);
		strnsetz(tmp, '-', prec - (*n_digits - 1), 1);
		ft_strcat(tmp, *itoa_out + 1);
	}
	free(*itoa_out);
	*itoa_out = tmp;
	*n_digits = ft_strlen(*itoa_out);
}

static void	append_hex(char **tmp, int *n_digits, t_specs *s)
{
	(*tmp) = ft_strnew(*n_digits + 2);
	(*tmp)[0] = '0';
	if (s->is_upper == 1)
		(*tmp)[1] = 'X';
	else
		(*tmp)[1] = 'x';
	(*n_digits) += 2;
}

void		append_spec_c(char **str, t_specs *s, int *n_digits, int tmp_dig)
{
	char	*tmp;

	tmp = NULL;
	if (s->sharp == 1)
	{
		if (s->base == 16)
		{
			append_hex(&tmp, n_digits, s);
		}
		else if (tmp_dig < s->prec || (*str[0] == '0'))
			return ;
		if (s->base == 8)
		{
			tmp = ft_strnew(*n_digits + 1);
			tmp[0] = '0';
			*n_digits += 1;
		}
		ft_strcat(tmp, *str);
		free(*str);
		*str = tmp;
	}
}
