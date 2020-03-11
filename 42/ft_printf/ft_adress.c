/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 23:28:59 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/01 07:54:42 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_convert_adress(void *value)
{
	unsigned long long nb;
	unsigned long long div;
	char c;
	int i;
	char *str;

	i = 0;
	nb = (unsigned long long)value;
	str = malloc(sizeof(char*) * (unbnb(nb)));
	div = 16;
	while (nb / div && div * 16)
		div *= 16;
	if (!(nb / div))
		div /= 16;
	while (div)
	{
		c = (nb / div < 10) ? nb / div + '0' : nb / div + 'a' - 10;
		str[i] = c;
		i++;
		nb %= div;
		div /= 16;
	}
	str[i] = '\0';
	return (str);
}

static int		ft_apply(to_list *flag, int len)
{
	int i;

	i = 0;
	if (flag->FLAG_NBR > 0 && flag->FLAG_MINUS == 0)
	{
		flag->FLAG_NBR = flag->FLAG_NBR - len - 1;
		flag->PRECISION == 0 ? flag->FLAG_NBR = flag->FLAG_NBR - 1 : 0;
		flag->PRECISION > 0 ? flag->FLAG_NBR = flag->FLAG_NBR -
		flag->PRECISION - 1 : 0;
		while (i < flag->FLAG_NBR + 1)
		{
			write(1, " ", 1);
			i = i + 1;
		}
	}
	return (i);
}

int				ft_adress(va_list args, to_list *flag)
{
	void		*tmp;
	int			x;
	int			i;

	i = 0;
	x = 0;
	tmp = va_arg(args, void*);
	tmp = ft_strjoin("0x", ft_convert_adress(tmp));
	x += ft_apply(flag, ft_strlen(tmp));
	ft_putstr_fd(tmp, 1);
	if (flag->FLAG_MINUS > 0)
	{
		while (i++ < flag->FLAG_NBR - (int)ft_strlen(tmp) && flag->FLAG_NBR > (int)ft_strlen(tmp))
			x += write(1, " ", 1);
	}
	return (x + ft_strlen(tmp));
}
