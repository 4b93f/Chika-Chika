/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:52:40 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/15 15:31:03 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	wdmatch(char *s1, char *s2)
{
	int len;
	int i;

    len = 0;
    i = 0;
	while(s1[len])
		++len;
	while (*s2 && i < len)
        if (*s2++ == s1[i])
            i++;
	if (i == len)
		write(1, s1, len);
}

int main(int argc, char **argv)
{
    char s1[] = "faya"; 
    char s2[] = "fgvvfdxcacpolhyghbreda";
    wdmatch(s1, s2);
    return(0);
}