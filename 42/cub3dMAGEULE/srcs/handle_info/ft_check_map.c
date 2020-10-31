/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:47:26 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/31 15:46:05 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_startend(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != '1')
		return (FALSE);
	i = strlen(str) - 1;
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

int		ft_check_space(char **map)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	int z = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
			{
				k = j;
				ft_void_algo(&i, &j, &k, map);
			}
			if (map[i][j] == '0')
			{
				k = j;
				ft_zero_algo(&i, &j, &k, map);
			}
		}
		j = -1;
	}
	return (TRUE);
}
