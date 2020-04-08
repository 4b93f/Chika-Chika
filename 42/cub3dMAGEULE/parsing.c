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

char **ft_parsing(int fd)
{
	char **str;
	int lenlen;
	char *line;

	lenlen = -1;
	while (TRUE)
	{
		if ((get_next_line(fd, &line) <= 0))
			return (str);
		lenlen++;
		if (!(str[lenlen] = ft_realloc(line, lenlen)))
			return (0);
		str[lenlen] = line;
		free(line);
	}
}