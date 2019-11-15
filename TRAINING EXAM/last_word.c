/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:30:18 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/14 21:05:21 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    char str[] = " oui bonosir la famille ";
    while(str[i])
        i++;
    if (str[i - 1] == ' ')
        i = i - 2;
    while (!(str[i] == ' '))
    {
        i--;
    }
    i++;
    while(str[i] != ' ')
    {
        ft_putchar(str[i]);
        i++;
    }
}            
