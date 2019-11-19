/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:53:21 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 17:12:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_basic_setup(char **map, char *code)
{
	int		line;
	int		col;

	line = 1;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] == code[0])
				map[line][col] = '0';
			else if (map[line][col] == code[1])
				map[line][col] = '1';
			else
				return (NULL);		
			col++;
		}
		line++;
	}
	return (map);
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

int		**ft_map_in_int(char **map)
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
		if (!(mapvalue[i] = (int *)malloc(sizeof(int) * len)))
			return (NULL);
	i = 0;
	while (++i < mapvalue[0][1])
	{
		j = -1;
		while (++j < len)
			mapvalue[i][j] = map[i][j] - 48;
	}
	return (mapvalue);
}

int		**ft_map_setup_main(char **map, char *code)
{
	int i;
	int	**mapvalue;

	i = 0;
	printf("test\n");
	if((map = ft_basic_setup(map, code)) == NULL)
		return (0);
	write(1, "\n", 1);
	if ((mapvalue = ft_map_in_int(map)) == NULL)
		return (0);
	// TO DO FREE **MAP NO MORE USE
	int line = 0;
	int col;
	mapvalue = ft_first_colnline(mapvalue);
	mapvalue = ft_map_setup(mapvalue);
	while (++line < mapvalue[0][1])
	{
		col = -1;
		while (++col < mapvalue[0][0])
			printf("%d ", mapvalue[line][col]);
		printf("\n");
	}
	return (mapvalue);
}