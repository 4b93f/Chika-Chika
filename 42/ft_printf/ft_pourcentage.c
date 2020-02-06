/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:04:27 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/04 15:03:22 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pourcentage(char *str, va_list ap)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
            i++;
        printf("%c", str[i]);  
        i++;
    }
    return (1);
}