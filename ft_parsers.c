/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:46:35 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 20:54:06 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_flags_pars(const char **str, t_specifer *specials)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			specials->flag_minus = 1;
		else
			specials->flag_zero = 1;
		(*str)++;
	}
}

void			ft_width_pars(const char **str,
va_list arguments, t_specifer *specials)
{
	int f;

	if (**str == '*')
	{
		specials->flag_width = va_arg(arguments, int);
		if (specials->flag_width < 0)
		{
			specials->flag_minus = 1;
			specials->flag_width *= -1;
		}
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		specials->flag_width = ft_atoi(*str);
		f = ft_len_num(specials->flag_width);
		while (**str == '0')
			++*str;
		(*str) += f;
	}
}

void			ft_checker_pars_accur(const char **str, t_specifer *specials)
{
	int f;

	specials->flag_accur = ft_atoi(*str);
	f = ft_len_num(specials->flag_accur);
	while (**str == '0')
		++*str;
	(*str) += f;
}

void			ft_accur_pars(const char **str,
va_list arguments, t_specifer *specials)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			specials->flag_accur = va_arg(arguments, int);
			if (specials->flag_accur < 0)
				specials->flag_accur = -1;
			(*str)++;
		}
		else if (ft_isdigit(**str))
			ft_checker_pars_accur(str, specials);
		else if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
				**str == 'i' || **str == 'u' || **str == 'x' || **str == 'X' ||
				**str == '%')
		{
			specials->flag_accur = 0;
			specials->flag_type = **str;
		}
	}
}

void			ft_type_pars(const char **str, t_specifer *specials)
{
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
		**str == 'i' || **str == 'u' || **str == 'x' || **str == 'X' ||
		**str == '%')
	{
		specials->flag_type = **str;
		++*str;
	}
}
