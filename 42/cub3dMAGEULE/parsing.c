/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:29:43 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/12 12:16:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_parsing()
{
	int **tab;
	int i;
	int lenlen;
	int fd;
	char **line;

	fd = open("map.txt", O_RDONLY);
	i = 0;
	
	while (get_next_line(fd, &line) > 0)
	{
		lenlen += get_next_line(fd, &line);
	}
	 
	if (!(tab = malloc(sizeof(int **) * lenlen)))
}