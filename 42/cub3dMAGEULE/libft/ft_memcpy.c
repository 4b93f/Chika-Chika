/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:07:25 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/14 01:26:58 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*ds;
	unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ds = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (n--)
	{
		ds[i] = source[i];
		i++;
	}
	return (dest);
}
/*
** Copie n bytes de la ZONE MEMOIRE SRC dans la ZONE MEMOIRE de DEST
*/
