/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:32:27 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 09:02:34 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_error(to_list *flag, int y)
{
	int i;

	i = 0;
	while (i++ < flag->FLAG_NBR)
		write(1, " ", 1);
	return (i);
}

static int		ft_apply(int fill, to_list *flag, int len, int i)
{
	int tmp;
	int stock;

	fill == 0 ? fill = 1 : 0;
	tmp = fill;
	flag->FLAG_ZERO > 0 ? stock = '0' : 0;
	flag->FLAG_ZERO == 0 ? stock = ' ' : 0;
	if (tmp == 1)
		tmp = tmp + len - 1;
	if (flag->FLAG_NBR > 0 && flag->FLAG_MINUS == 0)
	{
		tmp == 0 ? flag->FLAG_NBR = flag->FLAG_NBR - 1 : 0;
		tmp > 1 ? flag->FLAG_NBR = flag->FLAG_NBR - tmp - 1 : 0;
		tmp < 1 ? flag->FLAG_NBR = flag->FLAG_NBR - len - 1 : 0;
		while (i < flag->FLAG_NBR + 1)
		{
			write(1, &stock, 1);
			i = i + 1;
		}
	}
	if (fill > len)
		while (fill-- > len)
			i += write(1, "0", 1);
	return (i);
}

int		ft_integer(char *str, va_list args, to_list *flag, int x)
{
	char				*tmp;
	long long			y;
	int					len;
	int					i;
	int					fill;

	i = 0;
	y = va_arg(args, long long);
	if (y == 0 && flag->PRECISION == 0)
		return (ft_check_error(flag, y));
	y < 0 ? write(1, "-", 1) : 0;
	tmp = ft_itoll(y);
	tmp = !tmp ? "(null)" : tmp;
	len = ft_strlen(tmp);
	fill = flag->PRECISION;
	len < flag->PRECISION ? flag->PRECISION = len : 0;
	x = ft_apply(fill, flag, len, i);
	write(1, tmp, len);
	if (flag->FLAG_MINUS > 0)
	{
		flag->FLAG_NBR = flag->FLAG_NBR - flag->PRECISION + 1;
		while (i++ < flag->FLAG_NBR - 1)
			x += write(1, " ", 1);
	}
	return (x + len - 1);
}
