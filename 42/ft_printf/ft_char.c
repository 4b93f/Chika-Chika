/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:31:02 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/08 18:04:57 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_char(char *str, to_list *flag, va_list ap)
{
    char c;
    c = va_arg(ap, int);
	apply_flag(str, flag, c);
    printf("%c", c);
    return (1);
}
