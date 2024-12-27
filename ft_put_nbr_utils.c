/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:16:08 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/16 09:34:29 by aid-bray         ###   ########.fr       */
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
	int	count;

	count = 0;
	while (len-- > 0)
		count += write(1, &c, 1);
	return (count);
}

int	put_flag_char(t_flags flag, t_infonbr info)
{
	if (info.sign)
		return (write(1, "-", 1));
	else if (flag.c_plus)
		return (write(1, "+", 1));
	else if (flag.c_space)
		return (write(1, " ", 1));
	else if (flag.c_hash && info.nbr)
		return (write(1, "0", 1) + write(1, &info.x, 1));
	return (0);
}

int	treat_flags(t_flags flag, t_infonbr info)
{
	int	count;
	int	n_digit;

	count = 0;
	n_digit = count_digit(info.nbr, info.base);
	if (n_digit > flag.n_zero)
		flag.n_zero = n_digit;
	if (!flag.c_minus)
		count += put_spacezero(' ', flag.n_space - (flag.n_zero + info.count));
	count += put_flag_char(flag, info);
	count += put_spacezero('0', flag.n_zero - n_digit);
	count += ft_put_nbr_base(info.nbr, info.base, info.x);
	if (flag.c_minus)
		count += put_spacezero(' ', flag.n_space - (flag.n_zero + info.count));
	return (count);
}

int	treat_nbr_zero(t_flags flag, t_infonbr info)
{
	int	count;
	int	len;

	len = 0;
	count = 0;
	if (flag.n_zero > 0)
		len = flag.n_zero;
	else if (flag.n_zero <= 0 && !flag.c_dash)
		len = 1;
	if (!flag.c_minus)
		count += put_spacezero(' ', flag.n_space - (len + info.count));
	count += put_flag_char(flag, info);
	count += put_spacezero('0', len);
	if (flag.c_minus)
		count += put_spacezero(' ', flag.n_space - (len + info.count));
	return (count);
}
