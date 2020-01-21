/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:36:40 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/14 01:15:02 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*tab;
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				i;
	int				len_malloc;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (!ss1 || !s2)
		return (NULL);
	len_malloc = ft_strlen((char *)ss1) + ft_strlen((char *)ss2);
	if (!ss1 || !ss2)
		return (0);
	if (!(tab = malloc(sizeof(char) * len_malloc)))
		return (NULL);
	i = 0;
	while (ss1[i])
	{
		tab[i] = ss1[i];
		i++;
	}
	tab = ft_strcatplus(tab, (char*)ss2, i);
	return (tab);
}
/*
** Coller deux chaines de caractères ensembles
*/
