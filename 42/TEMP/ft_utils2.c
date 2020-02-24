/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:49:55 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 07:23:25 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_adress(void const *p)
{
	unsigned long	adress;
	char			*base;
	char			*fin;
	int				i;

	if (!(fin = malloc(sizeof(char*) * 11)))
		return (NULL);
	adress = (unsigned long)p;

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}
