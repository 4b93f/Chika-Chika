/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:31:45 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/05 15:20:29 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			set_long_long(char c, char *str)
{
	long long i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = '\0';
}

static void			ft_putnbr_base(long long nb, char *base, char *str)
{
	if (nb < 0)
	{
		set_long_long('-', str);
		nb = nb * (-1);
	}
	if (nb < ft_strllen(base))
	{
		set_long_long(base[nb], str);
	}
	else
	{
		ft_putnbr_base(nb / ft_strllen(base), base, str);
		ft_putnbr_base(nb % ft_strllen(base), base, str);
	}
}

static long long	ft_size_putnbr_base(long long nb, char *base)
{
	long long size;

	size = 0;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	if (nb < ft_strllen(base))
		size++;
	else
	{
		size = size + ft_size_putnbr_base(nb / ft_strllen(base), base);
		size = size + ft_size_putnbr_base(nb % ft_strllen(base), base);
	}
	return (size);
}

char				*ft_convert_base(char *nbr, char *base_form, char *base_to)
{
	long long		i;
	char			*str;
	long long		howmany;

	if (checkbase(base_form) == 0 || checkbase(base_to) == 0)
		return (0);
	i = ft_atoll_base(nbr, base_form);
	howmany = ft_size_putnbr_base(i, base_to);
	if (!(str = (char *)malloc(sizeof(char) * (howmany + 1))))
		return (0);
	str[0] = '\0';
	ft_putnbr_base(i, base_to, str);
	free(nbr);
	return (str);
}
