/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:32:27 by chly-huc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/29 03:12:37 by chly-huc         ###   ########.fr       */
=======
/*   Updated: 2020/03/01 07:24:47 by chly-huc         ###   ########.fr       */
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check2(long long nb, int *nb_space,
to_list *flag, int to_print)
{
	int nb0;

	nb0 = 0;
	*nb_space = flag->FLAG_NBR - flag->PRECISION;
	if (nb < 0)
	{
		nb0 = flag->PRECISION - to_print + 1;
		*nb_space = *nb_space - 1;
	}
	else
		nb0 = flag->PRECISION - to_print;
	return (nb0);
}

static int		ft_check(long long nb,
int *nb_space, to_list *flag, int to_print)
{
	int nb0;

	nb0 = 0;
	if (flag->PRECISION > 0 && flag->PRECISION >= flag->FLAG_NBR)
	{
		nb0 = flag->FLAG_NBR - to_print;
		if (flag->PRECISION >= flag->FLAG_NBR)
			nb0 = flag->PRECISION - to_print;
		if (nb < 0)
			nb0++;
	}
<<<<<<< HEAD
	else if (flag->PRECISION > to_print && flag->FLAG_NBR >
	flag->PRECISION && flag->PRECISION > 0)
	{
		nb0 = ft_check2(nb, nb_space, flag, to_print);
	}
=======
	else if (flag->PRECISION >= to_print && flag->FLAG_NBR >
	flag->PRECISION && flag->PRECISION > 0)
		nb0 = ft_check2(nb, nb_space, flag, to_print);
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
	else
		*nb_space = flag->FLAG_NBR - to_print;
	return (nb0);
}

static int		apply(long long nb, int nb_space, to_list *flag, int nb0)
{
	int i;

	i = 0;
	if (flag->FLAG_MINUS == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	if (nb < 0)
<<<<<<< HEAD
		i += write(1, "-", 1);
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (!(flag->V_P == 1 && flag->PRECISION == 0 && nb == 0 && nb0 <= 0))
		nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
=======
		write(1, "-", 1);
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (!(flag->V_P == 1 && flag->PRECISION == 0 && nb == 0 && nb0 <= 0))
	{
		nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
		i += nbnb(nb);
	}
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
	if (flag->FLAG_MINUS > 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	return (i);
}

int				ft_integer(va_list args,
to_list *flag, int nb_space, long long nb)
{
	int i;
	int nb0;
	int to_print;

	nb = (long long)va_arg(args, int);
	i = 0;
	to_print = nbnb(nb);
	nb0 = ft_check(nb, &nb_space, flag, to_print);
<<<<<<< HEAD
=======
	//printf("flag->NBR = %d\n", flag->FLAG_NBR);
	//printf("flag->PRECI = %d\n", flag->PRECISION);
	//printf("i = %d\n", i);
	//printf("Flag->MINUS = %d\n", flag->FLAG_MINUS);
	//printf("to_print = %d\n", to_print);
	//printf("flagneg = %d\n", flag->PRECI_NEG);
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
	if (flag->FLAG_ZERO > 0 && flag->PRECISION < 0)
	{
		nb0 = flag->FLAG_NBR - to_print;
		nb_space = 0;
<<<<<<< HEAD
	}
	flag->PRECISION = flag->PRECISION < 0 ?
		-(flag->PRECISION) : flag->PRECISION;
	flag->PRECISION == 0 && flag->V_P == 1 && nb == 0 ? nb_space += 1 : 0;
	apply(nb, nb_space, flag, nb0);
	if (nb == 0)
		return (i);
	return (nb < 0 ? i + to_print : i + to_print);
=======
		flag->PRECISION = flag->PRECISION < 0 ?
			-(flag->PRECISION) : flag->PRECISION;
		if (flag->FLAG_MINUS > 0)
		{
			nb_space = nb0;
			nb0 = 0;
		}
	}
	//printf("nb0 = %d\n", nb0);
	//printf("nb_space = %d\n", nb_space);
	flag->PRECISION = flag->PRECISION < 0 ?
		-(flag->PRECISION) : flag->PRECISION;
	flag->PRECISION == 0 && flag->V_P == 1 && nb == 0 ? nb_space += 1 : 0;
	i += apply(nb, nb_space, flag, nb0);
	return (i);
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
}