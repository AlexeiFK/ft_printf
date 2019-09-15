/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:08:43 by rjeor-mo          #+#    #+#             */
/*   Updated: 2018/11/24 19:17:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == '2')
		return (1);
	else if (c == '3')
		return (1);
	else if (c == '4')
		return (1);
	else if (c == '5')
		return (1);
	else if (c == '6')
		return (1);
	else if (c == '7')
		return (1);
	else if (c == '8')
		return (1);
	else if (c == '9')
		return (1);
	else
		return (0);
}
