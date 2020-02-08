/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_format_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:05:53 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/08 18:38:02 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_format_id(char *str, va_list ap, to_list *flag)
{
	int i;

	i = 0;
	while (str[i] != '%')
		i++;
	i++;
	while (str[i])
	{
		if (str[i] == 's')
			ft_string(str, flag, ap);
		else if ((str[i] == 'd') || (str[i] == 'i'))
			ft_integer(str, ap, flag);
		else if (str[i] == 'c')
			ft_char(str, flag, ap);
		else if (str[i] == 'u')
			ft_unsigned_int(str, ap, flag);
		else if (str[i] == '%')
			ft_pourcentage(str, ap);
		else if (str[i] == 'p')
			ft_p(str, ap);
		else if (str[i] == 'X' || str[i] == 'x')
			(str[i] == 'X' ? ft_hexa_caps(str, flag, ap) : ft_hexa_nocaps(str, flag, ap));
		i++;
	}
	return (1);
}
