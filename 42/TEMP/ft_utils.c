/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:14:06 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 07:26:02 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int		nbnb(long long nb)
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
	long long i;
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

static unsigned int		unbnb(unsigned int nb)
{
	unsigned int len;

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
