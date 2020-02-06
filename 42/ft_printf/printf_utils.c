/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:32:43 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/06 15:03:19 by chly-huc         ###   ########.fr       */
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
/*
static int		nbnb(int nb)
{
	int len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
*/

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

void			ft_putnbr_fd(int n, int fd)
{
	long int nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbr + '0', fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static unsigned int		nbnb1(unsigned int nb)
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

static char		*ft_strcat(char *dest, char *src, int start)
{
	int j;
	int i;

	i = start;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*tab;
	unsigned char	*chain_cpy1;
	unsigned char	*chain_cpy2;
	int				i;
	int				len_malloc;

	chain_cpy1 = (unsigned char *)s1;
	chain_cpy2 = (unsigned char *)s2;
	if (!s1)
		return (ft_strdup(s2));
	len_malloc = ft_strlen((char *)chain_cpy1) + ft_strlen((char *)chain_cpy2);
	if (!(tab = malloc(sizeof(char) * len_malloc)))
		return (NULL);
	i = 0;
	while (chain_cpy1[i])
	{
		tab[i] = chain_cpy1[i];
		i++;
	}
	tab = ft_strcat(tab, (char*)chain_cpy2, i);
	return (tab);
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

int	ft_strrrchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	int				size;

	i = 0;
	str = (unsigned char *)s;
	size = strlen((char*)str);
	while (size != 0)
	{
		if (str[size] != c)
			size--;
		else
			return (size);
	}
	if (str[size] == c)
		return (size);
	return (0);
}
