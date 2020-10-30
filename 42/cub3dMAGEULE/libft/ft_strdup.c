/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:04:16 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/30 17:52:10 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*source;
	int		i;

	source = (char *)s;
	if (!((dest = (char *)malloc(sizeof(char) * (ft_strlen(source) + 1)))))
		return (0);
	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
** Créer un chaine de caractère avec malloc
*/
