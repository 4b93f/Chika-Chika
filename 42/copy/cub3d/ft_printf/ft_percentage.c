/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:07:26 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/03 16:58:18 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check(t_flag *flag, int *nb0)
{
	int nb_space;

	nb_space = 0;
	if (flag->zero > 0 && flag->minus == 0)
		*nb0 = flag->width - 1;
	else if (flag->width > 0)
		nb_space = flag->width - 1;
	return (nb_space);
}

int		ft_percentage(t_flag *flag)
{
	int i;
	int nb_space;
	int nb0;

	i = 0;
	nb0 = 0;
	nb_space = check(flag, &nb0);
	if (flag->minus == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (flag->minus > 0)
	{
		i += write(1, "%%", 1);
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	}
	else
		i += write(1, "%%", 1);
	return (i);
}
