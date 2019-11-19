/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:53:21 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 16:03:39 by chly-huc         ###   ########.fr       */
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

char	**ft_first_colnline(char **map)
{
	int		line;
	int		col;

	line = 1;
	while (map[++line])
		map[line][0] = map[line - 1][0] + map[line][0] - 48;
	col = 0;
	while (map[1][++col])
		map[1][col] = map[1][col - 1] + map[1][col] - 48;
	return (map);
}

char	**ft_map_setup(char **map)
{
	int		line;
	int		col;

	line = 1;
	while (map[++line])
	{
		col = 0;
		while (map[line][++col])
			map[line][col] = map[line][col] + map[line][col - 1] + map[line - 1][col] - map[line - 1][col - 1] - 48;
	}
	return (map);
}

char	**ft_map_setup_main(char **map, char *code)
{
	int i;

	i = 0;
	write(1, "!", 1);
	if((map = ft_basic_setup(map, code)) == NULL)
		return (NULL);
	write(1, "\n", 1);
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	map = ft_first_colnline(map);
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	map = ft_map_setup(map);
	return (map);
}