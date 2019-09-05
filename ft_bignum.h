/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:22:28 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/05 22:52:52 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGNUM_H
# define FT_BIGNUM_H
# define MAX_NDIGITS 500
typedef struct				s_bignum
{
	char					*num;
	int						size;
	int						dot;
}							t_bignum;

char	*big_num_init(char *str, int size);
void	big_num_sqr(t_bignum *b1, t_bignum *res);
void	big_num_sqr_p(t_bignum *b1);
void	big_num_two_pow(int power, t_bignum *res);
void	big_num_div_two(t_bignum *b);
void	big_num_zero(t_bignum *b);
void	str_to_big(char *str, t_bignum *b);
void	big_num_print(t_bignum *b);
void	big_num_add(t_bignum *b1, t_bignum *b2, t_bignum *res);

#endif
