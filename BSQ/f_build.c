/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_build.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relefebv <relefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:06:47 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/20 12:52:29 by relefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/*
char	**ft_build(t_square *bigsquare, char **map, char *code)
{
	int sizestock;
	int cmpt;
	int cmptline;
	int	line;
	int	col;
	int colstock;

	colstock = bigsquare->colpos;
	sizestock = bigsquare->size;
	line = bigsquare->lignepos;
	cmptline = 0;
	while (map[line] && cmptline < sizestock)
	{
		cmpt = 0;
		col = colstock;
		while (map[col] && cmpt < sizestock)
		{
			map[line][col] = code[2];
			col++;
			cmpt++;
		}
		line++;
		cmptline++;
	}
	return (map);
}*/

//	int sizestock;		0
//	int cmpt;			1
//	int cmptline;		2
//	int	line;			3
//	int	col;			4
//	int colstock;		5
char	**ft_build(t_square *bigsquare, char **map, char *code)
{
	int		stock[6];

	stock[5] = bigsquare->colpos;
	stock[0] = bigsquare->size;
	stock[3] = bigsquare->lignepos;
	stock[2] = 0;
	while (map[stock[3]] && stock[2] < stock[0])
	{
		stock[1] = 0;
		stock[4] = stock[5];
		while (map[stock[4]] && stock[1] < stock[0])
		{
			map[stock[3]][stock[4]] = code[2];
			stock[4]++;
			stock[1]++;
		}
		stock[3]++;
		stock[2]++;
	}
	return (map);
}