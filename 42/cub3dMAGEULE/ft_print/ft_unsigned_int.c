/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:39:39 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/03 17:00:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check2(int *nb_space, t_flag *flag, int to_print)
{
	int nb0;

	nb0 = 0;
	*nb_space = flag->width - flag->preci;
	nb0 = flag->preci - to_print;
	return (nb0);
}

static int		ft_check(int *nb_space, t_flag *flag, int to_print)
{
	int nb0;

	nb0 = 0;
	if (flag->preci > 0 && flag->preci >= flag->width)
	{
		nb0 = flag->width - to_print;
		if (flag->preci >= flag->width)
			nb0 = flag->preci - to_print;
	}
	else if (flag->preci > to_print && flag->width >
	flag->preci && flag->preci > 0)
	{
		nb0 = ft_check2(nb_space, flag, to_print);
	}
	else
		*nb_space = flag->width - to_print;
	return (nb0);
}

static int		apply(unsigned long long nb,
int nb_space, t_flag *flag, int nb0)
{
	int i;

	i = 0;
	if (flag->minus == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (!(flag->v_p == 1 && flag->preci == 0 && nb == 0 && nb0 <= 0))
	{
		ft_putunbr(nb);
		i += unbnb(nb);
	}
	if (flag->minus > 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	return (i);
}

int				ft_uint(va_list args, t_flag *flag, int nb_space)
{
	int					i;
	int					nb0;
	int					to_print;
	unsigned long long	nb;

	nb = va_arg(args, unsigned int);
	i = 0;
	to_print = unbnb(nb);
	nb0 = ft_check(&nb_space, flag, to_print);
	if (flag->zero > 0 && flag->preci < 0)
	{
		nb0 = flag->width - to_print;
		nb_space = 0;
		flag->preci = flag->preci < 0 ?
			-(flag->preci) : flag->preci;
		if (flag->minus > 0)
		{
			nb_space = nb0;
			nb0 = 0;
		}
	}
	flag->preci == 0 && flag->v_p == 1 && nb == 0 ? nb_space += 1 : 0;
	i += apply(nb, nb_space, flag, nb0);
	return (i);
}
