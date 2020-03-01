/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:07:26 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/01 02:50:33 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int check(to_list *flag, int *nb0)
{
	int nb_space;

	nb_space = 0;
	if (flag->FLAG_ZERO > 0 && flag->FLAG_MINUS == 0)
		*nb0 = flag->FLAG_NBR - 1;
	else if (flag->FLAG_NBR > 0)
		nb_space = flag->FLAG_NBR - 1;
	return (nb_space);
}

int		ft_percentage(to_list *flag)
{
	int i;
	int nb_space;
	int nb0;

	i = 0;
	nb0 = 0;
	nb_space = check(flag, &nb0);
	//printf("flag->NBR = %d\n", flag->FLAG_NBR);
	//printf("flaag->PRECI = %d\n", flag->PRECISION);
	if (flag->FLAG_MINUS == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (flag->FLAG_MINUS > 0)
	{
		i += write(1, "%%", 1);
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	}
	else
		i += write(1, "%%", 1);
	return (i);
}
