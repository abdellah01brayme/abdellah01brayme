/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:49:22 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/12 09:57:14 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct t_flags
{
	int		n_space;
	int		n_zero;
	char	c_hash;
	char	c_dash;
	char	c_space;
	char	c_plus;
	char	c_minus;
	char	c_zero;
}	t_flags;
typedef struct t_infonbr
{
	unsigned int	nbr;
	int				count;
	int				sign;
	char			x;
	int				base;
}	t_infonbr;

int	ft_printf(const char *format, ...);
int	ft_putnbr(int nbr, t_flags flag);
int	ft_putpointer(void *p, t_flags flag);
int	ft_putunsig(unsigned int nbr, t_flags flag);
int	ft_puthexa(unsigned int nbr, char x, t_flags flag);
int	ft_put_nbrbase(size_t nbr, int base, char x);
int	put_spacezero(char c, int len);
int	count_digit(size_t nbr, int base);
int	put_flag_char(t_flags flag, t_infonbr info);
int	treat_flags(t_flags flag, t_infonbr info);
int	treat_nbr_zero(t_flags flag, t_infonbr info);

int	ft_putchar(char c, t_flags flag);
int	ft_putstr(char *str, t_flags flag);

#endif