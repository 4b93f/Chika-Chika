/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:56:09 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/15 15:38:33 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int     dejavu(char c, char *stock)
{
    int     i;
    int     check;
    i = 0;
    check = 0;
    while (stock[i])
    {
        if (stock[i] == c)
            check = 1;
        i++;
    }
    return (check);
}

int main()
{
    int i;
    int j;
    int x;
    
    i = 0;
    j = 0;
        
    char str[] = "zpadinton";
    char str1[] = "paqefwtdjetyiytjneytjoeyjnejeyj";
    x = strlen(str) + strlen(str1) ;
    char stock[x];
    
    while(str[i])
    {
        if (str[i] && !dejavu(str[i], stock))
            stock[j++] = str[i];
        i++;        
    }
    i = 0;
    while (str1[i])
    {
        if (str1[i] && !dejavu(str1[i], stock))
            stock[j++] = str1[i];
        i++;        
    }
    stock[j] = '\0';
    printf("%s\n", stock);
}