
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct			s_specs
{
	int			flag;
	int			width;
	int			prec;
	int			size;
	int			type;
	int			base;
	int			fd;
}				t_specs;

void	print_char(t_specs *s, int c);
void	print_int(t_specs *s, int c);


/*
 ** functions todo
*/

char *itoa_base_put_nbr_base();

void put_nbr_unsigned;


#endif
