/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:05:23 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/29 03:21:44 by chly-huc         ###   ########.fr       */
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
	printf("ret = %d\n\n", ft_printf("%17dJT7l3%2dkefve", -194241564, -2147483647));
	printf("ret = %d\n\n", printf("%17dJT7l3%2dkefve", -194241564, -2147483647));
}