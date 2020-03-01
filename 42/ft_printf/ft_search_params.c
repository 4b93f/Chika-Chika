/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:28:57 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/01 09:23:59 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_and_preci(to_list *flag, va_list args, char *str, int i)
{
	flag->FLAG_NBR += ft_width_calc(str, &i, args);
	flag->WIDTH = ft_width_calc(str, &i, args);
	if (str[i] == '.')
	{
		i = i + 1;
		flag->PRECISION = ft_width_calc(str, &i, args);
		flag->V_P = 1;
	}
	return (i);
}

void	ft_search_all(char *str, int *i, to_list *flag, va_list args)
{
	*i = *i + 1;
	while (str[*i] == '-' || str[*i] == '0')
	{
		str[*i] == '0' ? flag->FLAG_ZERO += 1 : 0;
		str[*i] == '-' ? flag->FLAG_MINUS += 1 : 0;
		*i = *i + 1;
	}
	*i = width_and_preci(flag, args, str, *i);
	if (flag->FLAG_NBR < 0)
	{
		flag->FLAG_MINUS += 1;
		flag->FLAG_NBR *= -1;
		flag->PRECI_NEG = 1;
	}
	if (flag->WIDTH < 0)
	{
		flag->FLAG_MINUS += 1;
		flag->WIDTH *= -1;
	}
	return ;
}
