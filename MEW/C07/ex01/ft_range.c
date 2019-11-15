/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 02:08:04 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/14 00:15:25 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *taille;
	int i;
	int size;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		taille = 0;
		return (taille);
	}
	if (!(taille = malloc(sizeof(int) * size)))
		return (0);
	while (i < size)
	{
		taille[i] = min;
		min++;
		i++;
	}
	return (taille);
}
