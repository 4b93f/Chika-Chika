/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:39:07 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/08 17:26:23 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void printf_choice(const char *str, va_list va_args, ...)
{
	va_list ap;
	int d;
	char c;
	char *s;
	int i;

	va_start(ap, str);
	while (s[i])
	{
		if (s[i] = '%')
			i++;
		if (s[i] == 'c')
		{
			c = (unsigned char) va_arg(args, int);
			ft_putchar(c);
			i++;
		}

	}
}

int printf(const char *format, ...)
{
		
}
ft_printf("%c\n", x);