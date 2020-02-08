/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 07:33:24 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/08 17:16:16 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *str, to_list *flag, va_list ap)
{
	char *s1;

	s1 = va_arg(ap, char*);
	apply_flag1(str, flag, s1);
	puts(s1);
	return ;
}
