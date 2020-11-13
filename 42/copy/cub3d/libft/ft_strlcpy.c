/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:09:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/30 16:43:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	int				j;
	unsigned char	*ssrc;

	j = 0;
	ssrc = (unsigned char *)src;
	while (ssrc[j])
		j++;
	if (size == 0)
		return (j);
	i = 0;
	while (ssrc[i] && i < size - 1)
	{
		dest[i] = ssrc[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
/*
** Copie size caractère de SRC dans DEST sans ce soucier
** de la taille de DEST
*/
