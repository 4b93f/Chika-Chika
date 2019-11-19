/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 04:34:25 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 17:04:29 by chly-huc         ###   ########.fr       */
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

    char **map;
	char *pre_map;
	char *code;
	int **map_converted;
	
	pre_map = read_and_write();
	map = ft_split(pre_map, "\n");
	code = ft_check_error(map);
	if((ft_check_error(map) == NULL))
		return(0);
	printf("test\n");
	map_converted = ft_map_setup_main(map, code);

	//while(map_converted[i])
	//{
		//printf("%s\n", map_converted[i]);
		//i++;	
	//}
	while(map[i])
	{
		free(map[i]);
		i++;
	}
    return(0);
}