#include "libft_printf.h"

int	put_space(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		i++;
		write (1, " ", 1);
	}
	return (i);
}

int	ft_putchar(char c, flags flag)
{
	int	i;

	if (flag.n_zero >=0 || flag.n_space == 0)
		return (-1);
	i = put_space(flag.n_space - 1);
	i += write (1, &c, 1);
	return (i);
}
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str, flags flag)
{
	int i;
	int	len;

	i = 0;
	if (!flag.n_space)
		return (-1);
	if (!str)
	{
		if (flag.n_zero >= 6 || flag.n_zero == -1)
			return (put_space(flag.n_space - 6) + write (1, "(null)", 6));
		else
			return (put_space (flag.n_space));
	}
	len  = ft_strlen(str);
	if (flag.n_zero < 0)
		flag.n_zero = len;
	if (len > flag.n_zero)
		len = flag.n_zero;
	if (flag.n_space < len)
		flag.n_space = len;
	i += put_space(flag.n_space - len);
	i += write (1, str, len);
	return (i);
}
