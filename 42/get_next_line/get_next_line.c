/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:29:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/21 06:31:56 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 3
#include "get_next_line.h"

int check_error(int fd, char *line)
{
	if (fd == -1)
		return (-1);
	return (1);
}

char *save(const char *str)
{
	char *save;
	save = ft_strrchr(str, '\n');
	return (ft_substr(save, 1, strlen(save - 1)));
}

int find_end_string(char *str)
{
	int i ;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


char	*readline(int fd, char *str)
{
	char buf[BUF_SIZE + 1];
	int ret;
	char *lu;
	int i;

	ret = 0;
	i = 0;
	lu = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		lu = ft_strjoin(lu, buf);
		if (find_end_string(lu) == 1)
			break ;
	}
	return (lu);
}

int get_next_line(int fd, char **line)
{
	static char *str;
	char *tmp;
	int i;
	int j;
	
	i = 0;
	j = 0;
	if (check_error(fd, *line) == -1)
		return (-1);
	if (!str)
		if(!(str = (char *)malloc(sizeof(char) * BUF_SIZE + 1)))
			return (0);
	if (*str)
		ft_strcpy(*line, str);
	str = readline(fd, str);
	tmp = str;
	if (str[i])
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			if (tmp != str)
			{
				
			}
			*line = ft_substr(line, 0, i + ft_strlen(tmp));
			str = &str[i + 1];
		}
	}
	else
			(*line) = ft_strdup("");
	printf("~line =%s~}", *line);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	
	fd = open("test", O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);

}
