#include "cub3d.h"

char *taking_info(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != '\t' && line[i] != '\n' && line[i] != '\r'  && line[i] != '\v'
     && line[i] != '\f' && ft_isalpha(line[i]))
        i++;
    return (line + i);
}

int main(int argc, char **argv)
{
    int i;
    char *str;
    int fd;
    char *line;

    i = 0;
    fd = open("map_test", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", ft_strtrim(taking_info(line), " "));
    str = ft_strtrim(taking_info(line), " ");
    printf("%ld", strlen(str));

}