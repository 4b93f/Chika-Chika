/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:36:40 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/28 19:01:17 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcat(char *dest, char *src, int start)
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
	unsigned char	*chain_cpy1;
	unsigned char	*chain_cpy2;
	int				i;
	int				len_malloc;

	chain_cpy1 = (unsigned char *)s1;
	chain_cpy2 = (unsigned char *)s2;
	if (!s1)
		return (ft_strdup(s2));
	len_malloc = ft_strlen((char *)chain_cpy1) + ft_strlen((char *)chain_cpy2);
	if (!(tab = malloc(sizeof(char) * len_malloc)))
		return (NULL);
	i = 0;
	while (chain_cpy1[i])
	{
		tab[i] = chain_cpy1[i];
		i++;
	}
	tab = ft_strcat(tab, (char*)chain_cpy2, i);
	return (tab);
}
/*
** Coller deux chaines de caractères ensembles
*/
