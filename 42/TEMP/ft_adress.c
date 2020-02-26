/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 23:28:59 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/26 03:07:06 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_power(long n, long pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_power(n, pow - 1));
}

char	*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	temp;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	return (str);
}

int		check(int base, long *nb, int *sign, long *len)
{
	if (base < 2 || base > 16)
		return (0);
	if (base != 10 && *nb < 0)
		return (0);
	if (base == 10 && *nb < 0)
	{
		*sign = -1;
		*nb = -(*nb);
	}
	else
		*sign = 1;
	*len = 1;
	return (1);
}

char	*ft_convert_adress(void *value, int base)
{
	long	nb;
	long	len;
	char	*result;
	int		sign;
	int		i;

	nb = (long)value;
	if (!check(base, &nb, &sign, &len))
		return (NULL);
	while (ft_power(base, len) <= nb)
		len++;
	if (!(result = malloc(sizeof(char) * (len + 2))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		result[i] = (base <= 10 || (base > 10 && (nb % base) < 10))
			? (nb % base) + 48 : (nb % base) - 10 + 'a';
		nb /= base;
	}
	result[i] = '\0';
	return (ft_strrev(result));
}

static int	ft_apply(to_list *flag, int len)
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

int		ft_adress(va_list args, to_list *flag)
{
	void		*tmp;
	int			x;
	int			i;

	i = 0;
	x = 0;
	tmp = va_arg(args, void*);
	tmp = ft_strjoin("0x", ft_convert_adress(tmp, 16));
	x += ft_apply(flag, ft_strlen(tmp));
	ft_putstr_fd(tmp, 1);
	i += ft_strlen(tmp);
	if (flag->FLAG_MINUS > 0)
	{
		while (i++ < flag->FLAG_NBR)
			x += write(1, " ", 1);
	}
	return (x + ft_strlen(tmp));
}
