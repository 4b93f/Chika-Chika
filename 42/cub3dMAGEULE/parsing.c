/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:29:43 by chly-huc          #+#    #+#             */
/*   Updated: 2020/07/18 18:31:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **ft_parsing()
{
	int fd;
	char **str;
	int cmpt;
	char *line;

	cmpt = -1;
	fd = open("map.txt", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		cmpt++;
		str[cmpt] = ft_realloc(line, cmpt);
		str[cmpt] = line;
		printf("%s\n", str[cmpt]);
		free(line);
	}
	str[cmpt] = line;
	printf("%s\n", str[cmpt]);
	free(line);
	return(0);
}