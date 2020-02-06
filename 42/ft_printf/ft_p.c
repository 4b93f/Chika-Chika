/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:01:02 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/05 22:28:19 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_p(char *str, va_list ap)
{
    char *tmp;
    char *s;
    tmp = va_arg(ap, void*);
    s = ft_strjoin("0x", itoa_base(tmp));
    printf("s = {%s}\n", s);
	return (0);
}