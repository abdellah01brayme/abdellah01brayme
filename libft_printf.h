
#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct flags
{
	int		n_space;
	int		n_zero;
	char	c_flag;
}	flags;

int	ft_printf(const char *format, ...);
int	ft_putnbr(int nbr, flags flag);
int	ft_putchar(char c, flags flag);
int	ft_putstr(char *str, flags flag);

#endif