/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:33:48 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/29 02:41:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_specifier(char *str, int *i, to_list *flag, va_list args)
{
	int			ret;
	int			x;
	long long	nb;

	x = 0;
	ret = 0;
	nb = 0;
	str[*i] == 'c' ? ret = (ft_character(args, flag)) : 0;
	str[*i] == 's' ? ret = (ft_string(args, flag, x)) : 0;
	str[*i] == 'p' ? ret = (ft_adress(args, flag)) : 0;
	str[*i] == 'x' ? ret = (ft_hexa(args, flag, x)) : 0;
	str[*i] == 'X' ? ret = (ft_hexa_caps(args, flag, x)) : 0;
	str[*i] == 'u' ? ret = (ft_uint(args, flag, x)) : 0;
	str[*i] == '%' ? ret = (ft_percentage(flag, x)) : 0;
	str[*i] == 'd' || str[*i] == 'i' ?
	ret = (ft_integer(args, flag, x, nb)) : 0;
	ft_init_struct(flag);
	return (ret);
}
