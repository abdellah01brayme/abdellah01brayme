/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:08:44 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 11:13:30 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digit(size_t nbr, int base)
{
	int	i;

	if (!nbr)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	put_spacezero(char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write (1, &c, 1);
		i++;
	}
	return (i);
}

int	put_flag_char(t_flags flag, t_infonbr info)
{
	if (info.sign)
		return (write (1, "-", 1));
	else if (flag.c_plus)
		return (write (1, "+", 1));
	else if (flag.c_space)
		return (write (1, " ", 1));
	else if (flag.c_hash && info.nbr)
		return (write (1, "0", 1) + write (1, &info.x, 1));
	return (0);
}


int	ft_putnbr(int nbr, t_flags flag)
{
	int				i;
	t_infonbr		info;

	info.base = 10;
	info.x = 'a';
	if ((flag.c_plus && flag.c_space)
		|| (flag.c_hash && (flag.c_plus || flag.c_space)))
		return (-1);
	i = 0;
	info.nbr = nbr;
	info.sign = 0;
	info.count = 0;
	if (nbr < 0)
	{
		info.nbr = -nbr;
		info.sign = 1;
		info.count = 1;
	}
	if ((flag.c_plus || flag.c_space) && !info.count)
		info.count = 1;
	if (flag.c_zero && !flag.c_dash && flag.n_zero > 0 && info.sign)
		flag.n_zero--;
	if (nbr)
		i += treat_flags(flag, info);
	else
		i += treat_nbr_zero(flag, info);
	return (i);
}