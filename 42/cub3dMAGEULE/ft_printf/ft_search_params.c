/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:28:57 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/06 14:16:54 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_and_preci(t_flag *flag, va_list args, char *str, int i)
{
	flag->width += ft_width_calc(str, &i, args);
	if (str[i] == '.')
	{
		i = i + 1;
		flag->preci = ft_width_calc(str, &i, args);
		flag->v_p = 1;
	}
	return (i);
}

int		ft_search_all(char *str, int *i, t_flag *flag, va_list args)
{
	int ret;

	ret = 0;
	*i = *i + 1;
	while (str[*i] == '-' || str[*i] == '0')
	{
		str[*i] == '0' ? flag->zero += 1 : 0;
		str[*i] == '-' ? flag->minus += 1 : 0;
		*i = *i + 1;
	}
	*i = width_and_preci(flag, args, str, *i);
	if (flag->width < 0)
	{
		flag->minus += 1;
		flag->width *= -1;
		flag->preci_neg = 1;
	}
	ret = ft_find_specifier((char*)str, i, flag, args);
	ft_init_struct(flag);
	ret == -1 ? flag->error = 1 : 0;
	return (ret);
}
