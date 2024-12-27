/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:49:22 by aid-bray          #+#    #+#             */
/*   Updated: 2024/12/18 14:21:43 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct t_flags
{
	int				n_space;
	int				n_zero;
	char			c_hash;
	char			c_dash;
	char			c_space;
	char			c_plus;
	char			c_minus;
	char			c_zero;
}					t_flags;

typedef struct t_infonbr
{
	unsigned int	nbr;
	int				count;
	int				sign;
	char			x;
	int				base;
}					t_infonbr;

int					ft_printf(const char *format, ...);
int					ft_putchar(char c, t_flags flag);
int					ft_putstr(char *str, t_flags flag);
int					ft_put_nbr(int nbr, t_flags flag);
int					ft_put_pointer(void *p, t_flags flag);
int					ft_put_unsigned(unsigned int nbr, t_flags flag);
int					ft_put_hexa(unsigned int nbr, char x, t_flags flag);
int					ft_put_nbr_base(size_t nbr, int base, char x);
int					count_digit(size_t nbr, int base);
int					put_spacezero(char c, int len);
int					put_flag_char(t_flags flag, t_infonbr info);
int					treat_flags(t_flags flag, t_infonbr info);
int					treat_nbr_zero(t_flags flag, t_infonbr info);
t_flags				set_flags(void);
int					ft_getnbr(const char *s, int *n);
int					get_spacezero(const char *s, t_flags *flag);
int					affiche_str(char *s, int len);

#endif