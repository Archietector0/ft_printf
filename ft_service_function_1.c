/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_service_function_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:25:25 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 21:32:14 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_base_parameters(t_specifer *specials, int counter)
{
	specials->flag_minus = -1;
	specials->flag_zero = -1;
	specials->flag_type = -1;
	specials->flag_width = -1;
	specials->flag_accur = -1;
	specials->counter = counter;
}

void			ft_sp_putchar(const char symbol, t_specifer *counter)
{
	write(1, &symbol, 1);
	counter->counter++;
}

size_t			ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void			ft_putnbr(long long int n, t_specifer *counter)
{
	unsigned int	num;
	char			let;

	if (n < 0)
		num = (unsigned int)-n;
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr(num / 10, counter);
	let = num % 10 + '0';
	ft_sp_putchar(let, counter);
}

int				ft_len_num(long long num)
{
	int i;

	i = 0;
	if (num > 0)
		while (num > 0)
		{
			num /= 10;
			i++;
		}
	else
		while (num < 0)
		{
			num /= 10;
			i++;
		}
	return (i);
}
