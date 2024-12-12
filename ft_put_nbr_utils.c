/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:16:08 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 11:04:11 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (nbr == 0)
		tab[i++] = '0';
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

int	ft_putpointer(void *p, t_flags flag)
{
	int	i;
	int	n_digit;
	int	len;

	i = 0;
	n_digit = count_digit((unsigned long)p , 16);
	if (!p)
		len = 5;
	else
		len = n_digit + 2;
	if (!flag.c_minus)
		i += put_spacezero(' ', flag.n_space - len);	
	if (!p)
		i += write (1, "(nil)", 5);
	else
	{
		i += write (1, "0x", 2);
		i += ft_put_nbrbase((unsigned long)p, 16, 'x');
	}
	if (flag.c_minus)
		i += put_spacezero(' ', flag.n_space - len);	
	return (i);
}

int	ft_putunsig(unsigned int nbr, t_flags flag)
{
	int			i;
	t_infonbr	info;

	info.base = 10;
	info.count = 0;
	info.nbr = nbr;
	info.sign = 0;
	info.x = 'a';
	i = 0;
	if (nbr)
		i += treat_flags(flag, info);
	else
		i += treat_nbr_zero(flag, info);
	return (i);
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
	count += ft_put_nbrbase(info.nbr, info.base, info.x);
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

int	ft_puthexa(unsigned int nbr, char x, t_flags flag)
{
	int			i;
	t_infonbr	info;

	info.nbr = nbr;
	info.base = 16;
	info.sign = 0;
	info.x = x;
	info.count = 0;
	if (flag.c_hash && nbr)
		info.count = 2;
	i = 0;
	if (nbr)
		i += treat_flags(flag, info);
	else
		i += treat_nbr_zero(flag, info);
	return (i);
}
