/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:05:23 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 09:03:23 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	to_list		*flag;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	flag = malloc(sizeof(to_list));
	ft_init_struct(flag);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_search_all((char*)str, &i, flag, args);
			ret += ft_find_specifier((char*)str, &i, flag, args);
		}
		else
		{
			ret += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (ret);
}

int main()
{
	int a = 4512;
	int c = 'z';
	printf("ret = %d\n", ft_printf("OUI = %d\n", a));
}