/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:36:13 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 13:59:23 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned int nbr, char x, t_flags flag)
{
	int			i;
	t_infonbr	info;

	info.nbr = nbr;
	info.base = 16;
	info.sign = 0;
	info.x = x;
	info.count = 0;
	flag.c_plus = 0;
	flag.c_space = 0;
	if (flag.c_hash && nbr)
		info.count = 2;
	i = 0;
	if (nbr)
		i += treat_flags(flag, info);
	else
		i += treat_nbr_zero(flag, info);
	return (i);
}
