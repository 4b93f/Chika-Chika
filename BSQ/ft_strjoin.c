/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relefebv <relefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:20:01 by relefebv          #+#    #+#             */
/*   Updated: 2019/11/20 15:36:04 by relefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strjoin(char *dest, char *src, int first)
{
	int		newlen;
	char	*joined;
	int		i;
	int		j;

	if (first == 1)
	{
		newlen = ft_strlen(dest) + ft_strlen(src);
		if (!(joined = (char *)malloc(sizeof(char) * (newlen + 1))))
			return (NULL);
		joined[newlen] = '\0';
		i = 0;
		j = 0;
		while (dest[i])
			joined[j++] = dest[i++];
		i = 0;
		while (src[i + first])
			joined[j++] = src[i++];
		free(dest);
		return (joined);
	}
	else if (first == 0)
	{
		newlen = ft_strlen(src);
		if (!(joined = (char *)malloc(sizeof(char) * (newlen + 1))))
			return (NULL);
		joined[newlen] = '\0';
		i = -1;
		while (src[++i])
			joined[i] = src[i];
		return (joined);
	}
	return (NULL);
}
