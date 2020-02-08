/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:34:36 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/08 20:24:32 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_integer(char *str, va_list ap, to_list *flag)
{
	char *buf;
	char *tmp;
	int i;
	i = va_arg(ap, int);
	buf = ft_itoa(i);
	apply_flag(str, flag, i);
	if (i < 0)
		printf("%s\n", (buf + 1));
	else
		printf("%s\n", (buf));
	return (1);
}
