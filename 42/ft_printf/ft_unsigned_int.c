/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:39:39 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/29 02:52:20 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check2(int *nb_space, to_list *flag, int to_print)
{
	int nb0;

	nb0 = 0;
	*nb_space = flag->FLAG_NBR - flag->PRECISION;
	nb0 = flag->PRECISION - to_print;
	return (nb0);
}

static int		ft_check(int *nb_space, to_list *flag, int to_print)
{
	int nb0;

	nb0 = 0;
	if (flag->PRECISION > 0 && flag->PRECISION >= flag->FLAG_NBR)
	{
		nb0 = flag->FLAG_NBR - to_print;
		if (flag->PRECISION >= flag->FLAG_NBR)
			nb0 = flag->PRECISION - to_print;
	}
	else if (flag->PRECISION > to_print && flag->FLAG_NBR >
	flag->PRECISION && flag->PRECISION > 0)
	{
		nb0 = ft_check2(nb_space, flag, to_print);
	}
	else
		*nb_space = flag->FLAG_NBR - to_print;
	return (nb0);
}

static int		apply(unsigned long long nb,
int nb_space, to_list *flag, int nb0)
{
	int i;

	i = 0;
	if (flag->FLAG_MINUS == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (!(flag->V_P == 1 && flag->PRECISION == 0 && nb == 0 && nb0 <= 0))
		ft_putunbr(nb);
	if (flag->FLAG_MINUS > 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	return (i);
}

int				ft_uint(va_list args, to_list *flag, int nb_space)
{
	int					i;
	int					nb0;
	int					to_print;
	unsigned long long	nb;

	nb = va_arg(args, long long);
	i = 0;
	to_print = unbnb(nb);
	nb0 = ft_check(&nb_space, flag, to_print);
	if (flag->FLAG_ZERO > 0 && flag->PRECISION < 0)
	{
		nb0 = flag->FLAG_NBR - to_print;
		nb_space = 0;
	}
	flag->PRECISION = flag->PRECISION < 0 ?
		-(flag->PRECISION) : flag->PRECISION;
	flag->PRECISION == 0 && flag->V_P == 1 && nb == 0 ? nb_space += 1 : 0;
	i += apply(nb, nb_space, flag, nb0);
	if (nb == 0)
		return (i);
	return (i + to_print);
}
