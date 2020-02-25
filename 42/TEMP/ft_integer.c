/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:32:27 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/25 08:15:24 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check(to_list *flag, int *fill, int max_print, int nb)
{

	*fill = flag->FLAG_ZERO > 0 && flag->PRECISION >= 0 ? '0' : ' ';
	*fill = flag->PRECISION < flag->FLAG_NBR ? ' ' : '0';
	if (flag->FLAG_ZERO > 0)
		*fill = '0';
	flag->PRECISION = flag->PRECISION < nbnb(nb) ? 0 : flag->PRECISION;
	max_print = flag->PRECISION > -1 ? flag->FLAG_NBR -
	flag->PRECISION : flag->FLAG_NBR;
	max_print = flag->PRECISION <= 0 ? flag->FLAG_NBR - nbnb(nb) : max_print;
	flag->FLAG_NBR = flag->FLAG_NBR <= flag->PRECISION ? 0 : flag->FLAG_NBR;
	return (max_print);
}

static int		apply_minus(int fill, int nb, int *x)
{
	if (fill == '0' && nb < 0)
	{
		write(1, "-", 1);
		nb *= (-1);
		*x = *x + 1;
	}
	return (nb);
}

int				ft_integer(va_list args, to_list *flag, int x)
{
	int nb;
	int fill;
	int i;
	int max_print;

	nb = va_arg(args, int);
	i = 0;
	if (nb == 0 && flag->PRECISION == 0)
		return (0);
	max_print = 0;
	max_print = check(flag, &fill, max_print, nb);
	nb = apply_minus(fill, nb, &x);
	while (i++ < max_print)
	{
		if (flag->FLAG_MINUS == 0)
			x += write(1, &fill, 1);
	}
	while (flag->PRECISION-- > (nbnb(nb)))
		x += write(1, "0", 1);
	ft_putnbr(nb);
	while (i++ < flag->FLAG_NBR && flag->FLAG_MINUS > 0)
		x += write(1, " ", 1);
	return (x + nbnb(nb));
}
