/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:14:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/12 13:22:47 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void *ft_realloc(void *ptr, int new_size)
{
	char *new_str;
	int x;

	if (ptr == NULL)
		return (ptr);
	x = sizeof(ptr);
	new_str = malloc(new_size);
	return (new_str);
}
