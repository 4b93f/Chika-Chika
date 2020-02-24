/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:51:15 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/13 15:44:23 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void apply_minus(va_list args, int *p, int len)
{
    int count;
    int tmp;
    tmp = va_arg(args, int);
}

void flag_minus(int *i, char *str, va_list args, int *p)
{
    int len;

    len = 0;
    while (str[*i] <= '0' && str[*i] >= '9')
        *i = *i + 1;
    apply_minus(args, p, len);
}