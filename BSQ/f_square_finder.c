#include "bsq.h"

t_square	test_bigger(int **map, int line, int col, t_square bigsquare)
{

}

t_square	ft_is_it_bigger(int **map, int line, int col, t_square bigsquare)
{

}

t_square	square_finder(int **map)
{
	int			line;
	int			col;
	t_square	bigsquare;

	line = 0;
	while (++line <= map[0][0])
	{
		col = -1;
		while (++col < map[0][0])
			bigsquare = ft_is_it_bigger(map, line, col, bigsquare);
	}
	return (bigsquare);
}