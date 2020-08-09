#include "cub3d.h"

void ft_updownwall(char *map)
{
    int i;
    i = 0;
    if (ft_check_startend(map) == FALSE)
        return(FALSE);
    while (map[i])
    {
        if (map[i] != '1' && map[i] != ' ')
            return (ft_error());
        i++;
    }
}

int ft_wrong_char(char *map)
{
    int i;

    i = 0;
    if (ft_check_startend(map) == FALSE)
        return(FALSE);
    while (map[i])
    {
        if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E' || map[i] == ' ' || map[i] == '0' || map[i] == '1'|| map[i] == '2')
            i++;
        else
            return(FALSE);
    }
    return (TRUE);
}

int ft_check_space(char **map)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if (map[i][j] == ' ')
            {
                while(map[i][j] && map[i][j] == ' ')
                    j++;
                if (map[i][j] != '1')
                    return(FALSE);
            }
            j++;
        }
        j = 0;
        i++;
    }
}


int ft_check_startend(char *map)
{
    int i;

    i = 0;
    while (map[i] && map[i] != ' ')
        i++;
    if (map[i] != 1)
        return(FALSE);
    i = ft_strlen(map);
    while(i > 0 && map[i] == '  ')
        i--;
    if (map[i] != '1')
        return(FALSE);
    return(TRUE);
}


int ft_check_map(char **map)
{
    int i;

    i = 1;
    updownwall(map[0]);
    while(map[i + 1] != NULL)
    {
        if (wrong_char(map[i]) == FALSE)
            return(FALSE);
        i++;
    }
    updownwall(map[i]);
    return(TRUE);
}


