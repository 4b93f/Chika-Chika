/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:39:39 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/25 08:06:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int				ft_check_error(to_list *flag)
{
	int i;

	i = 0;
	while (i++ < flag->FLAG_NBR)
		write(1, " ", 1);
	return (i);
}

static int			ft_apply(int fill, to_list *flag, int len)
{
	int tmp;
	int stock;
	int i;

	i = 0;
	fill == 0 ? fill = 1 : 0;
	tmp = fill;
	flag->FLAG_ZERO > 0 ? stock = '0' : 0;
	flag->FLAG_ZERO == 0 ? stock = ' ' : 0;
	tmp == 1 ? tmp = tmp + len - 1 : 0;
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

int						ft_uint(va_list args, to_list *flag, int x)
{
	char				*tmp;
	unsigned long long	y;
	int					len;
	int					i;
	int					fill;

	i = 0;
	y = va_arg(args, unsigned long long);
	if (y == 0 && flag->PRECISION == 0)
		return (ft_check_error(flag));
	tmp = ft_u_itoa(y);
	tmp = !tmp ? "(null)" : tmp;
	len = ft_strlen(tmp);
	fill = flag->PRECISION;
	len < flag->PRECISION ? flag->PRECISION = len : 0;
	i = ft_apply(fill, flag, len);
	x += write(1, tmp, len);
	if (flag->FLAG_MINUS > 0)
	{
		flag->FLAG_NBR = flag->FLAG_NBR - flag->PRECISION + 1;
		while (i++ < flag->FLAG_NBR - 1)
			x += write(1, " ", 1);
	}
	printf("i = %d", i);
	return (i);
}
*/

static int		check(to_list *flag, int *fill, int max_print, int nb)
{

	*fill = flag->FLAG_ZERO > 0 && flag->PRECISION >= 0 ? '0' : ' ';
	*fill = flag->PRECISION < flag->FLAG_NBR ? ' ' : '0';
	if (flag->FLAG_ZERO > 0)
		*fill = '0';
	flag->PRECISION = flag->PRECISION < nbnb(nb) ? 0 : flag->PRECISION;
	max_print = flag->PRECISION > -1 ? flag->FLAG_NBR -
	flag->PRECISION : flag->FLAG_NBR;
	max_print = flag->PRECISION <= 0 ? flag->FLAG_NBR - unbnb(nb) : max_print;
	flag->FLAG_NBR = flag->FLAG_NBR <= flag->PRECISION ? 0 : flag->FLAG_NBR;
	return (max_print);
}

static void		apply_minus(int fill, int nb, int *x)
{
	if (fill == '0' && nb < -2147483648)
	{
		write(1, "-", 1);
		*x = *x + 1;
	}
}

int				ft_uint(va_list args, to_list *flag, int x)
{
	unsigned long long	nb;
	int					fill;
	int					i;
	int					max_print;

	nb = va_arg(args, long long);
	i = 0;
	if (nb == 0 && flag->PRECISION == 0)
		return (0);
	max_print = 0;
	max_print = check(flag, &fill, max_print, nb);
	apply_minus(fill, nb, &x);
	while (i++ < max_print)
	{
		if (flag->FLAG_MINUS == 0)
			x += write(1, &fill, 1);
	}
	while (flag->PRECISION-- > (unbnb(nb)))
		x += write(1, "0", 1);
	ft_putunbr(nb);
	i = unbnb(nb);
	while (i++ < flag->FLAG_NBR && flag->FLAG_MINUS > 0)
		x += write(1, " ", 1);
	return (x + unbnb(nb));
}