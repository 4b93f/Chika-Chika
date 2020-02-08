/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:31:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/08 20:52:48 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_0(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = sign * (-1);
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res < 0)
			return (sign > 0 ? -1 : 0);
	}
	return (sign > 0 ? res : -res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(newstr = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (start--)
		i++;
	while (s[i] && len--)
	{
		newstr[j++] = (char)s[i++];
		newstr[i] = '\0';
	}
	return (newstr);
}

void apply_flag(char *str, to_list *flag, long long nb)
{
    int i;

    i = 0;
	//printf("flag = %d\n", flag->FLAG_NBR);
    if (flag->FLAG_ZERO > 0)
        ft_flag_zero(str, flag, nb);
	else if (flag->FLAG_NBR > 0)
		ft_flag_nbr(str, flag, nb);
    return ;
}

void apply_flag1(char *str, to_list *flag, char *s1)
{
	int i;

    i = 0;
    if (flag->FLAG_ZERO > 0)
        ft_flag_zero1(str, s1);
	else if (flag->FLAG_NBR > 0)
		ft_flag_nbr1(str, flag, s1);
    return ;
}

int ft_index(char *str)
{
    int i;

    i = 0;
    while (str[i] != '%')
        i++;
    i++;
	return (0);
}

int		nbnb(long long nb)
{
	int len;

	len = 0;
	if (nb <= 0)
	{
		len++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void ft_flag_zero(char *str, to_list *flag, long long nb)
{
    int i;
    int u;
    char *tmp;
    u = 0;
	
    tmp = malloc(sizeof(char*) * ft_strlen(str));
    i = ft_index(str);
    tmp = ft_substr(str, i + 1, strlen(str));
    while (!(i = ft_strrrchr(tmp, FORMAT[u])))
		u++;
	tmp[i] = 0;
    i = ft_atoi_0(tmp);
    i = i - nbnb(nb);
	if (nb < 0)
		write(1, "-", 1);
    while (i-- > 0)
        write(1, "0", 1);
	return ;
}

void ft_flag_zero1(char *s1, char *s2)
{
	int i;
	int u;
	char *tmp;

	u = 0;
	if (!(tmp = malloc(sizeof(char*) * strlen(s1))))
		return ;
	i = ft_index(s1);
	tmp = ft_substr(s1, i + 1, strlen(s1));
	while (!(i = ft_strrrchr(tmp, FORMAT[u])))
	{
		u++;
	}
	tmp[i] = 0;
	i = ft_atoi_0(tmp);
	i = i - strlen(s2);
	while (i-- > 0)
        printf("0");
	return ;
}

void ft_flag_nbr(char *s1, to_list *flag, long long nb)
{
	int i;

    int u;
    char *tmp;
    u = 0;

    tmp = malloc(sizeof(char*) * ft_strlen(s1));
    i = ft_index(s1);
    tmp = ft_substr(s1, i + 1, strlen(s1));
    while (!(i = ft_strrrchr(tmp, FORMAT[u])))
		u++;
	tmp[i] = 0;
    i = ft_atoi_0(tmp);
    i = i - nbnb(nb);
	if (nbnb(nb) == 2)
		write(1, " ", 1);
    while (i-- > 0)
        write(1, " ", 1);
	if (nb < 0)
		write(1, "-", 1);
	return ;
}

void ft_flag_nbr1(char *s1, to_list *flag, char *s2)
{
	int i;
	int u;
	char *tmp;

	u = 0;
	if (!(tmp = malloc(sizeof(char*) * strlen(s1))))
		return ;
	i = ft_index(s1);
	tmp = ft_substr(s1, i + 1, strlen(s1));
	while (!(i = ft_strrrchr(tmp, FORMAT[u])))
	{
		u++;
	}
	tmp[i] = 0;
	i = ft_atoi_0(tmp);
	i = i - strlen(s2);
	while (i-- > 0)
        printf(" ");
	return ;
}
