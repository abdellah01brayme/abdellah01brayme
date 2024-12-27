/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:33:57 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/18 14:22:55 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_pointer(void *p, t_flags flag)
{
	int	i;
	int	n_digit;
	int	len;

	i = 0;
	n_digit = count_digit((unsigned long)p, 16);
	if (!p)
		len = 5;
	else
		len = n_digit + 2;
	if (!flag.c_minus)
		i += put_spacezero(' ', flag.n_space - len);
	if (!p)
		i += affiche_str("(nil)", 5);
	else
	{
		i += affiche_str("0x", 2);
		i += ft_put_nbr_base((unsigned long)p, 16, 'x');
	}
	if (flag.c_minus)
		i += put_spacezero(' ', flag.n_space - len);
	return (i);
}
