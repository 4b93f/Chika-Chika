/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:46:38 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/14 17:22:13 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbnb(long long nb)
{
	int len;

	len = 0;
	if (nb <= 0)
	{
		len++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void apply_zero(va_list args, int *p, int len, int *i, char *str)
{
    int count;
    int tmp;
    tmp = va_arg(args, int);
    count = 0;
    count = len - nbnb(tmp);
    while (count--)
        write(1, "0", 1);
    ft_putstr(tmp);
    FLAG++;
}

void flag_zero(int *i, char *str, va_list args, int *p)
{
    int len;

    len = 0;
    while (str[*i] >= '0' && str[*i] <=  '9')
    {
        if (str[*i] >= '0' && str[*i] <=  '9')
            len = len * 10 + (str[*i] - '0');
        *i = *i + 1;
    }
    apply_zero(args, p, len, i, str);
}