/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:24:18 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/30 18:32:53 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
** retourne une chaine de caractères issue de la chaine ’s’.
** Cette nouvelle chaine commence à l’index ’start’ et
** a pour taille maximale ’len’
*/
