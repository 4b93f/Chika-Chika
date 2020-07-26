#include "cub3d.h"

int main()
{
    int fd;
	char **str;
	int cmpt;
	char *line;

	cmpt = -1;
	fd = open("map.txt", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		cmpt++;
		str[cmpt] = ft_realloc(line, cmpt);
		str[cmpt] = line;
		free(line);
	}
	str[cmpt] = line;
	free(line);
	printf("c'est cette merde qui fonctionne pas =%c", str[0][7]);
	return(0);
}