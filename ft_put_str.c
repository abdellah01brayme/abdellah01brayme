/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:25:46 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/20 18:41:06 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	affiche_str(char *s, int len)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < len && s[i])
	{
		count += write (1, &s[i], 1);
		i++;
	}
	return (count);
}

static int	put_strnull(t_flags flag)
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
		count += affiche_str("(null)", 6);
	if (flag.c_minus)
		count += put_spacezero(' ', flag.n_space - len);
	return (count);
}

static void	swap(int *a, int *b)
{
	int	n;

	n = *a;
	*a = *b;
	*b = n;
}

int	ft_putstr(char *str, t_flags flag)
{
	int	count;
	int	len;

	len = ft_strlen(str);
	count = 0;
	if (flag.c_zero && !flag.c_dash)
		swap(&flag.n_zero, &flag.n_space);
	if (!str)
		return (put_strnull(flag));
	if (flag.c_dash && flag.n_zero <= 0)
		len = 0;
	else if (flag.c_dash && flag.n_zero > 0 && flag.n_zero <= len)
		len = flag.n_zero;
	if (!flag.c_minus)
		count += put_spacezero(' ', flag.n_space - len);
	if (len)
		count += affiche_str(str, len);
	if (flag.c_minus)
		count += put_spacezero(' ', flag.n_space - len);
	return (count);
}
