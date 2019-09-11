/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:31 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/11 22:26:43 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
 ** minus -- fd = parser's work
 ** you dont have to change is_upper and base
*/
typedef struct			s_specs
{
	char		minus;
	char		plus;
	char		space;
	char		sharp;
	char		zero;
	int			width;
	int			prec;
	int			fd;

	int			is_upper;
	int			base;
}				t_specs;

typedef struct				s_floatd
{
	unsigned char			sign;
	unsigned long long int	manti;
	signed short int		exp;
	int						expl;
	int						is_norm;
}							t_floatd;

/*
 ** add to lib
*/

char	*ft_itoa_base(long long int n, int base, int is_upper_case);
char	*ft_itoa_base_u(unsigned long long int n, int base, int is_upper_case);
void	ft_putnstr_fd(char const *s, int fd, int n);
char	*ft_free_strjoin(char *s1, char *s2);
char	*ft_dtoa(double f, int prec);
char	*ft_ldtoa(long double f, int prec);

/*
 ** additional functions for basic output
*/

char					choose_empty_symbol(t_specs *s);
char					choose_empty_symbolf(t_specs *s, char *dtoa);
int						put_empty_symbols(unsigned char c, int n, int fd);
void					append_spec_c(char **str, t_specs *s, int *n_digs);
void					int_prec_set(char **str, int *n_digs, int prec);
void					print_mem(void *mem, int size);
int						print_float_sign(int sign, t_specs *s);
int						get_float_sign(int sign, t_specs *s);
char					*ft_itoa_base_u_zero(unsigned long long int n,
						int base, int is_upper_case, int zeros);
unsigned char			get_sign(void *mem, int size);
signed short int		get_exp(void *mem, int size);
unsigned long long int	get_mant(void *mem, int size);
signed short int		get_expl(void *mem, int size);
unsigned long long int	get_mantl(void *mem, int size);
unsigned char			get_signl(void *mem, int size);


/*
**	basic output functions
*/

int		print_string(t_specs *s, char *str);
int		print_char(t_specs *s, unsigned char c);
int		print_int(t_specs *s, long long int c);
int		print_uint(t_specs *s, unsigned long long int c);
int		print_double(t_specs *s, double num);
int		print_long_double(t_specs *s, long double num);


/*
 ** interface
*/

void	specs_init(t_specs *s);

int		print_flag_f(t_specs *s, double f);
int		print_flag_f_l(t_specs *s, long double f);

int		print_flag_c(t_specs *s, unsigned char c);
int		print_flag_s(t_specs *s, char *str);
int		print_flag_p(t_specs *s, void *p);

int		print_flag_di(t_specs *s, int num);
int		print_flag_di_l(t_specs *s, long int num);
int		print_flag_di_hh(t_specs *s, signed char num);
int		print_flag_di_h(t_specs *s, short int num);
int		print_flag_di_ll(t_specs *s, long long int num);

int		print_flag_o(t_specs *s, unsigned int num);
int		print_flag_o_l(t_specs *s, unsigned long int num);
int		print_flag_o_hh(t_specs *s, unsigned char num);
int		print_flag_o_h(t_specs *s, unsigned short int num);
int		print_flag_o_ll(t_specs *s, unsigned long long int num);

int		print_flag_u(t_specs *s, unsigned int num);
int		print_flag_u_l(t_specs *s, unsigned long int num);
int		print_flag_u_hh(t_specs *s, unsigned char num);
int		print_flag_u_h(t_specs *s, unsigned short int num);
int		print_flag_u_ll(t_specs *s, unsigned long long int num);

int		print_flag_x_big(t_specs *s, unsigned int num);
int		print_flag_x_big_l(t_specs *s, unsigned long int num);
int		print_flag_x_big_hh(t_specs *s, unsigned char num);
int		print_flag_x_big_h(t_specs *s, unsigned short int num);
int		print_flag_x_big_ll(t_specs *s, unsigned long long int num);

int		print_flag_x(t_specs *s, unsigned int num);
int		print_flag_x_l(t_specs *s, unsigned long int num);
int		print_flag_x_hh(t_specs *s, unsigned char num);
int		print_flag_x_h(t_specs *s, unsigned short int num);
int		print_flag_x_ll(t_specs *s, unsigned long long int num);

#endif
