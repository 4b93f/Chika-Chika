/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:55:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/06 16:10:38 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexa_nocaps(char *str, to_list *flag, va_list ap)
{
    char *nbr;
    nbr = ft_itoa(va_arg(ap, int));
    nbr = ft_convert_base(nbr, "0123456789", BASE1);
    apply_flag1(str, flag, nbr);
    printf("%s", nbr);
    return (1);
}

int ft_hexa_caps(char *str, to_list *flag, va_list ap)
{
    char *nbr;

    nbr = ft_itoa(va_arg(ap, int));
    nbr = ft_convert_base(nbr, "0123456789", BASE2);
    apply_flag1(str, flag, nbr);
    printf("%s", nbr);
    return (1);
}
