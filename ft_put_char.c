/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:08:40 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/18 14:28:03 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags flag)
{
	int	i;

	i = 0;
	if (flag.c_zero && !flag.c_dash)
		flag.n_space = flag.n_zero;
	if (!flag.c_minus)
		i += put_spacezero(' ', flag.n_space - 1);
	i += write(1, &c, 1);
	if (flag.c_minus)
		i += put_spacezero(' ', flag.n_space - 1);
	return (i);
}
