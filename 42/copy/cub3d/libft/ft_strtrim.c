/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:41:19 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/02 20:02:40 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int				start;
	size_t			end;
	unsigned char	*ss1;
	unsigned char	*sset;

	if (!s1 || !set)
		return (NULL);
	ss1 = (unsigned char *)s1;
	sset = (unsigned char *)set;
	end = ft_strlen((char*)ss1) - 1;
	start = 0;
	while (ft_strchr((char*)sset, ss1[start]))
		start++;
	if (start >= (int)ft_strlen((char*)ss1))
		return (ft_strdup(""));
	while (ft_strchr((char*)sset, ss1[end]))
		end--;
	return (ft_substr((char*)ss1, start, end - start + 1));
}

/*
** Coupe le début et la fin d'une chaine de caractères
** si la chaine "SET" s'y trouve
*/
