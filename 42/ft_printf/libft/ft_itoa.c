/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 03:44:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/14 01:11:37 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbnb(int nb)
{
	int len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = nbnb(n);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0 && (str[0] = '0'))
		return (str);
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[i--] = '0' + ((str[0] == '-') ? -(n % 10) : n % 10);
		n = n / 10;
	}
	return (str);
}
/*
** Changer un nombre à une chaine de caractères
*/
