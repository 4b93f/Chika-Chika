/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:47:26 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/17 18:14:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_check_startend(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] == ' ')
        i++;
    if (str[i] != '1')
        return (FALSE);
    i = strlen(str) - 1;
    while(i > 0 && str[i] == ' ')
        i--;
    if (str[i] != '1')
        return (FALSE);
    return (TRUE);
}

int  ft_updownwall(char *map)
{
    int i;
    
    i = 0;
    if (ft_check_startend(map) == FALSE)
        return (FALSE);
    while (map[i])
    {
        if (map[i] != '1' && map[i] != ' ')
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int ft_check_char(t_params *params, char *map)
{
    int i;

    i = 0;
    if (ft_check_startend(map) == FALSE)
        return (FALSE);
    while (map[i])
    {
        if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
        {
            params->find_pos++;
            params->player_orientation = map[i];
        }
        if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E' || map[i] == ' ' || map[i] == '0' || map[i] == '1'|| map[i] == '2')
        {
            if (map[i] == '2')
                params->sp->numsprite += 1;
            i++;
        }
        else
            return (FALSE);
    }
    return (TRUE);
}

int ft_void_algo(int *i, int *j, int *k, char **map)
{    
    *k = *j;
    while(*k > 0 && map[*i][*k] == ' ')
        *k = *k - 1;
    if (map[*i][*k] != '1' && *k != 0)
        return (FALSE);
    *k = *j;
    while(map[*i][*k] && map[*i][*k] == ' ')
        *k = *k + 1;
    if (map[*i][*k] != '1' && map[*i][*k])
        return (FALSE);
    *k = *i;
    while(*k > 0 && map[*k][*j] == ' ')
        *k = *k - 1;
    if (map[*k][*j] != '1' && *k != 0 && (map[*k] <= (map[*k - 1])))
        return (FALSE);
    *k = *i;
    while(map[*k] != NULL && map[*k][*j] == ' ')
        *k = *k + 1;
    if (map[*k] != NULL && map[*k][*j] != '1' && (map[*k] <= (map[*k + 1])))
        return (FALSE);
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
                if (!ft_void_algo(&i, &j, &k, map))
                    return (FALSE);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (TRUE);
}

