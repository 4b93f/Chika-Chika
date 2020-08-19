#include "cub3d.h"

int ft_check_startend(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] == ' ')
        i++;
    if (str[i] != '1')
        return(FALSE);
    i = strlen(str) - 1;
    while(i > 0 && str[i] == ' ')
        i--;
    if (str[i] != '1')
        return(FALSE);
    return(TRUE);
}

int  ft_updownwall(char *map)
{
    int i;
    i = 0;
    if (ft_check_startend(map) == FALSE)
        return(FALSE);
    while (map[i])
    {
        if (map[i] != '1' && map[i] != ' ')
            return(FALSE);
        i++;
    }
    return(TRUE);
}

int findpos = 0;

int ft_wrong_char(char *map)
{
    int i;

    i = 0;
    if (ft_check_startend(map) == FALSE)
        return(FALSE);
    while (map[i])
    {
        if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
            findpos++;
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
                k = j;
                while(k > 0 && map[i][k] == ' ')
                    k--;
                if (map[i][k] != '1' && k != 0)
                    return(FALSE);
                k = j;
                while(map[i][k] && map[i][k] == ' ')
                    k++;
                if (map[i][k] != '1' && map[i][k])
                    return(FALSE);
                /************************************/
                k = i;
                while(k > 0 && map[k][j] == ' ')
                    k--;
                if (map[k][j] != '1' && k != 0 && (map[k] <= (map[k - 1])))
                    return(FALSE);
                k = i;
                while(map[k] != NULL && map[k][j] == ' ')
                    k++;
                if (map[k] != NULL && map[k][j] != '1' && (map[k] <= (map[k + 1])))
                    return(FALSE);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return(TRUE);
}

int ft_search_player(char **map)
{
    int i;
    int findpos;

    i = 0;
    findpos = 0;
    while(map[i])
    {
        if (strchr(map[i], 'S') || strchr(map[i], 'N') || strchr(map[i], 'E') || strchr(map[i], 'W'))
            findpos++;
        i++;
    }
    if (findpos > 1)
        return (FALSE);
    return (TRUE);
}
int ft_check_map(char **map)
{
    int i;
    
    i = 1;
    if (ft_search_player(map) == 0)
        return(FALSE);
    if (!map[2])
        return(FALSE);
    if (ft_updownwall(map[0]) == 0)
        return(FALSE);
    while(map[i + 1] != NULL)
    {
        if (ft_wrong_char(map[i]) == FALSE)
            return(FALSE);
        i++;
    }
    if (ft_updownwall(map[i]) == 0)
        return(FALSE);
    if (ft_check_space(map) == 0)
        return(FALSE);
    if (findpos == 0 || findpos > 1)
        return (FALSE);
    return(TRUE);
}


