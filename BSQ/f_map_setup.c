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

	line = 0;
	while (map[++line])
		map[line][0] = map[line - 1][0] + map[line][0];
	col = 0;
	while (map[0][++col])
		map[0][col] = map[0][col - 1] + map[0][col];
	return (map);
}