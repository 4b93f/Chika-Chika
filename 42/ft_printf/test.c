/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:44:56 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/06 15:23:16 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
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

int ft_index(char *str)
{
    int i;

    i = 0;
    while (str[i] != '%')
        i++;
    i++;
	return (0);
}


void ft_flag_zero1(char *s1, char *s2)
{
	int i;
	int u;
	char *tmp;

	tmp = malloc(sizeof(char*) * strlen(s1));
	i = ft_index(s1);
	tmp = ft_substr(s1, i + 1, strlen(s1));
	while (!(i = ft_strrrchr(tmp, FORMAT[u])))
		u++;
	tmp[i] = 0;
	i = ft_atoi_0(tmp);
	i = i - strlen(s2);
	while (i-- > 0)
        write(1, "0", 1);
	printf("%s", s2);
}
*/
int main()
{
	printf("%-50d", 15);
}