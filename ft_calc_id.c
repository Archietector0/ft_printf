/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:57:58 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 21:46:00 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_prnt_rezult_id(int param, int puts,
int len, t_specifer *specials)
{
	if (specials->flag_minus == 1 ||
	(specials->flag_minus == -1 && specials->flag_zero == 1))
		if (param < 0)
			ft_sp_putchar('-', specials);
	if (specials->flag_minus == 1)
	{
		ft_puts(specials->flag_accur - len, '0', specials);
		if (!(param == 0 && specials->flag_accur == 0))
			ft_putnbr(param, specials);
	}
	if (specials->flag_minus == -1 && specials->flag_zero == 1
	&& specials->flag_accur == -1)
		ft_puts(puts, '0', specials);
	else
		ft_puts(puts, ' ', specials);
	if (specials->flag_minus == -1 && specials->flag_zero == -1)
		if (param < 0)
			ft_sp_putchar('-', specials);
	if (specials->flag_minus == -1)
	{
		ft_puts(specials->flag_accur - len, '0', specials);
		if (!(param == 0 && specials->flag_accur == 0))
			ft_putnbr(param, specials);
	}
}

void			ft_calc_id(va_list arguments, t_specifer *specials)
{
	int len;
	int param;
	int puts;
	int len_max;

	param = va_arg(arguments, int);
	len = ft_len_num(param);
	if (param == 0 && specials->flag_accur != 0)
		len = 1;
	if (specials->flag_zero == 1 && specials->flag_accur != -1)
		specials->flag_zero = -1;
	if (specials->flag_accur > len)
		len_max = specials->flag_accur;
	else
		len_max = len;
	puts = specials->flag_width - len_max;
	if (param < 0)
		--puts;
	ft_prnt_rezult_id(param, puts, len, specials);
}
