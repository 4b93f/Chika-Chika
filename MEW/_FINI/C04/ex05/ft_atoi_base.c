/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:51:49 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/12 21:18:01 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		checktabase(char *base)
{
	int		i;
	int		j;

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

int		ft_atoi_base(char *str, char *base)
{
	int res;
	int sign;
	int j;

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
		if (*str == base[j] && checktabase(base))
		{
			res = res * checktabase(base) + j;
			j = -1;
			str++;
		}
	return (sign > 0 ? res : -res);
}

int main()
{
	printf("%d\n", ft_atoi_base("  -f6","0123456789abcdef"));
}