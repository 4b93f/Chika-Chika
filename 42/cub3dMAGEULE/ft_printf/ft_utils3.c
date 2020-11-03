/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:51:28 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/05 14:26:16 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_init_struct(t_flag *flag)
{
	flag->zero = 0;
	flag->minus = 0;
	flag->dot = 0;
	flag->stars = 0;
	flag->width = 0;
	flag->preci = -1;
	flag->v_p = 0;
	flag->preci_neg = 0;
	flag->error = 0;
	return (1);
}

int				mini_atoi(char *str, int *i)
{
	int res;

	res = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
		*i = *i + 1;
		if (res < 0)
			return (0);
	}
	return (res);
}

int				ft_width_calc(char *str, int *i, va_list args)
{
	int res;

	res = 0;
	if ((res = mini_atoi(str, i)) >= 0)
	{
		if (str[*i] == '*')
		{
			*i = *i + 1;
			return (va_arg(args, int));
		}
		return (res);
	}
	return (0);
}

long long		ft_strllen(char *str)
{
	long long		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			specific_parameters(t_flag *flag, int *nb0,
int *nb_space, int *to_print)
{
	if (flag->zero > 0 && flag->preci < 0)
	{
		*nb0 = flag->width - *to_print;
		*nb_space = 0;
		flag->preci = flag->preci < 0 ?
			-(flag->preci) : flag->preci;
		if (flag->minus > 0)
		{
			*nb_space = *nb0;
			*nb0 = 0;
		}
	}
	return ;
}
