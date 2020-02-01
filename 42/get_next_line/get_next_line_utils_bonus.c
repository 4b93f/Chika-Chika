/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:24:12 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/01 00:40:54 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_error(int fd, char *str)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];

	i = 0;
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src)
		return (0);
	if (!((dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1))))
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!(tab = malloc(sizeof(char) * ft_strlen((char*)s1)
					+ ft_strlen((char*)s2) + 1)))
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[++j])
		tab[j + i] = s2[j];
	tab[i + j] = '\0';
	free(s1);
	return (tab);
}
