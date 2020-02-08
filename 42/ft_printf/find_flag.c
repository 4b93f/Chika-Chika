/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:05:56 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/08 20:25:51 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int find_flag(char *str, to_list *flag)
{
    int i;
    int u;
    char *stock;

    i = 0;
    u = 0;
    if (!(stock = malloc(sizeof(char*) * ft_strlen(str))))
        return (0);
    while (str[i] != '%')
        i++;
    while (str[++i])
        stock[u++] = str[i];
    i = 0;
    while (stock[i])
    {
        u = 0;
        while (FLAGS[u])
        {
            if (stock[i] == FLAGS[u])
            {
                ft_flag(stock, flag);
                return (TRUE);
            }
            u++;
        }
        i++;
    }
    return (FALSE);
}

void ft_flag(char *str, to_list *flag)
{
    int i;
    int u;
    int y;

    i = 0;
    u = 0;
    y = 0;
    while (str[i] == '%')
        i++;
    if (str[i] == '0')
        flag->FLAG_ZERO += 1;
    else if (str[i] == '-')
        flag->FLAG_MINUS++;
    else if (str[i] == '.')
        flag->FLAG_DOT++;
    else if (str[i] == '*')
        flag->FLAG_STARS++;
	else if (ft_isdigit(str[i]))
		flag->FLAG_NBR += 1;
}

int no_format(char *str, to_list *flag)
{
    int i;
    int y;

    i = 0;

    char s[] = "cspdiuxX%%";
    while (str[i])
    {
        y = 0;
        while (s[y])
        {
            if (str[i] == s[y])
                return (FALSE);
            y++;
        }
        i++;
    }
    return (TRUE);
}
