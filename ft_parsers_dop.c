/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_dop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:52:52 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 20:54:10 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_pars_info(const char **str,
va_list arguments, t_specifer *specials)
{
	ft_flags_pars(str, specials);
	ft_width_pars(str, arguments, specials);
	ft_accur_pars(str, arguments, specials);
	ft_type_pars(str, specials);
}

void			ft_puts(int len, char c, t_specifer *specials)
{
	while (len-- > 0)
		ft_sp_putchar(c, specials);
}
