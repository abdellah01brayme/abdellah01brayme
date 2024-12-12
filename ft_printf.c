/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:08:34 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 11:09:45 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr(const char *s, char c)
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

t_flags set_flags()
{
	t_flags flag;

	flag.n_space = -1;
	flag.n_zero = -1;
	flag.c_hash = 0;
	flag.c_dash = 0;
	flag.c_space = 0;
	flag.c_plus = 0;
	flag.c_minus = 0;
	flag.c_zero = 0;
	return (flag);
}

int	accept_flags(t_flags flag, char c)
{
	if (c == '%')
		return (1);
	else if ((flag.c_hash && (flag.c_plus || flag.c_space || flag.c_space))
		|| (flag.c_plus && flag.c_space) || (flag.c_minus && flag.c_zero)
		|| ((flag.c_plus || flag.c_hash || flag.c_zero || flag.c_space ||
			(flag.n_zero >= 0 && flag.c_dash)) && (c == 'c' || c == 'p'))
		|| ((flag.c_plus || flag.c_hash || flag.c_zero || flag.c_space)
			&& c == 's') )
		return (0);
	else if (!flag.c_hash && !flag.c_plus && !flag.c_space)
		return (1);
	else if (flag.c_hash && (c == 'x' || c == 'X'))
		return (1);
	else if ((flag.c_plus || flag.c_space) && (c == 'i' || c == 'd'))
		return (1);
	return (0);
}

int	ft_getnbr(const char *s, int *n)
{
	int	i;

	i = 0;
	*n = -1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		*n = 0;
		while (s[i] >= '0' && s[i] <= '9')
			*n = ((*n) * 10) + (s[i++] - '0');
	}
	return (i);
}

int	get_spacezero(const char *s, t_flags *flag)
{
	int	i;
	int	n1;
	int	n2;

	i = 0;
	i += ft_getnbr(s, &n1);
	if (s[i] == '.')
		i += ft_getnbr(s + i + 1, &n2) + ++flag->c_dash;
	if (flag->c_dash)
	{
		flag->n_space = n1;
		flag->n_zero = n2;
	}
	else if (flag->c_zero)
		flag->n_zero = n1;
	else
		flag->n_space = n1;
	if (flag->c_zero && !flag->c_dash && flag->n_zero > 0)
		flag->n_space = -1;
	return (i);
}

int	get_flags(const char *s, t_flags *flag)
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
	if (!accept_flags(*flag, s[i]))
		return (-1);
	return (i);
}

int	print_option(const char **format, va_list *args)
{
	t_flags	flag;
	int		option;

	option = get_flags(*format, &flag);
	if (option == -1)
		return (-1);
	*format += option;
	if (**format == 'i' || **format == 'd')
		return (ft_putnbr(va_arg(*args, int), flag));
	if (**format == 'x' || **format == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), **format, flag));
	if (**format == 'u')
		return (ft_putunsig(va_arg(*args, unsigned int), flag));
	if (**format == 'p')
		return (ft_putpointer(va_arg(*args, void *), flag));
	if (**format == 'c')
		return (ft_putchar(va_arg(*args, int), flag));
	if (**format == 's')
		return (ft_putstr(va_arg(*args, char *), flag));
	if (**format == '%')
		return (ft_putchar('%', flag));
	return (option);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
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
