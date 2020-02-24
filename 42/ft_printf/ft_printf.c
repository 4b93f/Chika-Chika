/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:39:07 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/10 16:42:24 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_init_struct(to_list *flag)
{
	flag->FLAG_ZERO = 0;
	flag->FLAG_MINUS = 0;
	flag->FLAG_DOT = 0;
	flag->FLAG_STARS = 0;
	flag->FLAG_NBR = 0;
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	int		nbarg;
	int		i;
	to_list *flag;
	my_struct *index;

	i = 0;
	flag = malloc(sizeof(to_list));
	index = malloc(sizeof(my_struct));
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
	int i = 500000;
	char str[] = "CA";
	char c = 'X';
	char const *p = "hello";

	printf("%90u\n", i);
	ft_printf("%90u", i);
}
