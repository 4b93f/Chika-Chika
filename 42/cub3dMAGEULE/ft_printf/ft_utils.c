/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:14:06 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/05 11:29:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long				nbnb(long long nb)
{
	long long len;

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

char					*ft_itoll(long long n)
{
	long long		i;
	char			*str;

	i = nbnb(n);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0 && (str[0] = '0'))
		return (str);
	while (n != 0)
	{
		str[i--] = '0' + ((str[0] == '-') ? -(n % 10) : n % 10);
		n = n / 10;
	}
	return (str);
}

int						unbnb(unsigned long long nb)
{
	unsigned long long len;

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

char					*ft_u_itoa(unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = unbnb(n);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0 && (str[0] = '0'))
		return (str);
	while (n != 0)
	{
		str[i--] = '0' + ((str[0] == '-') ? -(n % 10) : n % 10);
		n = n / 10;
	}
	return (str);
}

int						ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
