/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:56:53 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 20:57:10 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_calc_s(va_list arguments, t_specifer *specials)
{
	const char		*param;
	long int		len;
	static char		sym = ' ';

	if (specials->flag_zero == 1 && specials->flag_minus == -1)
		sym = '0';
	if (!(param = va_arg(arguments, char *)))
		param = "(null)";
	len = ft_strlen(param);
	if (specials->flag_accur == -1)
		specials->flag_accur = len;
	else
	{
		if (len < specials->flag_accur)
			specials->flag_accur = len;
	}
	specials->flag_width -= specials->flag_accur;
	if (specials->flag_minus == 1)
		while (*param && specials->flag_accur-- > 0)
			ft_sp_putchar(*param++, specials);
	while (specials->flag_width-- > 0)
		ft_sp_putchar(sym, specials);
	if (specials->flag_minus == -1)
		while (*param && specials->flag_accur-- > 0)
			ft_sp_putchar(*param++, specials);
}
