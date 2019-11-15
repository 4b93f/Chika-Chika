/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:54:11 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/01 10:59:34 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s1[i] || s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main()
{
    char s1[] = "19 c'est bien";
    char s2[] = "42 c'est mieux";
    printf("%d\n", ft_strcpy(s1, s2));
    return (0);
}