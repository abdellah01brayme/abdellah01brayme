/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:34:42 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 14:02:03 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int nbr, t_flags flag)
{
	int			i;
	t_infonbr	info;

	info.base = 10;
	info.count = 0;
	info.nbr = nbr;
	info.sign = 0;
	info.x = 'a';
	flag.c_hash = 0;
	flag.c_plus = 0;
	flag.c_space = 0;
	i = 0;
	if (nbr)
		i += treat_flags(flag, info);
	else
		i += treat_nbr_zero(flag, info);
	return (i);
}
