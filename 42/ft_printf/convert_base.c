/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:31:45 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/06 17:07:44 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long long		checktabase(char *base);
long long		ft_atoi_base(char *str, char *base);
long long		ft_strlen(char *str);

void	set_long_long(char c, char *str)
{
	long long i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = '\0';
}

void	ft_putnbr_base(long long nb, char *base, char *str)
{
	if (nb < 0)
	{
		set_long_long('-', str);
		nb = nb * (-1);
	}
	if (nb < ft_strlen(base))
	{
		set_long_long(base[nb], str);
	}
	else
	{
		ft_putnbr_base(nb / ft_strlen(base), base, str);
		ft_putnbr_base(nb % ft_strlen(base), base, str);
	}
}

long long		ft_size_putnbr_base(long long nb, char *base)
{
	long long size;

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
	long long		i;
	char	*str;
	long long		howmany;

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
