/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:55:04 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 20:55:48 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_calc_proc(t_specifer *specials)
{
	char sym;

	sym = ' ';
	if (specials->flag_zero == 1 && specials->flag_minus == -1)
		sym = '0';
	if (specials->flag_minus == 1)
		ft_sp_putchar('%', specials);
	while (--specials->flag_width >= 1)
		ft_sp_putchar(sym, specials);
	if (specials->flag_minus == -1)
		ft_sp_putchar('%', specials);
}
