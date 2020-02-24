/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:33:48 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 09:04:06 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_specifier(char *str, int *i, to_list *flag, va_list args)
{
	int ret;
	int x;

	x = 0;
	ret = 0;
	str[*i] == 'c' ? ret = (ft_character(str, args, flag)) : 0;
	str[*i] == 's' ? ret = (ft_string(str, args, flag)) : 0;
	str[*i] == 'p' ? ret = (ft_adress(str, args, flag)) : 0;
	str[*i] == 'X' || str[*i] == 'x' ? ret = (ft_hexa(str, args, flag, i)) : 0;
	str[*i] == 'u' ? ret = (ft_uint(args, flag, x)) : 0;
	str[*i] == '%' ? ret = (ft_percentage(str, args, flag, x)) : 0;
	str[*i] == 'd' || str[*i] == 'i' ?
	ret = (ft_integer(str, args, flag, x)) : 0;
	ft_init_struct(flag);
	return (ret);
}
