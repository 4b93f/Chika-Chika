/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:07:58 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/13 14:03:33 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*source;
	int		i;

	source = (char *)s;
	if (!((dest = (char *)malloc(sizeof(char) * (ft_strlen(source) + 1)))))
		return (0);
	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!(tab = malloc(sizeof(char) * ft_strlen((char*)s1)
					+ ft_strlen((char*)s2) + 1)))
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[++j])
		tab[j + i] = s2[j];
	tab[i + j] = '\0';
	return (tab);
}

unsigned int		nbnb1(unsigned int nb)
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

char *itoa_base(void const *p)
{
	unsigned long adress;
	char *base;
	char *fin;
	int i;

    if (!(fin = malloc(sizeof(char*) * 11)))
        return (NULL);	
    adress = (unsigned long) p;

	base = "0123456789abcdef";
	i = 8;
	while ((i >= 8 || adress / 16) > 0)
	{
		fin[i] = base[(adress % 16)];
		adress /= 16;
		i--;
	}
	fin[i] = base[(adress % 16)];
	return (fin);
}

char			*ft_u_itoa(unsigned int n)
{
	unsigned int i;
	char	*str;

	i = nbnb1(n);
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

char			*ft_itoa(long long n)
{
	long long		i;
	char	*str;

	i = nbnb1(n);
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
