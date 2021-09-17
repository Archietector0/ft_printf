/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:15:22 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 21:42:39 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_calc_c(va_list arguments, t_specifer *specials)
{
	char param;

	param = va_arg(arguments, int);
	if (specials->flag_type == '%')
		param = '%';
	if (specials->flag_minus == 1)
		ft_sp_putchar(param, specials);
	while (--specials->flag_width >= 1)
		ft_sp_putchar(' ', specials);
	if (specials->flag_minus == -1)
		ft_sp_putchar(param, specials);
}
