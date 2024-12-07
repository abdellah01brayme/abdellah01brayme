#include "libft_printf.h"

int	ft_put_nbrbase(size_t nbr, int base, char x)
{
	char	*str;
	char	tab[21];
	int		i;
	int		count;

	i = 0;
	if (x == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	while (nbr)
	{
		tab[i++] = str[nbr % base];
		nbr /= base;
	}
	count = i;
	while (i-- > 0)
		write (1, &tab[i], 1);
	return (count);
}


int	count_digit(size_t nbr, int base)
{
	int	i;

	i = 0;
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}


int	put_flags(char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write (1, &c, 1);
		i++;
	}
	return (i);
}

int	treat_flags(int nbr, int n_digit, flags flag, int len)
{
	int	count;
	int	space;
	int	zero;

	if (!flag.n_space && flag.n_zero && !nbr)
		zero = 1;
	else if (flag.n_zero > n_digit)
		zero = flag.n_zero;
	else
		zero = n_digit;
	if (flag.n_space <= 0 && !nbr)
		space = 0;
	else
		space = flag.n_space;
	count = put_flags(' ', space - zero - len);
	if (flag.c_flag)
		count += write (1, &flag.c_flag, 1);
	count += put_flags('0', zero - n_digit);
	return (count);
}

int	ft_putnbr(int nbr, flags flag)
{
	unsigned int	n;
	int				i;
	int				n_digit;

	i = 0;
	n = nbr;
	if (nbr < 0)
	{
		n = -nbr;
		flag.c_flag = '-';
		i++;
	}
	if (flag.c_flag && nbr >= 0)
		i++;
	n_digit = count_digit(n, 10);
	i = treat_flags(nbr, n_digit, flag, i);
	i += ft_put_nbrbase(n, 10, flag.c_flag);
	return (i);
}
