/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:47:27 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 22:23:37 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_specifer
{
	char	flag_minus;
	char	flag_zero;
	char	flag_type;
	int		flag_width;
	int		flag_accur;
	int		counter;
}				t_specifer;

void			ft_base_parameters(t_specifer *specials, int counter);
void			ft_sp_putchar(const char symbol, t_specifer *counter);
size_t			ft_strlen(const char *s);
void			ft_putnbr(long long int n, t_specifer *counter);
int				ft_len_num(long long num);
int				ft_atoi(const char *str);
int				ft_len_num(long long num);
int				ft_len_x(unsigned int num);
int				ft_len_p(unsigned long long int num);
int				ft_isdigit(int c);
void			ft_flags_pars(const char **str, t_specifer *specials);
void			ft_width_pars(const char **str,
va_list arguments, t_specifer *specials);
void			ft_checker_pars_accur(const char **str, t_specifer *specials);
void			ft_accur_pars(const char **str,
va_list arguments, t_specifer *specials);
void			ft_type_pars(const char **str, t_specifer *specials);
void			ft_pars_info(const char **str,
va_list arguments, t_specifer *specials);
void			ft_puts(int len, char c, t_specifer *specials);
void			ft_calc_c(va_list arguments, t_specifer *specials);
void			ft_calc_proc(t_specifer *specials);
void			ft_calc_s(va_list arguments, t_specifer *specials);
void			ft_calc_id(va_list arguments, t_specifer *specials);
void			ft_calc_u(va_list arguments, t_specifer *specials);
void			ft_calc_xx(va_list arguments, t_specifer *specials);
void			ft_calc_p(va_list arguments,
t_specifer *specials);
void			ft_manage(va_list arguments, t_specifer *specials);
int				ft_printf(const char *str, ...);

#endif
