/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:31 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/09/01 22:57:23 by rjeor-mo         ###   ########.fr       */
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
	int			size;
	int			type;
	int			is_upper;
	int			base;
	int			fd;
}				t_specs;



void	put_empty_symbols(unsigned char c, int n, int fd);

void	print_string(t_specs *s, char *str);
void	print_char(t_specs *s, unsigned char c);
void	print_int(t_specs *s, long long int c);
void	print_uint(t_specs *s, unsigned long long int c);

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

#endif
