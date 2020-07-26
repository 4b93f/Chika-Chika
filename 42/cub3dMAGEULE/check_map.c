#include "cub3d.h"

int check_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        if (find_error(map[i]) == 1)
            return (1);
        i++;
    }
    return (0);
}

int wrong_char(char **map)
{
    int i;

    i = 0;
    while(map[i] != 1)
        i++;
    while (map[i])
    {
        if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
            i++;
    }
    return (1);
}

int updownwall(char **map)
{
    int i;

    i = 0;
    while (map[i] != '1')
        i++;
    while (map[i])
    {
        if (map[i] != '1')
            return (1);
        i++;
    }
    return (0);
}