/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:42:45 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/05 22:24:51 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unsigned_int(char *str, va_list ap, to_list *flag)
{
    int i = 0;
    unsigned int y;

    i = va_arg(ap, int);
    if (i < 0)
    {
        y = i;
        puts(ft_u_itoa(i));
    }
    else
        ft_integer(str, ap, flag);
    return(1);
}