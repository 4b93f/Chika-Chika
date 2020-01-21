/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:17:09 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/09 23:08:33 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] != c)
			i++;
		else
			return (str + i);
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
/*
** Cherche le caractére "c" dans la chaine caractére S
*/
