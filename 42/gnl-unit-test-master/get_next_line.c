/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:29:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/29 09:25:57 by chly-huc         ###   ########.fr       */
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
	char *line;

	i = 0;
	j = 0;
	if (!string)
		return(NULL);
	while (string[i] && string[i] != '\n')
		i++;
	line = ft_substr(string, 0, i);
	if (!(line = malloc(sizeof(char) * i + 1)))
		return (NULL);
	while(j < i)
	{
		line[j] = string[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char    *readline(int fd, char *string)
{
    char buf[BUF_SIZE + 1];
    int ret;
    char *temp;
    temp = NULL;
    while (!(find_end_string(buf)) && (ret = read(fd, buf, BUF_SIZE)) > 0)
    {
        buf[ret] = '\0';
		temp = string;
        string = ft_strjoin(string, buf);
        printf("{string = %s}\n", string);
        free(temp);
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
    while (strings[j])
        j++;
    while (strings[i] && strings[i] != '\n')
        i++;
    if (!(tmp = ft_substr(strings, i + 1, j)))
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
    if (check_error(fd, str) < 0)
        return (-1);
    if (str && str[0] == '\n')
    {
        *line = ft_strdup("");
        str = rest(str);
        return (1);
    }
    str = readline(fd, str);
    *line = get_l(str);
    if (!find_end_string(str))
    {
        *line = ft_strdup("");
        free(str);
        return (0);
    }
    str = rest(str);
    return(1);
}

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;
	int j = 0;
	argc = 2;
	fd = open(argv[1], O_RDONLY);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		//printf("|line final = %s|\n", line);
		//printf("ret : %d\n", ret);
		free(line);
	}
		printf("lien final = %s\n", line);
		printf("ret : %d\n", ret);
		free(line);
		//system("leaks a.out");
	//printf("ret : %d\n", ret);
		//system ("leaks a.out");
	/*
	  if ()
	  	return freerror(str, ret)
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
		system("leaks a.out");
	*/
	close(fd);
	CHECK
	return (0);
}

