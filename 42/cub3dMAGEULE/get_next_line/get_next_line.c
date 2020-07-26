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
	char	*ligne;

	i = 0;
	j = 0;
	if (!string)
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	if (!(ligne = ft_substr1(string, 0, i)))
		return (NULL);
	while (j < i)
	{
		ligne[j] = string[j];
		j++;
	}
	ligne[i] = '\0';
	return (ligne);
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
		string = ft_strjoin1(string, buf);
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
	tmp = malloc(sizeof(char*) * ft_strlen1(strings));
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
	static	char	*str;

	*line = NULL;
	if (check_error(fd, str) < 0 || BUFFER_SIZE < 1)
		return (-1);
	str = readline(fd, str);
	*line = get_l(str);
	if (!find_end_string(str))
	{
		if (str == NULL)
			*line = ft_strdup1("");
		free(str);
		str = NULL;
		return (0);
	}
	str = rest(str);
	return (1);
}