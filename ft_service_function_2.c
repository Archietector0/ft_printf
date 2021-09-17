/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_function_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:28:54 by tbarth            #+#    #+#             */
/*   Updated: 2021/01/19 20:30:20 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_miss(const char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || str[*i] == '\t' ||
		str[*i] == '\n' || str[*i] == '\v'
		|| str[*i] == '\f' || str[*i] == '\r')
		*i = *i + 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i = *i + 1;
	}
}

int				ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	ft_miss(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign < 0)
		{
			if (num < -922337203685477580
				|| (num == -922337203685477580 && str[i] > '8'))
				return (0);
		}
		else
		{
			if (num > 922337203685477580
				|| (num == 922337203685477580 && str[i] > '7'))
				return (-1);
		}
		num = (num * 10) + (str[i++] - '0') * sign;
	}
	return ((int)num);
}

int				ft_len_x(unsigned int num)
{
	int i;

	i = 0;
	while (num /= 16)
		i++;
	return (i);
}

int				ft_len_p(unsigned long long int num)
{
	int i;

	i = 0;
	while (num /= 16)
		i++;
	return (i);
}

int				ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
