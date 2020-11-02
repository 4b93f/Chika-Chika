/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:26:08 by root              #+#    #+#             */
/*   Updated: 2020/11/02 18:50:41 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_realloc(char **str, char *line)
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
		cpy[i] = strdup(str[i]);
		free(str[i]);
		i++;
	}
	cpy[i] = line;
	cpy[i + 1] = NULL;
	free(str);
	return (cpy);
}

char	**ft_map_parsing(int fd, char *firstline)
{
	char	**str;
	int		cmpt;
	char	*line;

	if (!(str = malloc(sizeof(char*) * 1)))
		return (0);
	str[0] = NULL;
	str = ft_realloc(str, firstline);
	cmpt = -1;
	while (get_next_line(fd, &line) > 0)
	{
		cmpt++;
		if (!(str = ft_realloc(str, line)))
			return (0);
	}
	if (!(str = ft_realloc(str, line)))
		return (0);
	return (str);
}
