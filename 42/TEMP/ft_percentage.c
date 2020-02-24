/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:07:26 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 08:51:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percentage(char *str, va_list args, to_list *flag, int x)
{
	int i;
	int fill;

	i = 0;
	if (flag->FLAG_ZERO > 0)
		fill = '0';
	else
		fill = ' ';
	if (flag->FLAG_NBR > 0 && flag->FLAG_MINUS == 0)
	{
		flag->PRECISION == 0 ? flag->FLAG_NBR = flag->FLAG_NBR - 1 : 0;
		flag->PRECISION > 0 ? flag->FLAG_NBR = flag->FLAG_NBR -
		flag->PRECISION - 1 : 0;
		while (i++ < flag->FLAG_NBR - 1)
			x +=write(1, &fill, 1);
	}
	if (flag->FLAG_MINUS > 0)
	{
		flag->FLAG_NBR = flag->FLAG_NBR - flag->PRECISION + 1;
		while (i++ < flag->FLAG_NBR - 1)
			x +=write(1, &fill, 1);
	}
	write(1, "%%", 1);
	return (x + i + 1);
}
