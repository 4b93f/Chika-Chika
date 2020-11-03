/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_caps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:18:10 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/05 14:57:12 by chly-huc         ###   ########.fr       */
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

static int		apply(char *str, int *nb_space, t_flag *flag, int nb0)
{
	int i;

	i = 0;
	if ((flag->v_p == 1 && flag->preci == 0 &&
	flag->minus == 0 && !ft_strcmp(str, "0")))
		*nb_space += 1;
	if (flag->minus == 0)
		while (*nb_space > 0)
		{
			i += write(1, " ", 1);
			*nb_space -= 1;
		}
	while (nb0-- > 0)
		i += write(1, "0", 1);
	if (!(flag->v_p == 1 && flag->preci == 0 && !strcmp(str, "0")))
		i += write(1, str, ft_strlen(str));
	else
		*nb_space += 1;
	if (flag->minus > 0)
		while (*nb_space > 0)
		{
			i += write(1, " ", 1);
			*nb_space -= 1;
		}
	return (i);
}

int				ft_hexa_caps(va_list args, t_flag *flag, int i)
{
	int			to_print;
	int			nb_space;
	char		*str;
	int			nb0;

	nb_space = 0;
	if (!(str = ft_itoll(va_arg(args, unsigned int))))
		return (-1);
	if (!(str = ft_convert_base(str, NUMBER, BASE2)))
		return (-1);
	str = !str ? "(null)" : str;
	to_print = ft_strlen(str);
	nb0 = ft_check(&nb_space, flag, to_print);
	specific_parameters(flag, &nb0, &nb_space, &to_print);
	i += apply(str, &nb_space, flag, nb0);
	free(str);
	return (i);
}
