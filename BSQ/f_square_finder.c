#include "bsq.h"

t_square	*test_bigger(int **map, int line, int col, t_square *bigsquare)
{
	int		algo;
	int		tsize;
	int		corner[4];  // haut gauche   droite   bas gauche droite

	tsize = bigsquare->size;
	if (col + bigsquare->size + 1 >= map[0][0] || line + bigsquare->size + 1 >= map[0][1])
		return (NULL);
	if (line == 1 && col == 0 && map[tsize + 1][tsize] == 0)
		return(bigsquare);
	else if (line == 1 && col == 0 && map[tsize + 1][tsize] > 0)
		return (NULL);

	
	if (line == 1)
	{
		corner[0] = 0;
		corner[1] = 1;
		corner[2] = map[line + tsize][col];
		corner[3] = map[line + tsize][col + tsize];
	}
	else if (col == 0)
	{
		corner[0] = 0;
		corner[1] = map[line][col + tsize] ;
		corner[2] = 0;
		corner[3] = map[line + tsize][col + tsize];
	}
	if (line > 1 && col > 0)
	{
		corner[0] = map[line][col];
		corner[1] = map[line][col + tsize + 1];
		corner[2] = map[line + tsize + 1][col];
		corner[3] = map[line + tsize + 1][col + tsize + 1];
	}
	printf("\nAAAAA\ncol et line = %d   %d\n", col, line);
	printf("tsize = %d\n", tsize);
	printf("coin haut gauche = %d\n", corner[0]);
	printf("coin haut droit = %d\n", corner[1]);
	printf("coin bas gauche = %d\n", corner[2]);
	printf("coin bas droite = %d\n", corner[3]);
	algo = corner[3] - corner[2] - corner[1] + corner[0];
	printf("algo = %d\n", algo);
	if (algo > 0)
		return (NULL);
	return (bigsquare);
}

t_square	*ft_is_it_bigger(int **map, int line, int col, t_square *bigsquare)
{
	if (col + bigsquare->size >= map[0][0] || line + bigsquare->size >= map[0][1])
		return (bigsquare);
	if (map[1][0] == 1 && line == 1 && col == 0)
		return(bigsquare);
	while (test_bigger(map, line, col, bigsquare))
	{
		if (col != 0)	
			bigsquare->colpos = col + 1;
		else if (col == 0)
			bigsquare->colpos = col;
		if (line != 1 && col != 0)
			bigsquare->lignepos = line + 1;
		else if (line == 1)
			bigsquare->lignepos = line;
		else
			bigsquare->lignepos = line;
		
		bigsquare->size = bigsquare->size + 1;
		printf("Taille = %d\nColonne = %d\nLigne = %d\n", bigsquare->size, bigsquare->colpos, bigsquare->lignepos);
	}	
	return (bigsquare);
}

t_square	*square_finder(int **map)
{
	int			line;
	int			col;
	t_square	*bigsquare;



	int i = 1;
	int j = 0;
	while (i < map[0][1])
	{
		j = 0;
		while (j < map[0][0])
		{
			printf("%d ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}



	if (!(bigsquare = (t_square *)(malloc(sizeof(t_square) * 1))))
		return (NULL);
	bigsquare->colpos = 0;
	bigsquare->lignepos = 1;
	bigsquare->size = 0;
	line = 0;
	while (++line < map[0][1])
	{
		col = -1;
		while (++col < map[0][0])
			bigsquare = ft_is_it_bigger(map, line, col, bigsquare);
	}
	bigsquare->size = bigsquare->size - 1;
	printf("final  size = %d %d %d\n", bigsquare->size, bigsquare->colpos, bigsquare->lignepos);
	return (bigsquare);
}