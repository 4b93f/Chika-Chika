/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:41:15 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 08:19:54 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_character(char *str, va_list args, to_list *flag)
{
	int					tmp;
	int					i;
	int					fill;
	int 				x;

	i = 0;
	x = 0;
	tmp = va_arg(args, int);
	if (flag->FLAG_ZERO > 0)
		fill = '0';
	else
		fill = ' ';
	if (flag->FLAG_NBR > 0 && flag->FLAG_MINUS == 0)
	{
		while (i++ < flag->FLAG_NBR - 1)
			x += write(1, &fill, 1);
	}
	write(1, &tmp, 1);
	if (flag->FLAG_MINUS > 0 && flag->FLAG_NBR > 0)
	{
		while (i++ < flag->FLAG_NBR - 1)
			x+= write(1, &fill, 1);
	}
	return (x + 1);
}
