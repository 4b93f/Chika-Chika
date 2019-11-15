/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:30:10 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/14 15:50:44 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*map;

	i = 0;
	if (!(map = malloc(sizeof(char) * length + 1)))
		return (0);
	while (i < length)
	{
		map[i] = (*f)(tab[i]);
	}
	return (map);
}
