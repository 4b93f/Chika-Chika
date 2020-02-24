/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 23:28:59 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 08:30:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_apply(va_list args, to_list *flag, int len)
{
	int i;

	i = 0;
	if (flag->FLAG_NBR > 0 && flag->FLAG_MINUS == 0)
	{
		flag->PRECISION == 0 ? flag->FLAG_NBR = flag->FLAG_NBR - 1 : 0;
		flag->PRECISION > 0 ? flag->FLAG_NBR = flag->FLAG_NBR -
		flag->PRECISION - 1 : 0;
		while (i < flag->FLAG_NBR + 1)
		{
			write(1, " ", 1);
			i = i + 1;
		}
	}
	return (i);
}

int		ft_adress(char *str, va_list args, to_list *flag)
{
	char		*tmp;
	int			i;
	int			len;
	int 		x;

	i = 0;
	tmp = va_arg(args, char*);
	tmp = ft_strjoin("0x", ft_convert_adress(tmp));
	tmp = !tmp ? "(null)" : tmp;
	len = ft_strlen(tmp);
	len < flag->PRECISION || flag->PRECISION < 0 ? flag->PRECISION = len : 0;
	x = ft_apply(args, flag, len);
	flag->PRECISION > 0 ? write(1, tmp, flag->PRECISION) : write(1, tmp, len);
	if (flag->FLAG_MINUS > 0)
	{
		flag->FLAG_NBR = flag->FLAG_NBR - flag->PRECISION + 1;
		while (i++ < flag->FLAG_NBR - 1)
			write(1, " ", 1);
	}
	return (x + flag->PRECISION);
}
