/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:51:04 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/09 23:27:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ds;
	unsigned char		*source;

	if (!dest && !src)
		return (NULL);
	ds = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		ds[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (ds + i + 1);
		i++;
	}
	return (NULL);
}
/*
** Copier n octets de la ZONE MEMOIRE de src
** dans la ZONE MEMOIRE de dest
** tant que "c" n'est pas trouvé
*/
