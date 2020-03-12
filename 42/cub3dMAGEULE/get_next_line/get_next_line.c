/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:29:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/01 01:08:45 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_end_string(char *str)
{
	int	i;

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

char	*get_l(char *string)
{
	int		i;
	int		j;
	char	*chain;

	i = 0;
	j = 0;
	if (!string)
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	if (!(chain = ft_substr(string, 0, i)))
		return (NULL);
	while (j < i)
	{
		chain[j] = string[j];
		j++;
	}
	chain[i] = '\0';
	return (chain);
}

char	*readline(int fd, char *string)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	char	*temp;

	temp = NULL;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		string = ft_strjoin(string, buf);
		if (find_end_string(buf))
			break ;
	}
	return (string);
}

char	*rest(char *strings)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	if (!strings)
		return (NULL);
	while (strings[i] && strings[i] != '\n')
		i++;
	tmp = malloc(sizeof(char*) * ft_strlen(strings));
	while (strings[i])
	{
		tmp[j] = strings[i + 1];
		i++;
		j++;
	}
	free(strings);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static	char	*str[OPEN_MAX];

	*line = NULL;
	if (check_error(fd, str[fd]) < 0 || BUFFER_SIZE < 1)
		return (-1);
	str[fd] = readline(fd, str[fd]);
	*line = get_l(str[fd]);
	if (!find_end_string(str[fd]))
	{
		if (str[fd] == NULL)
			*line = ft_strdup("");
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	str[fd] = rest(str[fd]);
	return (1);
}
