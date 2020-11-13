/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:05:23 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/06 14:14:06 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		ft_errorbis(t_flag *flag)
{
	if (flag->error == 1)
		return (1);
	return (-1);
}

static int		error(t_flag *flag, int *i, int *ret)
{
	*i = 0;
	*ret = 0;
	ft_init_struct(flag);
	return (1);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	t_flag		flag;
	int			i;
	int			ret;

	if (!str || !error(&flag, &i, &ret))
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_search_all((char*)str, &i, &flag, args);
			if (ft_errorbis(&flag) == 1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}
