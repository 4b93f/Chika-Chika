/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:15:37 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/03 17:00:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check(t_flag *flag, int *to_print)
{
	int nb_space;

	nb_space = 0;
	if (flag->preci > 0)
	{
		if (flag->preci < *to_print)
			*to_print = flag->preci;
		if (flag->width > *to_print)
			nb_space = flag->width - *to_print;
	}
	else
		nb_space = flag->width - *to_print;
	if (flag->width > 0 && flag->preci == 0)
		nb_space = flag->width;
	return (nb_space);
}

int				ft_string(va_list args, t_flag *flag, int i)
{
	int			to_print;
	int			nb_space;
	char		*str;

	nb_space = 0;
	str = va_arg(args, char*);
	str = !str ? "(null)" : str;
	to_print = ft_strlen(str);
	nb_space = ft_check(flag, &to_print);
	if (flag->minus == 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	if (!(flag->v_p == 1 && flag->preci == 0))
	{
		write(1, str, to_print);
		i += to_print;
	}
	if (flag->minus > 0)
		while (nb_space-- > 0)
			i += write(1, " ", 1);
	return (i);
}
