/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:26:01 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/14 16:38:53 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) != 1)
		return (0);
	if ((argv[2][0] != '+') && (argv[2][0] != '-') && (argv[2][0] != '*')
			&& (argv[2][0] != '/') && (argv[2][0] != '%'))
		return (0);
	return (1);
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign > 0 ? res : -res);
}

int		which(int s1, char *op, int s2)
{
	int (*f[5])(int, int);
	int	res;

	res = 0;
	f[0] = &calcadditionus;
	f[1] = &calcaminus;
	f[2] = &calcadivisionus;
	f[3] = &calcamultiplus;
	f[4] = &calcamodulus;
	if (op[0] == '+')
		res = f[0](s1, s2);
	else if (op[0] == '-')
		res = f[1](s1, s2);
	else if (op[0] == '/')
		res = f[2](s1, s2);
	else if (op[0] == '*')
		res = f[3](s1, s2);
	else if (op[0] == '%')
		res = f[4](s1, s2);
	return (res);
}

int		main(int argc, char **argv)
{
	int s1;
	int s2;
	int res2;

	if (check(argc, argv) == 0)
		return (0);
	s1 = ft_atoi(argv[1]);
	s2 = ft_atoi(argv[3]);
	if (zero(argv[2][0], s2) == 1)
		return (write(1, "Stop : division by zero", 23));
	if (zero(argv[2][0], s2) == 2)
		return (write(1, "Stop : modulo by zero", 21));
	res2 = which(s1, argv[2], s2);
	if ((s1 < 0 || s2 < 0) && (s1 > 0 || s2 > 0))
	{
		res2 = res2 * -1;
		ft_putnbr(-res2);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(res2);
		ft_putchar('\n');
	}
	return (0);
}
