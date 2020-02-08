/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:42:45 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/08 20:51:20 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unsigned_int(char *str, va_list ap, to_list *flag)
{
    int i = 0;
   unsigned long long y;

    i = va_arg(ap, int);
    if (i < 0)
    {
        y = (unsigned int)i;
		apply_flag(str, flag, y);
        puts(ft_u_itoa(y));
    }
    else
    {
        apply_flag(str, flag, i);
		puts(ft_u_itoa(i));
    }
    return(1);
}
