/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 02:37:35 by chly-huc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/29 02:42:46 by chly-huc         ###   ########.fr       */
=======
/*   Updated: 2020/03/01 08:28:58 by chly-huc         ###   ########.fr       */
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
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
<<<<<<< HEAD
		*nb_space = flag->FLAG_NBR - to_print;
	if (flag->FLAG_NBR > 0 && flag->PRECISION == 0)
		*nb_space = flag->FLAG_NBR;
	return (nb0);
}

static int		apply(char *str, int nb_space, to_list *flag, int nb0)
=======
	{
		*nb_space = flag->FLAG_NBR - to_print;
	}
	return (nb0);
}

static int		apply(char *str, int *nb_space, to_list *flag, int nb0)
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
{
	int i;

	i = 0;
<<<<<<< HEAD
	if (flag->FLAG_MINUS == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (!(flag->V_P == 1 && flag->PRECISION == 0))
		i += write(1, str, ft_strlen(str));
	if (flag->FLAG_MINUS > 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
=======
	if ((flag->V_P == 1 && flag->PRECISION == 0 &&
	flag->FLAG_MINUS == 0 && !strcmp(str, "0")))
		*nb_space += 1;
	if (flag->FLAG_MINUS == 0)
		while (*nb_space > 0)
		{
			i += write(1, " ", 1);
			*nb_space -= 1;
		}
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (!(flag->V_P == 1 && flag->PRECISION == 0 && !strcmp(str, "0")))
		i += write(1, str, ft_strlen(str));
	else
		*nb_space += 1;
	if (flag->FLAG_MINUS > 0)
		while (*nb_space > 0)
		{
			i += write(1, " ", 1);
			*nb_space -= 1;
		}
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
	return (i);
}

int				ft_hexa(va_list args, to_list *flag, int i)
{
	int			to_print;
	int			nb_space;
	char		*str;
	int			nb0;

	nb_space = 0;
	str = ft_itoll(va_arg(args, unsigned long long));
	str = ft_convert_base(str, NUMBER, BASE1);
	str = !str ? "(null)" : str;
	to_print = ft_strlen(str);
	nb0 = ft_check(&nb_space, flag, to_print);
	if (flag->FLAG_ZERO > 0 && flag->PRECISION < 0)
	{
		nb0 = flag->FLAG_NBR - to_print;
		nb_space = 0;
<<<<<<< HEAD
	}
	flag->PRECISION = flag->PRECISION < 0 ?
		-(flag->PRECISION) : flag->PRECISION;
	i += apply(str, nb_space, flag, nb0);
=======
		flag->PRECISION = flag->PRECISION < 0 ?
			-(flag->PRECISION) : flag->PRECISION;
		if (flag->FLAG_MINUS > 0)
		{
			nb_space = nb0;
			nb0 = 0;
		}
	}
	i += apply(str, &nb_space, flag, nb0);
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
	return (i);
}
