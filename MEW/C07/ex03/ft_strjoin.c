/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 03:12:29 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/14 17:08:42 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		malloc_size(int size, char **strs, char *sep)
{
	int i;
	int len_malloc;
	int len_sep;

	i = 0;
	len_malloc = 0;
	len_sep = ft_strlen(sep);
	while (i < size)
	{
		len_sep = len_sep + ft_strlen(strs[i]);
		if (i < size - 1)
			len_malloc += len_sep;
		i++;
	}
	return (len_malloc);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = NULL;
	if (!((dest = malloc(sizeof(char) * ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		res;
	int		i;

	res = malloc_size(size, strs, sep);
	if (size == 0)
	{
		if (!(tab = (char *)malloc(sizeof(char) * 1)))
			return (0);
		tab[0] = '\0';
		return (tab);
	}
	if (!(tab = malloc(sizeof(char) * res + 1)))
		return (0);
	i = 0;
	tab[0] = '\0';
	while (i < size)
	{
		tab = ft_strcat(tab, strs[i]);
		if (i < size - 1)
			tab = ft_strcat(tab, sep);
		i++;
	}
	return (tab);
}
