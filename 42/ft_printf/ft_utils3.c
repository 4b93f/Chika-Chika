/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:51:28 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/01 03:59:53 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_init_struct(to_list *flag)
{
	flag->FLAG_ZERO = 0;
	flag->FLAG_MINUS = 0;
	flag->FLAG_DOT = 0;
	flag->FLAG_STARS = 0;
	flag->FLAG_NBR = 0;
	flag->WIDTH = 0;
	flag->PRECISION = -1;
	flag->V_P = 0;
	flag->PRECI_NEG = 0;
	return (1);
}

int				mini_atoi(char *str, int *i)
{
	int res;

	res = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
		*i = *i + 1;
		if (res < 0)
			return (0);
	}
	return (res);
}

int				ft_width_calc(char *str, int *i, va_list args)
{
	int res;

	res = 0;
	if ((res = mini_atoi(str, i)) >= 0)
	{
		if (str[*i] == '*')
		{
			*i = *i + 1;
			return (va_arg(args, int));
		}
		return (res);
	}
	return (0);
}

long long		ft_strllen(char *str)
{
	long long		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
