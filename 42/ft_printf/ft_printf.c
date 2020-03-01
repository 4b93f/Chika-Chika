/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:05:23 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/01 10:00:20 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		error(to_list *flag)
{
	ft_init_struct(flag);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	to_list		*flag;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (!(flag = malloc(sizeof(to_list))))
		return (-1);
	if (!str || !error(flag))
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_search_all((char*)str, &i, flag, args);
			ret += ft_find_specifier((char*)str, &i, flag, args);
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}

int main()
{
	ft_printf("%-.*XNRO5u%-.4u%-.*uw %*.*u", 1, -23203775, 165208518, -8, -391932317, 3, 9, 243800997);
	printf("%-.*XNRO5u%-.4u%-.*uw %*.*u", 1, -23203775, 165208518, -8, -391932317, 3, 9, 243800997);
	
}