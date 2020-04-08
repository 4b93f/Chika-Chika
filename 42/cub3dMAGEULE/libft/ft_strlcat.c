/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:28:02 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/12 01:38:04 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;
	unsigned char	*ssrc;

	i = 0;
	ssrc = (unsigned char *)src;
	res = 0;
	while (dest[i])
		i++;
	while (ssrc[res])
		res++;
	if (size <= i)
		res = res + size;
	else
		res = res + i;
	j = 0;
	while (ssrc[j] && i + 1 < size)
		dest[i++] = ssrc[j++];
	dest[i] = '\0';
	return (res);
}
/*
** Copie SRC dans DEST tant que size > 0
*/
