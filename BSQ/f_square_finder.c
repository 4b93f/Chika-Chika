#include "bsq.h"

t_square	test_bigger(char **map, int line, int col, t_square bigsquare)
{

}

t_square	ft_is_it_bigger(char **map, int line, int col, t_square bigsquare)
{
	
}

t_square	square_finder(char **map)
{
	int			line;
	int			col;
	t_square	bigsquare;

	line = 0;
	while (map[++line])
	{
		col = -1;
		while (map[line][++col])
			bigsquare = ft_is_it_bigger(map, line, col, bigsquare);
	}
	return (bigsquare);
}