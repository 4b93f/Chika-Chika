/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:39:07 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/06 16:11:50 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_init_struct(to_list *flag)
{
	flag->FLAG_ZERO = 0;
	flag->FLAG_MINUS = 0;
	flag->FLAG_DOT = 0;
	flag->FLAG_STARS = 0;
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	int		nbarg;
	int		i;
	to_list *flag;

	i = 0;
	flag = malloc(sizeof(to_list));
	ft_init_struct(flag);
	nbarg = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			find_flag((char*)str, flag);
			find_format_id((char*)str, ap, flag);
			return (0);
		}
		else
			printf("%c", str[i]);
		i++;
	}
	va_end(ap);
	return (1);
}

int main()
{
	int i = -500000;
	char str[] = "CA";
	char c = 'X';
	char const *p = "hello";

	printf("%010X\n", 8562);
	ft_printf("%010X", 8562);
}