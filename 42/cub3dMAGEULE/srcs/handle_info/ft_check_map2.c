/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:49:00 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/31 15:46:09 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_void_algo(int *i, int *j, int *k, char **map)
{
	*k = *j;
	while (*k > 0 && map[*i][*k] == ' ')
		*k = *k - 1;
	if (map[*i][*k] != '1' && *k != 0)
		ft_error(WRONG_MAP_FORMAT);
	*k = *j;
	while (map[*i][*k] && map[*i][*k] == ' ')
		*k = *k + 1;
	if (map[*i][*k] != '1' && map[*i][*k])
		ft_error(WRONG_MAP_FORMAT);
	*k = *i;
	while (*k > 0 && map[*k][*j] == ' ')
		*k = *k - 1;
	if (map[*k][*j] != '1' && *k != 0 && (map[*k] <= (map[*k - 1])))
		ft_error(WRONG_MAP_FORMAT);
	*k = *i;
	while (map[*k] != NULL && map[*k][*j] == ' ')
		*k = *k + 1;
	if (map[*k] != NULL && map[*k][*j] != '1' && (map[*k] <= (map[*k + 1])))
		ft_error(WRONG_MAP_FORMAT);
}

void	ft_zero_algo(int *i, int *j, int *k, char **map)
{
	while (*k > 0 && map[*i][*k] != '1')
		*k = *k - 1;
	if (map[*i][*k] != '1' && *k != 0)
		ft_error(WRONG_MAP_FORMAT);
	*k = *j;
	while (map[*i][*k] && map[*i][*k] != '1')
		*k = *k + 1;
	if (map[*i][*k] != '1' && map[*i - 1][*k] && map[*i + 1][*k])
		ft_error(WRONG_MAP_FORMAT);
	*k = *i;
	while (*k > 0 && map[*k][*j] != '1')
	{
		if (map[*k][*j] == ' ')
			ft_error(WRONG_MAP_FORMAT);
		*k = *k - 1;
	}
	*k = *i;
	while (map[*k] && *k > 0 && map[*k][*j] != '1')
	{
		if (map[*k][*j] == ' ')
			ft_error(WRONG_MAP_FORMAT);
		*k = *k + 1;
	}
	if (!map[*k])
		ft_error(WRONG_MAP_FORMAT);
}
