/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:06:51 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/13 23:01:23 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		checkbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		if ((base[i] == ' ') || (base[i] == '\t') || (base[i] == '\n')
		|| (base[i] == '\r') || (base[i] == '\v') || (base[i] == '\f'))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		checktabase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		if ((base[i] == ' ') || (base[i] == '\t') || (base[i] == '\n')
				|| (base[i] == '\r') || (base[i] == '\v') || (base[i] == '\f'))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int res;
	int sign;
	int j;

	res = 0;
	sign = 1;
	j = -1;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\r') || (*str == '\v') || (*str == '\f'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (base[++j])
		if (*str == base[j] && checktabase(base))
		{
			res = res * checktabase(base) + j;
			j = -1;
			str++;
		}
	return (sign > 0 ? res : -res);
}
