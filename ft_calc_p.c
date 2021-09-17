/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:03:11 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 21:49:35 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_desc_p(unsigned long long int num, t_specifer *specials)
{
	int b;

	b = 55;
	if (specials->flag_type == 'p')
		b = 87;
	if (num < 16)
	{
		if (num <= 9)
			ft_sp_putchar(num + 48, specials);
		else
			ft_sp_putchar(num + b, specials);
	}
	else
	{
		ft_desc_p(num / 16, specials);
		ft_desc_p(num % 16, specials);
	}
}

static void		ft_flag_minus_p(size_t param, int len,
t_specifer *specials)
{
	ft_sp_putchar('0', specials);
	ft_sp_putchar('x', specials);
	ft_puts(specials->flag_accur - len, '0', specials);
	if (param != 0)
		ft_desc_p(param, specials);
	else if (param == 0 && specials->flag_accur != 0)
		ft_sp_putchar('0', specials);
}

static void		ft_prnt_rezult_p(size_t param, int len,
int puts, t_specifer *specials)
{
	if (specials->flag_minus == 1)
		ft_flag_minus_p(param, len, specials);
	if (specials->flag_minus == -1 && specials->flag_zero == 1 &&
	specials->flag_accur == -1)
		ft_puts(puts, '0', specials);
	else
	{
		if (specials->flag_minus == -1 && specials->flag_zero == 1 &&
		specials->flag_accur == 1)
			ft_puts(puts, '0', specials);
		else
			ft_puts(puts, ' ', specials);
	}
	if (specials->flag_minus == -1)
		ft_flag_minus_p(param, len, specials);
}

void			ft_calc_p(va_list arguments,
	t_specifer *specials)
{
	int		len;
	size_t	param;
	int		puts;
	int		len_max;

	param = (size_t)va_arg(arguments, void *);
	if (param == 0 && specials->flag_accur != 0)
		len = 3;
	else if (param == 0 && specials->flag_accur == 0)
		len = 2;
	else
		len = ft_len_p(param) + 3;
	if (specials->flag_accur == -1)
		specials->flag_accur = 1;
	if (specials->flag_accur > len)
		len_max = specials->flag_accur;
	else
		len_max = len;
	puts = specials->flag_width - len_max;
	ft_prnt_rezult_p(param, len, puts, specials);
}
