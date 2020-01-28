/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:29:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/25 10:17:44 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 7
#include "get_next_line.h"

int check_error(int fd, char *line)
{
	if (fd == -1)
		return (-1);
	return (1);
}

int find_end_string(char str, int j)
{
	int i;

	i = 0;
	if (str)
		return (0);
	if (str == '\n')
		if (str == '\n')
			return (1);
	return (0);
}
char	*readline(int fd, char **line, char *str)
{	
	char buf[BUF_SIZE + 1];
	char	*tmp;
	int ret;
	char *lu;
	int i;
	
	ret = 0;
	lu = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		i = 0;		
		buf[ret] = '\0';
		while (buf[i] && buf[i] != '\n')
		{
			tmp = *line;
			*line = ft_charjoin(*line, buf[i]);
			//printf("line:[%s] buf:[%c] i:[%d]\n", *line, buf[i], i);
			//write(1, "!\n", 1);
			free(tmp);
			i++;
		}
		if (buf[i] == '\n')
			break ;
	}
	if (buf[i] == '\n')
		while (buf[++i])
			*str++ = buf[i];
	*str = 0;
	return (*line);
}

int get_next_line(int fd, char **line)
{
	static char str[OPEN_MAX];
	char *tmp;
	int i;
	int j;
	int o;
	
	
	i = 0;
	if (check_error(fd, *line) == -1)
		return (-1);
	if (*str)
	{
		while(str[i])
		{
			if (str[i] == '\n')
			{
				*line = ft_substr(str, 0, i);
				tmp = ft_substr(str, i + 1 , BUF_SIZE);
				o = 0;
				printf("tmp = %s\n", tmp);
				while(tmp[o])
				{
					str[o] = tmp[o];
					o++;
				}
				
				return (1);
			}
			i++;
		}
		*line = ft_strjoin(*line, str);	
	}
	i = 0;
	readline(fd, line, str);
	*str = str[i];
	//printf("~~~line final == %s~~~\n", *line);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int j;
		
	line = NULL;
	j = 0;
	fd = open("test2", O_RDONLY);
	while(j < 28)
	{
		get_next_line(fd, &line);
		//printf("{%s}\n", line);
		free(line);
		line = NULL;
		j++;
	}
}
