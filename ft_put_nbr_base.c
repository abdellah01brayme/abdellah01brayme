/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:39:41 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 11:40:04 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr_base(size_t nbr, int base, char x)
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
		write(1, &tab[i], 1);
	return (count);
}
