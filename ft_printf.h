/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:31 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/02 22:53:50 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

//	int			size;
//	int			type;
//
	int			is_upper;
	int			base;
}				t_specs;

/*
 ** 	maybe return size_t instead of int
 **		0x in width
 **		add buffer ARGH!
*/
int		put_empty_symbols(unsigned char c, int n, int fd);

int		print_string(t_specs *s, char *str);
int		print_char(t_specs *s, unsigned char c);
int		print_int(t_specs *s, long long int c);
int		print_uint(t_specs *s, unsigned long long int c);

char	*ft_itoa_base(long long int n, int base, int is_upper_case);
char	*ft_itoa_base_u(unsigned long long int n, int base, int is_upper_case);


void	ft_putnstr_fd(char const *s, int fd, int n);

/*
 ** functions todo
*/

void	ft_putunbr_base();
void	put_nbr_unsigned();
int		number_of_digs_decs(int num);
int		number_of_digs_decu(unsigned int num);
int		number_of_digs_hexu(unsigned int num);
int		number_of_digs_octu(unsigned int num);

/*
 ** interface
*/

/*
 ** 	maybe return size_t instead of int
*/
void	specs_init(t_specs *s);

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
