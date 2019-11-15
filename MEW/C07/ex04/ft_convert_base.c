/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:00:50 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/14 17:08:48 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		checktabase(char *base);
int		ft_atoi_base(char *str, char *base);
int		checkbase(char *base);
int		ft_strlen(char *str);

void	ft_putcharv2(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = '\0';
}

void	ft_putnbr_base(int nb, char *base, char *str)
{
	if (nb < 0)
	{
		ft_putcharv2('-', str);
		nb = nb * (-1);
	}
	if (nb < ft_strlen(base))
	{
		ft_putcharv2(base[nb], str);
	}
	else
	{
		ft_putnbr_base(nb / ft_strlen(base), base, str);
		ft_putnbr_base(nb % ft_strlen(base), base, str);
	}
}

int		ft_size_putnbr_base(int nb, char *base)
{
	int size;

	size = 0;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	if (nb < ft_strlen(base))
		size++;
	else
	{
		size = size + ft_size_putnbr_base(nb / ft_strlen(base), base);
		size = size + ft_size_putnbr_base(nb % ft_strlen(base), base);
	}
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_form, char *base_to)
{
	int		i;
	char	*str;
	int		howmany;

	if (checktabase(base_form) == 0 || checktabase(base_to) == 0)
		return (0);
	i = ft_atoi_base(nbr, base_form);
	howmany = ft_size_putnbr_base(i, base_to);
	if (!(str = (char *)malloc(sizeof(char) * (howmany + 1))))
		return (0);
	str[0] = '\0';
	ft_putnbr_base(i, base_to, str);
	return (str);
}
