/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:17:22 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/01 15:15:29 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return(i);
}

char *ft_sttrev(char *str)
{
    int i;
    int size;
    int milieu;
    int tmp;

    i = 0;
    size = ft_strlen(str);
    milieu = size / 2;
    while (i < milieu)
    {
        tmp = str[i];
        str[i] = str[size - 1];
        str[size - 1] = tmp;
        i++;
        size--;
    }
    return(str);
}

int main()
{
    char str[] = "123456789";
    ft_sttrev(str);
    printf("%s", str);
    return (0);
}