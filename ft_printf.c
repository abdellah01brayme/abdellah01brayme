/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:08:34 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/20 18:43:49 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == c)
			return (i);
	}
	return (0);
}

static int	get_flags(const char *s, t_flags *flag, int *option)
{
	int	i;

	i = 0;
	*flag = set_flags();
	while (ft_strchr("# +0-", s[i]))
	{
		if (s[i] == '#')
			flag->c_hash = '#';
		else if (s[i] == ' ')
			flag->c_space = ' ';
		else if (s[i] == '+')
			flag->c_plus = '+';
		else if (s[i] == '0')
			flag->c_zero = '0';
		else if (s[i] == '-')
			flag->c_minus = '-';
		i++;
	}
	i += get_spacezero(s + i, flag);
	if (ft_strchr("idxXupcs%", s[i]))
		return (*option = i, 1);
	return (*option = i, 0);
}

static int	put_flag_error(char c, t_flags flag)
{
	int		count;

	count = write (1, "%", 1);
	if (flag.c_hash == '#')
		count += write (1, "#", 1);
	if (flag.c_plus == '+')
		count += write (1, "+", 1);
	else if (flag.c_space == ' ')
		count += write (1, " ", 1);
	if (flag.c_minus == '-')
		count += write (1, "-", 1);
	else if (flag.c_zero == '0')
		count += write (1, "0", 1);
	if (flag.n_space > 0)
		count += ft_put_nbr_base(flag.n_space, 10, 'a');
	if (flag.c_dash && flag.n_zero <= 0)
		count += write (1, ".0", 2);
	else if (flag.n_zero > 0)
	{
		count += write (1, ".", 1);
		count += ft_put_nbr_base(flag.n_zero, 10, 'a');
	}
	count += write (1, &c, 1);
	return (count);
}

static int	print_option(const char **format, va_list args)
{
	t_flags	flag;
	int		option;
	int		i;

	i = get_flags(*format, &flag, &option);
	*format += option;
	if (!i)
		return (put_flag_error(**format, flag));
	if (**format == 'i' || **format == 'd')
		return (ft_put_nbr(va_arg(args, int), flag));
	if (**format == 'x' || **format == 'X')
		return (ft_put_hexa(va_arg(args, unsigned int), **format, flag));
	if (**format == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int), flag));
	if (**format == 'p')
		return (ft_put_pointer(va_arg(args, void *), flag));
	if (**format == 'c')
		return (ft_putchar(va_arg(args, int), flag));
	if (**format == 's')
		return (ft_putstr(va_arg(args, char *), flag));
	if (**format == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	if (!format || (write (1, 0, 0) == -1))
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		tmp = 0;
		if (*format == '%' && ++format)
			tmp = print_option(&format, args);
		else
			tmp = write(1, format, 1);
		count += tmp;
		format++;
	}
	return (count);
}
