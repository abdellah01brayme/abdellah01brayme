/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:04:50 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/14 16:57:04 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	set_flags(void)
{
	t_flags	flag;

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
	{
		flag->c_dash = '.';
		i += ft_getnbr(s + i + 1, &n2) + 1;
	}
	if (flag->c_dash)
	{
		flag->n_space = n1;
		flag->n_zero = n2;
	}
	else if (flag->c_zero && !flag->c_minus)
		flag->n_zero = n1;
	else
		flag->n_space = n1;
	if (flag->c_zero && !flag->c_dash && flag->n_zero > 0)
		flag->n_space = -1;
	return (i);
}
