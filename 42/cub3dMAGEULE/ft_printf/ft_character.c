/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:41:15 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/03 16:57:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_character(va_list args, t_flag *flag)
{
	int					tmp;
	int					i;
	int					fill;
	int					x;

	i = 0;
	x = 0;
	tmp = va_arg(args, int);
	if (flag->zero > 0)
		fill = '0';
	else
		fill = ' ';
	if (flag->width > 0 && flag->minus == 0)
	{
		while (i++ < flag->width - 1)
			x += write(1, &fill, 1);
	}
	x += write(1, &tmp, 1);
	if (flag->minus > 0 && flag->width > 0)
	{
		while (i++ < flag->width - 1)
			x += write(1, &fill, 1);
	}
	return (x);
}
