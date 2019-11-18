/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 04:34:25 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/18 21:35:21 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define BUF_SIZE 4096

char	*read_and_write()
{
	int		fd;
	int		ret;
	int		size;
	char	*dicos;
	char	buf[BUF_SIZE + 1];

	size = 0;
	fd = open("map.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		size += ret;
	}
	if (!(dicos = malloc(sizeof(char) * (size + 1))))
		return (0);
	close(fd);
	fd = open("map.txt", O_RDONLY);
	read(fd, dicos, size);
	dicos[size] = '\0';
	return (dicos);
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    char **map;
	char *pre_map;
	pre_map = read_and_write();
	map = ft_split(pre_map, "\n");
	if ((ft_recup_code(map[0], map)) == 0)
		return(0);
	if (ft_verif_map(map) == 0)
		return(0);
    return(0);
}