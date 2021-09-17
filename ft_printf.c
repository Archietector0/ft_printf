/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:44:24 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 22:19:15 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_manage(va_list arguments, t_specifer *specials)
{
	if (specials->flag_type == 'c')
		ft_calc_c(arguments, specials);
	else if (specials->flag_type == 's')
		ft_calc_s(arguments, specials);
	else if (specials->flag_type == 'p')
		ft_calc_p(arguments, specials);
	else if (specials->flag_type == 'i' || specials->flag_type == 'd')
		ft_calc_id(arguments, specials);
	else if (specials->flag_type == 'u')
		ft_calc_u(arguments, specials);
	else if (specials->flag_type == 'x' || specials->flag_type == 'X')
		ft_calc_xx(arguments, specials);
	else if (specials->flag_type == '%')
		ft_calc_proc(specials);
}

int			ft_printf(const char *str, ...)
{
	t_specifer	specials;
	va_list		arguments;

	va_start(arguments, str);
	ft_base_parameters(&specials, 0);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			++str;
			ft_pars_info(&str, arguments, &specials);
			ft_manage(arguments, &specials);
			ft_base_parameters(&specials, specials.counter);
		}
		else
			ft_sp_putchar(*str++, &specials);
	}
	va_end(arguments);
	return (specials.counter);
}
