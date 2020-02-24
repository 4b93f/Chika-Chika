/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:05:56 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/14 19:14:50 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int find_specifier(char *str, to_list *flag)
{
    str[*i] == 'd' || str[*i] == 'i' ? 
    return (FALSE);
}

void ft_flag(char *str, int *i, to_list *flag)
{
    *i = *i + 1;
    str[*i] == '0' ? flag->FLAG_ZERO = 1 : 0;
    str[*i] == '-' ? flag->FLAG_MINUS = 1 : 0;
}

void ft_parsing(char *str, int *i, to_list *flag)
{
    int y;
    
    y = i;
    while (!(no_format(y, flag)))
    {
        ft_flag(str, i, flag);
        y++;
    }
    
}

int no_format(char c, to_list *flag)
{
    int i;
    int y;

    i = 0;
    y = 0;
    
    while (FORMAT[y])
    {
        if (c == FORMAT[y])
            return (TRUE);
        y++;
    }
    return (FALSE);
}
