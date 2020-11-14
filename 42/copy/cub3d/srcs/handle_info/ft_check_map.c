/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:47:26 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/14 18:38:41 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_startend(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != '1')
		return (FALSE);
	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] == ' ')
		i--;
	if (str[i] != '1')
		return (FALSE);
	return (TRUE);
}

int		ft_updownwall(char *map)
{
	int i;

	i = 0;
	if (ft_check_startend(map) == FALSE)
		return (FALSE);
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		ft_check_char(t_params *params, char *map)
{
	int i;

	i = 0;
	if (ft_check_startend(map) == FALSE)
		return (FALSE);
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
		{
			params->find_pos++;
			params->player_orientation = map[i];
		}
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W'
		|| map[i] == 'E' || map[i] == ' ' || map[i] == '0'
		|| map[i] == '1' || map[i] == '2')
		{
			if (map[i] == '2')
				params->sp->numsprite += 1;
			i++;
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int		ft_check_space(int j, int k, t_params *params, char **map)
{
	int i;

	i = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
			{
				k = j;
				if (!(ft_void_algo(&i, &j, &k, map)))
					quit("WRONG_MAP_FORMAT");
			}
			if (map[i][j] == '0')
			{
				k = j;
				if (!(ft_zero_algo(&i, &j, &k, map)))
					quit("WRONG_MAP_FORMAT");
			}
		}
		j = -1;
	}
	return (TRUE);
}
