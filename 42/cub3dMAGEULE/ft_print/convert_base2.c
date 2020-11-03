/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:32:23 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/03 16:56:44 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		checkbase(char *base)
{
	long long		i;
	long long		j;

	i = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		if ((base[i] == ' ') || (base[i] == '\t') || (base[i] == '\n')
				|| (base[i] == '\r') || (base[i] == '\v') || (base[i] == '\f'))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

long long		ft_atoll_base(char *str, char *base)
{
	long long res;
	long long sign;
	long long j;

	res = 0;
	sign = 1;
	j = -1;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\r') || (*str == '\v') || (*str == '\f'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (base[++j])
		if (*str == base[j] && checkbase(base))
		{
			res = res * checkbase(base) + j;
			j = -1;
			str++;
		}
	return (sign > 0 ? res : -res);
}
