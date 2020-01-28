/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:24:12 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/25 09:33:53 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int		i;
	char	*sstr;

	i = 0;
	sstr = (char *)str;
	if (!sstr)
		return (0);
	while (sstr[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*source;
	int		i;

	source = (char *)src;
	if (!src)
		return (0);
	if (!((dest = (char *)malloc(sizeof(char) * (ft_strlen(source) + 1)))))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd((char*)s, 1);
}

void			ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	return ;
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

static char		*ft_strcatplus(char *dest, char *src, int start)
{
	int j;
	int i;

	i = start;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char			*ft_charjoin(char const *s1, char const s2)
{
	char	*tab;
	char	*ss1;
	int		i;
	int		len_malloc;

	ss1 = (char *)s1;
	len_malloc = ft_strlen(ss1) + 1;
	if (!(tab = malloc(sizeof(char) * len_malloc)))
		return (NULL);
	i = 0;
	while (ss1 && i < len_malloc && ss1[i])
	{
		tab[i] = ss1[i];
		i++;
	}
	tab[i++] = s2;
	tab[i] = 0;
	return (tab);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*tab;
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				i;
	int				len_malloc;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	len_malloc = ft_strlen((char *)ss1) + ft_strlen((char *)ss2) + 1;
	if (!(tab = malloc(sizeof(char) * len_malloc)))
		return (NULL);
	i = 0;
	while (ss1 && ss1[i])
	{
		tab[i] = ss1[i];
		i++;
	}
	tab = ft_strcatplus(tab, (char*)ss2, i);
	return (tab);
}

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	int				size;

	i = 9;
	str = (unsigned char *)s;
	size = ft_strlen((char*)str);
	while (size != 0)
	{
		if (str[size] != c)
			size--;
		else
			return ((char*)str + size);
	}
	if (str[size] == c)
		return ((char*)&str[i]);
	return (NULL);
}
