/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:04:27 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/10 16:29:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pourcentage(char *str, to_list *flag, va_list ap)
{
    int i;
    char *tmp;
    
    i = 0;
    apply_p();
    return (1);
}

void apply_p(char *str, to_list *flag)
{
    int i;
    char *tmp;

    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
            i++;
        tmp = str + ft_index(str + i);
        printf("%c", str[i]);
        i++;
    }
}