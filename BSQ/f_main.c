/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 04:34:25 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/20 17:14:41 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define BUF_SIZE 4096
/*
char	*readfd0_and_write()
{
	int		ret;
	char	**joined_buffer;
	char	*alljoined;
	int		first;

	first = 0;
	if(!(joined_buffer = malloc(sizeof(char *) * 3)))
		return (NULL);
	joined_buffer[2] = 0;
	if(!(joined_buffer[1] = malloc(sizeof(char) * BUF_SIZE + 1)))
		return (NULL);
	joined_buffer[1][BUF_SIZE] = '\0';
	ret = BUF_SIZE;
	while (ret != 0)
	{
		if ((ret = read(0, joined_buffer[1], BUF_SIZE)) == -1)
			return (NULL);
		joined_buffer[0] = ft_strjoin(joined_buffer[0], joined_buffer[1], first);
		first = 1;
	}
	if (!(alljoined = ft_strdup(joined_buffer[0])))
		return (NULL);
	ft_free_malloc(joined_buffer);
	printf("%s\n", alljoined);
	return (alljoined);
}
*/

char	*read_and_write(char *filepath)
{
	int		fd;
	int		ret;
	int		size;
	char	*dicos;
	char	buf[BUF_SIZE + 1];

	size = 0;
	fd = open(filepath, O_RDONLY);
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
	fd = open(filepath, O_RDONLY);
	read(fd, dicos, size);
	dicos[size] = '\0';
	return (dicos);
}

char	*readfd0_and_write()
{
	int		fd;
	char	buffer[51];
	int		ret;
	char	*dicos;
	int		tot;

	tot = 0;
	if ((fd = open("entree", O_WRONLY, O_TRUNC)) == -1)
		return (NULL);
	ret = 1;
	while (ret)
	{
		if ((ret = read(0, buffer, 50)) == -1)
			return (NULL);
		tot = tot + ret;
		buffer[ret] = '\0';
		write(fd, buffer, ret);
	}
	close(fd);
	if(!(dicos = read_and_write("entree")))
		return (NULL);
	dicos[tot] = '\0';
	return (dicos);	
}

int	map_handler(char *filepath, int argc)
{
	t_square	*bigsquare;
    char 		**map;
	char 		*pre_map;
	char 		*code;
	int 		**map_converted;
	int i;

	i = 0;
	
	if (argc == 1)
	{	
		if(!(pre_map = readfd0_and_write()))
			return (0);
	}
	else if (!(pre_map = read_and_write(filepath)))
		return (0);
	if (!(map = ft_split(pre_map, "\n")))
		return (0);
	if (!(code = ft_check_error(map)))
		return (0);
	if ((ft_check_error(map) == NULL))
		free(map);
	if (!(map_converted = ft_map_setup_main(map, code)))
		return (0);
	if (!(bigsquare = square_finder(map_converted)))
		return (0);
	if (!(map = ft_build(bigsquare, map, code)))
		return (0);
	ft_display(map);
    return(1);
}

int	main(int argc, char **argv)
{
	int		i;
	
	i = 1;
	if (argc == 1)
		if (!(map_handler(argv[0], argc)))
			return (write(2, "map error\n", 10));
	while (i < argc)
	{
		if(!map_handler(argv[i], argc))
			write(2, "map error\n", 10);
		i++;
	}
	return (0);
}