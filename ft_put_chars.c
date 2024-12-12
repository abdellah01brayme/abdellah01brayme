/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:08:40 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 10:39:32 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c, t_flags flag)
{
	int	i;

	i = 0;
	if (!flag.c_minus)
		i += put_spacezero(' ', flag.n_space - 1);
	i += write (1, &c, 1);
	if (flag.c_minus)
		i += put_spacezero(' ', flag.n_space - 1);
	return (i);
}

int	put_strnull(t_flags flag)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	if (flag.n_zero == -1 && !flag.c_dash)
		len = 6;
	else if (flag.n_zero < 6 && flag.c_dash)
		len = 0;
	else
		len = 6;
	if (!flag.c_minus)
		count += put_spacezero(' ', flag.n_space - len);
	if (len)
			count += write (1, "(null)", 6);
	if (flag.c_minus)
		count += put_spacezero(' ', flag.n_space - len);
	return (count);
}

int	ft_putstr(char *str, t_flags flag)
{
	int	count;
	int	len;
	int	i;

	len = ft_strlen(str);
	count = 0;
	i = 0;
	if (!str)
		return (put_strnull(flag));
	if (flag.c_dash && flag.n_zero <= 0)
		len = 0;
	else if (flag.c_dash && flag.n_zero > 0 && flag.n_zero <= len)
		len = flag.n_zero;
	if (!flag.c_minus)
		count += put_spacezero(' ', flag.n_space - len);
	if (len)
		while (*str && i < len)
		{
			count += write (1, str++, 1);
			i++;
		}
	if (flag.c_minus)
		count += put_spacezero(' ', flag.n_space - len);
	return (count);
}
	// if (flag.n_zero >= 0 && flag.n_zero < len)
	// 	len = flag.n_zero;
	// if (len)
	// 	n = len;
	// else if (flag.n_zero >= 6 || flag.n_zero == -1)
	// 	n = 6;
	// else
	// 	n = 0;
	// if (!flag.c_minus)
	// 	count += put_spacezero(' ', flag.n_space - n);
	// if (len)
	// 	count += write (1, str, len);
	// else if (flag.n_zero >= 6 || flag.n_zero == -1)
	// 	count += write (1, "(null)", 6);
	// if (flag.c_minus)
	// 	count += put_spacezero(' ', flag.n_space - n);