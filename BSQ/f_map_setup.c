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
		col++;
	}
	return (map);
}

char	**ft_first_colnline(char **map)
{
	int		line;
	int		col;

	line = 1;
	while (map[++line])
		map[line][0] = map[line - 1][0] + map[line][0];
	col = 0;
	while (map[1][++col])
		map[1][col] = map[1][col - 1] + map[1][col];
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
			map[line][col] = map[line][col] + map[line][col - 1] + map[line - 1][col] - map[line - 1][col - 1] - 144;
	}
	return (map);
}

char	**ft_map_setup_main(char **map, char *code)
{
	if((map = ft_basic_setup(map, code)) == NULL)
		return (NULL);
	map = ft_first_colnline(map);
	map = ft_map_setup(map);
	return (map);
}