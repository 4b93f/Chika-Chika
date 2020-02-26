/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:15:37 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/26 07:02:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_apply(to_list *flag, int len)
{
	int i;

	i = 0;
	if (flag->PRECISION < 0)
		flag->FLAG_NBR -= flag->FLAG_MINUS > 0 ? len - 1 : len;
	if (flag->FLAG_NBR > 0 && flag->FLAG_MINUS == 0)
	{
		flag->FLAG_NBR = flag->PRECISION > 0 ? flag->FLAG_NBR -
		flag->PRECISION : flag->FLAG_NBR;
		while (i < flag->FLAG_NBR)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i);
}

int		ft_string(va_list args, to_list *flag)
{
	char		*tmp;
	int			i;
	int			len;
	int			x;

	i = 0;
	x = 0;
	tmp = va_arg(args, char*);
	tmp = !tmp ? "(null)" : tmp;
	len = ft_strlen(tmp);
	if (flag->FLAG_NBR <= len && flag->PRECISION < 0)
	{
		ft_putstr_fd(tmp, 1);
		return (len);
	}
	flag->PRECISION > len ? flag->PRECISION = len : 0;
	x = ft_apply(flag, len);
	if (flag->PRECISION == 0)
		return (flag->FLAG_NBR);
	flag->PRECISION > 0 ? write(1, tmp, flag->PRECISION) : write(1, tmp, len);
	if (flag->FLAG_MINUS > 0)
	{
		flag->FLAG_NBR = flag->PRECISION > 0 ? flag->FLAG_NBR -
		flag->PRECISION : flag->FLAG_NBR - 1;
		while (i < flag->FLAG_NBR)
		{
			x += write(1, " ", 1);
			i++;
		}
	}
	return (flag->PRECISION > 0 ? x + flag->PRECISION : x + len);
}
