/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:08:08 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 21:43:58 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_desc_x(unsigned int num, t_specifer *specials)
{
	int b;

	b = 55;
	if (specials->flag_type == 'x')
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
		ft_desc_x(num / 16, specials);
		ft_desc_x(num % 16, specials);
	}
}

static void		ft_prnt_rezult_xx(unsigned int param, int puts,
int len, t_specifer *specials)
{
	if (specials->flag_minus == 1)
	{
		ft_puts(specials->flag_accur - len, '0', specials);
		if (param != 0)
			ft_desc_x(param, specials);
	}
	if (specials->flag_minus == -1 && specials->flag_zero == 1
	&& specials->flag_accur == -1)
		ft_puts(puts, '0', specials);
	else
	{
		if (specials->flag_minus == -1 && specials->flag_zero == 1
		&& specials->flag_accur == 1)
			ft_puts(puts, '0', specials);
		else
			ft_puts(puts, ' ', specials);
	}
	if (specials->flag_minus == -1)
	{
		ft_puts(specials->flag_accur - len, '0', specials);
		if (param != 0)
			ft_desc_x(param, specials);
	}
}

void			ft_calc_xx(va_list arguments, t_specifer *specials)
{
	int				len;
	unsigned int	param;
	int				puts;
	int				len_max;

	param = va_arg(arguments, unsigned int);
	if (param == 0)
		len = ft_len_x(param);
	else
		len = ft_len_x(param) + 1;
	if (specials->flag_zero == 1 && specials->flag_accur != -1)
		specials->flag_zero = -1;
	if (specials->flag_accur == -1)
		specials->flag_accur = 1;
	if (specials->flag_accur > len)
		len_max = specials->flag_accur;
	else
		len_max = len;
	puts = specials->flag_width - len_max;
	ft_prnt_rezult_xx(param, puts, len, specials);
}
