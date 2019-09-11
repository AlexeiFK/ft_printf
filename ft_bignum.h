/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:22:28 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 22:21:06 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGNUM_H
# define FT_BIGNUM_H
# define MAX_NDIGITS 1100
# define MAX_LNDIGITS 16900
typedef struct				s_bignum
{
	char					*num;
	int						size;
	int						dot;
}							t_bignum;

void	big_num_add_p(t_bignum *b1, t_bignum *b2);
void	get_real_int(t_bignum *res, char *mant, int exp, int norm);
void	get_real_frac(t_bignum *res, char *mant, int exp, int norm);
void	get_real_intl(t_bignum *res, char *mant, int exp, int norm);
void	get_real_fracl(t_bignum *res, char *mant, int exp, int norm);
void	big_num_sqr_p(t_bignum *b1);
void	big_num_two_pow(int power, t_bignum *res);
void	big_num_div_two(t_bignum *b);
void	big_num_zero(t_bignum *b);
void	big_num_zerol(t_bignum *b);
void	big_num_round(t_bignum *b, int prec, t_bignum *more);
void	big_num_round_int(t_bignum *b, t_bignum *fr);
void	big_num_free(t_bignum *b);
void	big_num_bzero(t_bignum *b);
void	str_to_big(char *str, t_bignum *b);
int		big_num_print(t_bignum *b, int prec);
char	*big_to_str_dot(t_bignum *b, int prec);
char	*big_to_str(t_bignum *b, int prec, int dot);
void	str_round(int after, int prec, char *str);
int		is_smth_after(t_bignum *b, int prec);
void	ft_rounding(t_bignum *b, t_bignum *fr, int prec);
void	ft_roundingl(t_bignum *b, t_bignum *fr, int prec);

#endif
