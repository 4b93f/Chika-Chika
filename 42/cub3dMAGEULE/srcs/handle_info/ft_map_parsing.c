/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:26:08 by root              #+#    #+#             */
/*   Updated: 2020/11/04 20:36:11 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**ft_realloc(char **str, char *line, char **strfree)
{
	char	**cpy;
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	if (!(cpy = malloc(sizeof(char *) * (i + 2))))
		return (0);
	i = 0;
	while (str[i] != NULL)
	{
		cpy[i] = (str[i]);
		i++;
	}
	cpy[i] = line;
	cpy[i + 1] = NULL;
	free(strfree);
	return (cpy);
}

char	**ft_map_parsing(int fd, char *firstline)
{
	char	**str;
	int		cmpt;
	char	*line;
	char	**free;

	if (!(str = malloc(sizeof(char*) * 1)))
		return (NULL);
	str[0] = NULL;
	free = str;
	if (!(str = ft_realloc(str, firstline, free)))
		return (NULL);
	cmpt = -1;
	while (get_next_line(fd, &line) > 0)
	{
		cmpt++;
		free = str;
		if (!(str = ft_realloc(str, line, free)))
			return (NULL);
	}
	free = str;
	if (!(str = ft_realloc(str, line, free)))
		return (0);
	return (str);
}
