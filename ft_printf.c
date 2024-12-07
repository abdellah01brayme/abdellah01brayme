#include "libft_printf.h"

int	get_spacezero(const char *s, int *space, int *zero)
{
	int	i;

	i = 0;
	*space = -1;
	*zero = -1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		*space = 0;
		while (s[i] >= '0' && s[i] <= '9')
		{
			(*space) = ((*space) * 10) + (s[i] - '0'); 
			i++;
		}
	}
	if (s[i] == '.')
	{
		i++;
		*zero = 0;
		while (s[i] >= '0' && s[i] <= '9')
		{
			(*zero) = ((*zero) * 10) + (s[i] - '0'); 
			i++;
		}
	}
	return (i);
}
int	get_flags(const char *s, flags *flag)
{
	int	i;

	i = 0;
	flag->c_flag ='\0';
	if (*s == ' ' || *s == '+' || *s == '#')
	{
		i++;
		flag->c_flag = *s;
		i += get_spacezero(s + i, &flag->n_space, &flag->n_zero);
		if (( *s == ' ' || *s == '+' ) && (s[i] == 'd' || s[i] == 'i'))
			return (i);
		else if (*s == '#' && (s[i] == 'x' || s[i] == 'X'))
			return (i);
		return (0);
	}
	i += get_spacezero(s, &flag->n_space, &flag->n_zero);
	if ((s[i] == 'i' || s[i] == 'd' || s[i] == 'u' || s[i] == 'p')
		|| (s[i] == 'x' || s[i] == 'X' || s[i] == 's' || s[i] == 'c'))
		return (i);
	return (0);
}

int	print_option(const char **format, va_list *args)
{
	flags	flag;
	int		option;

	option = get_flags(*format, &flag);
	*format += option;
	if (**format == 'i' || **format == 'd')
		return (ft_putnbr(va_arg(*args, int), flag));
	// if (**format == 'x' || **format == 'X')
	// 	return (ft_puthexa(va_arg(*args, unsigned int), flag));
	// if (**format == 'u')
	// 	return (ft_putunsig(va_arg(*args, unsigned int), flag));
	// if (**format == 'p')
		// return (ft_putpointer(va_arg(*args, size_t), flag));
	if (**format == 'c')
		return (ft_putchar(va_arg(*args, int), flag));
	if (**format == 's')
		return (ft_putstr(va_arg(*args, char *), flag));
	 return (option);
}
int	ft_printf(const char *format, ...)
{
	va_list args;
	int		count;
	int		tmp;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		tmp = 0;
		if (*format == '%' && ++format)
			tmp = print_option(&format, &args);
		else
			tmp = write (1, format, 1);
		if (tmp == -1)
			return (tmp);
		count += tmp;
		format++;
	}
	return (count);
}
