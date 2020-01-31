/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:29:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/31 12:33:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 10
#include "get_next_line.h"

static int check_error(int fd, char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return(1);
	if (fd == -1)
		return (0);
	while (str[i])
	{
		if (str[i] == '\0')
			return(0);
		i++;
	}		
	return (1);
}

static int find_end_string(char *str)
{
	int i ;

	i = 0;
	if (!str)
		return(0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char *get_l(char *string)
{
	int  i;
	int j;
	char *ligne;

	i = 0;
	j = 0;
	if (!string)
		return(NULL);
	while (string[i] && string[i] != '\n')
		i++;
	if (!(ligne = ft_substr(string, 0, i)))
		return (NULL);
	while (j < i)
	{
		ligne[j] = string[j];
		j++;
	}
	ligne[i] = '\0';
	return (ligne);
}

char    *readline(int fd, char *string)
{
    char buf[BUF_SIZE + 1];
    int ret;
    char *temp;
    temp = NULL;
    while ((ret = read(fd, buf, BUF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        string = ft_strjoin(string, buf);
		if (find_end_string(buf))
			break;
    }
    return (string);
}

char     *rest(char *strings)
{
    int i;
    int j;
    char *tmp;

    j = 0;
    i = 0;
    if (!strings)
        return (NULL);
    while (strings[i] && strings[i] != '\n')
        i++;
    if (!(tmp = ft_substr(strings, i + 1, strlen(strings))))
        return (NULL);
   	free(strings);
    return (tmp);
}

int get_next_line(int fd, char **line)
{
    static char *str = NULL;
    int i;
    char *tmp;

    i = 0;
	tmp  = NULL;
	*line = NULL;
    if (check_error(fd, str) < 0)
	{
		printf("regarde\n");
        return (-1);
	}
    if (str && str[0] == '\n')
    {
        *line = ft_strdup("");
        str = rest(str);
        return (1);
    }
    if (!(str = readline(fd, str)))
		return (-1);
    if (!(*line = get_l(str)))
		return (-1);
    if (!find_end_string(str))
    {
        free(str);
        return (0);
    }
    str = rest(str);
    return(1);
}

void	ft_putendl(char const *s)
{
	int i;

	i = ft_strlen((char*)s);
	if (s)
		write(1, s, i);
	write(1, "\n", 1);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	ft_putendl(line);
	free(line);
	CHECK
	if (argc == 2)
		close(fd);
}
