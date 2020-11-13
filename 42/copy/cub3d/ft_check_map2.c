/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:49:00 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/13 18:50:02 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_void_algo(int *i, int *j, int *k, char **map)
{
	*k = *j;
	while (*k > 0 && map[*i][*k] == ' ')
		*k = *k - 1;
	if (map[*i][*k] != '1' && *k != 0)
		return (0);
	*k = *j;
	while (map[*i][*k] && map[*i][*k] == ' ')
		*k = *k + 1;
	if (map[*i][*k] != '1' && map[*i][*k])
		return (0);
	*k = *i;
	while (*k > 0 && map[*k][*j] == ' ')
		*k = *k - 1;
	if (map[*k][*j] && map[*k][*j] != '1' && *k != 0 && (map[*k]
	<= (map[*k - 1])))
		return (0);
	*k = *i;
	while (map[*k] != NULL && map[*k][*j] == ' ')
		*k = *k + 1;
	if (map[*k][*j] && map[*k] != NULL && map[*k][*j] != '1' && (map[*k]
	<= (map[*k + 1])))
		return (0);
	return (1);
}

int	ft_zero_algo(int *i, int *j, int *k, char **map)
{
	while (*k > 0 && map[*i][*k] != '1')
		*k = *k - 1;
	if (map[*i][*k] != '1' && *k != 0)
		return (0);
	*k = *j;
	while (map[*i][*k] && map[*i][*k] != '1')
		*k = *k + 1;
	if (map[*i][*k] != '1' && map[*i - 1][*k] && map[*i + 1][*k])
		return (0);
	*k = *i;
	while (*k > 0 && map[*k][*j] != '1')
	{
		if (map[*k][*j] == ' ')
			return (0);
		*k = *k - 1;
	}
	*k = *i;
	while (map[*k] && *k > 0 && map[*k][*j] != '1')
	{
		if (map[*k][*j] == ' ')
			return (0);
		*k = *k + 1;
	}
	return (!map[*k] ? 0 : 1);
}
