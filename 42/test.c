/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:23:21 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/29 09:31:18 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
# define BUFFER_SIZE 10

static int         ft_line_until_n(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}     


static char		*ft_line(char *join_buf)
{
	int i;
	int j;
	char *line;

	i = 0;
	j = 0;
	if (!join_buf)
		return (NULL);
	while (join_buf[i] && join_buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = join_buf[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

static char		*ft_stock_line(char *join_buf)
{
	unsigned int i;
	char *line_to_stock;
	
	i = 0;
	if (!join_buf)
		return (NULL);
	while (join_buf[i] && join_buf[i] != '\n')
		i++;
	i++;
	line_to_stock = ft_substr(join_buf, i, ft_strlen(join_buf) - i);
	free(join_buf);
	return (line_to_stock);
}

static int			ft_free(char *str, int returned)
{
	if (str)
		free(str);
	return (returned);
}

int         get_next_line(int fd, char **line)
{
    static char     *str;
	int i;
	char buf[BUFFER_SIZE + 1];
	char *join_buf;
	
	join_buf = NULL;
    if (BUFFER_SIZE <= 0 || fd < 0|| !line || read(fd, buf, 0) < 0)
        return (-1);
	if (str)
		if (!(join_buf = ft_strdup(str)))
			return (ft_free(join_buf, -1));
	while (!ft_line_until_n(buf) && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (i == 0)
			return (0);
		if (!(join_buf = ft_strjoin(join_buf, buf)))
			return (-1);
	}
	if (!(*line = ft_line(join_buf)))
		return (ft_free(join_buf, -1));
	if (!ft_line_until_n(join_buf))
		return (ft_free(join_buf, 0));
	if (!(str = ft_stock_line(join_buf)))
		return (ft_free(join_buf, -1));
//	printf("buf : %s", buf);
//	printf("\n------\n");
//	printf("join_buf : -->%s<--\n", join_buf);
//	printf("static str : -->%s<--\n\n\n\n", str);

	return (1);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include <limits.h>

int	main(int ac, char **av)
{
	char	*line;
	char	*gline;
	int		fd;
	int		gd;
	int		ret;
	int		gret;

	if (ac < 2)
		return (0);
	line = NULL;
	gline = NULL;
	fd = open(av[1], O_RDONLY);
	gd = open(av[2], O_RDONLY);
	printf("OPEN_MAX = %d\n", OPEN_MAX);
	ret = 1;
	gret = 1;
	while (ret > 0 || gret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("[%d]->%s\n", ret, line);
		if (ret >= 0)
			free(line);
		gret = get_next_line(gd, &gline);
		printf("[%d]->%s\n", gret, gline);
		if (ret >= 0)
			free(gline);
	}
}