/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 23:28:59 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/05 14:56:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_convert_adress(void *value)
{
	unsigned long long	nb;
	unsigned long long	div;
	char				c;
	int					i;
	char				*str;

	i = 0;
	nb = (unsigned long long)value;
	if (!(str = malloc(sizeof(char*) * (unbnb(nb)))))
		return (NULL);
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

static int		ft_apply(t_flag *flag, int len)
{
	int i;

	i = 0;
	if (flag->width > 0 && flag->minus == 0)
	{
		flag->width = flag->width - len - 1;
		flag->preci > 0 ? flag->width = flag->width -
		flag->preci - 1 : 0;
		while (i < flag->width + 1)
		{
			write(1, " ", 1);
			i = i + 1;
		}
	}
	return (i);
}

int				ft_adress(va_list args, t_flag *flag)
{
	void		*tmp;
	int			x;
	int			i;

	i = 0;
	x = 0;
	tmp = va_arg(args, void*);
	if (tmp == NULL && flag->preci == 0)
		tmp = "0x";
	else if (!(tmp = ft_strjoin("0x", ft_convert_adress(tmp))))
		return (-1);
	x += ft_apply(flag, ft_strlen(tmp));
	ft_putstr_fd(tmp, 1);
	x += ft_strlen(tmp);
	if (flag->minus > 0)
	{
		while (i++ < flag->width - (int)ft_strlen(tmp)
		&& flag->width > (int)ft_strlen(tmp))
			x += write(1, " ", 1);
	}
	ft_strlen(tmp) > 2 ? free(tmp) : 0;
	return (x);
}
