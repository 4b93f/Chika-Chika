/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:37:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/09 23:02:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ds;
	unsigned char	*source;

	ds = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	if (source > ds)
		while (i < n)
		{
			ds[i] = source[i];
			i++;
		}
	else
		while (n-- != 0)
			ds[n] = source[n];
	return (ds);
}
/*
** copie n octets de la ZONE MEMOIRE de SRC dans la ZONE MEMOIRE de dest
** en faisant attention à leurs tailles
*/
