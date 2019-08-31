#include "libft.h"
#include "ft_printf.h"


void	print_char(t_specs *s, unsigned char c)
{
	int	i;

	// - flag or no flag
	i = 1;
	while (i < s->width)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(c);
}


void	print_int(t_specs *s, int c)
{
	ft_putnbr(c);
}
