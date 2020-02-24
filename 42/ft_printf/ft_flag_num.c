/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:23:31 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/14 16:19:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void putspace(int *p, int count)
{
    while (count-- > 0)
        write(1, " ", 1);
}

void apply_num(char *str, va_list args, int *p, int *i, int len)
{
    int count;
    void *tmp;

    tmp = va_arg(args, void *);
    count = 0;
    count = len - nbnb((long long)tmp);
    if (str[*i] == 'd' || str[*i] == 'i')
    {
        putspace(p, count);
        ft_putnbr((int)tmp);
    }
    else if (str[*i] == 'x' || str[*i] == 'X')
    {
        putspace(p, count);
        tmp = ft_itoa((long long)tmp);
        tmp = ft_convert_base(tmp, "0123456789", BASE1);
        ft_putstr(tmp);
        
    }
    else if (str[*i] == 'u')
    {
        putspace(p, count);
        ft_putnbr((int)tmp);
    }
}

void flag_num(int *i, char *str, va_list args, int *p)
{
    int len;

    len = 0;
    while (str[*i] >= '0' && str[*i] <=  '9')
    {
        if (str[*i] >= '0' && str[*i] <=  '9')
            len = len * 10 + (str[*i] - '0');
        *i = *i + 1;
    }
    apply_num(str, args, p, i, len);
}