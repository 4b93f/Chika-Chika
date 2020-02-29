/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:15:37 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/29 08:26:43 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check(to_list *flag, int *to_print)
{
	int nb_space;

	nb_space = 0;
	if (flag->PRECISION > 0)
	{
		if (flag->PRECISION < *to_print)
			*to_print = flag->PRECISION;
		if (flag->FLAG_NBR > *to_print)
			nb_space = flag->FLAG_NBR - *to_print;
	}
	else
		nb_space = flag->FLAG_NBR - *to_print;
	if (flag->FLAG_NBR > 0 && flag->PRECISION == 0)
		nb_space = flag->FLAG_NBR;
	return (nb_space);
}

int				ft_string(va_list args, to_list *flag, int i)
{
	int			to_print;
	int			nb_space;
	char		*str;

	nb_space = 0;
	str = va_arg(args, char*);
	str = !str ? "(null)" : str;
	to_print = ft_strlen(str);
	nb_space = ft_check(flag, &to_print);
	if (flag->FLAG_MINUS == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	if (!(flag->V_P == 1 && flag->PRECISION == 0))
	{
		write(1, str, to_print);
		 i += to_print;
	}
	if (flag->FLAG_MINUS > 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	return (i);
}
