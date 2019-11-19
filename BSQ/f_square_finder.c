#include "bsq.h"

t_square	*test_bigger(int **map, int line, int col, t_square *bigsquare)
{
	int		algo;
	int		tsize;

	algo = 0;
	tsize = bigsquare->size;
	if (col + bigsquare->size >= map[0][0] || line + bigsquare->size >= map[0][1])
		return (NULL);
	algo = map[line][col] + map[line + tsize][col + tsize];
	algo = algo - (map[line][col + tsize] + map[line + tsize][col]);
	if (algo > 0)
		return (NULL);
	return (bigsquare);
}

t_square	*ft_is_it_bigger(int **map, int line, int col, t_square *bigsquare)
{
	if (col + bigsquare->size >= map[0][0] || line + bigsquare->size >= map[0][1])
		return (bigsquare);
	if (map[1][0] == 1)
		return(bigsquare);
	if (col > 0)
		if (map[line][col - 1] < map[line][col])
			return (bigsquare);
	if (line > 1)
		if (map[line - 1][col] < map[line][col])
			return (bigsquare);
	while (test_bigger(map, line, col, bigsquare))
	{
		bigsquare->colpos = col;
		bigsquare->lignepos = line;
		bigsquare->size = bigsquare->size + 1;
	}	
	return (bigsquare);
}

t_square	*square_finder(int **map)
{
	int			line;
	int			col;
	t_square	*bigsquare;
	t_square	square;

	square.colpos = 0;
	square.lignepos = 1;
	square.size = 0;
	bigsquare = &square;
	line = 0;
	while (++line <= map[0][0])
	{
		col = -1;
		while (++col < map[0][0])
			bigsquare = ft_is_it_bigger(map, line, col, bigsquare);
	}
	return (bigsquare);
}