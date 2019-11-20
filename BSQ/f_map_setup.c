/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:53:21 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/20 18:23:38 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_basic_setup(char **map, char *code, int **mapvalue)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	while (++i < mapvalue[0][1])
	{
		j = -1;
		while (++j < len)
		{
			if (map[i][j] == code[0])
				mapvalue[i][j] = 0;
			else if (map[i][j] == code[1])
				mapvalue[i][j] = 1;
			else
				return (NULL);
		}
	}
	return (mapvalue);
}

int		**ft_first_colnline(int **map)
{
	int		line;
	int		col;

	line = 1;
	while (++line < map[0][1])
		map[line][0] = map[line - 1][0] + map[line][0];
	col = 0;
	while (++col < map[0][0])
		map[1][col] = map[1][col - 1] + map[1][col];
	return (map);
}

int		**ft_map_setup(int **map)
{
	int		line;
	int		col;

	line = 1;
	while (++line < map[0][1])
	{
		col = 0;
		while (++col < map[0][0])
			map[line][col] = map[line][col] + map[line][col - 1] + map[line - 1][col] - map[line - 1][col - 1];
	}
	return (map);
}

int		**ft_map_in_int(char **map, char *code)
{
	int		**mapvalue;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(map[1]);
	if (!(mapvalue = (int **)malloc(sizeof(int *) * len + 1)))
		return (NULL);
	if (!(mapvalue[0] = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	i = 0;
	while (map[i])
		i++;
	mapvalue[0][0] = len;
	mapvalue[0][1] = i;
	i = 0;
	while (++i < mapvalue[0][1])
	{
		if (!(mapvalue[i] = (int *)malloc(sizeof(int) * len)))
			return (NULL);
	}
	return (mapvalue);
}

int		**ft_map_setup_main(char **map, char *code)
{
	int	**mapvalue;

	if ((mapvalue = ft_map_in_int(map, code)) == NULL)
		return (0);
	if((mapvalue = ft_basic_setup(map, code, mapvalue)) == NULL)
		return (0);
	mapvalue = ft_first_colnline(mapvalue);
	mapvalue = ft_map_setup(mapvalue);
	return (mapvalue);
}