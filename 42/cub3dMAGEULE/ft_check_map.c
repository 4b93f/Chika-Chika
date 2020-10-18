/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:47:26 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 19:14:44 by chly-huc         ###   ########.fr       */
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

void ft_void_algo(int *i, int *j, int *k, char **map)
{    
    *k = *j;
    while(*k > 0 && map[*i][*k] == ' ')
        *k = *k - 1;
    if (map[*i][*k] != '1' && *k != 0)
        ft_error(WRONG_MAP_FORMAT);
    *k = *j;
    while(map[*i][*k] && map[*i][*k] == ' ')
        *k = *k + 1;
    if (map[*i][*k] != '1' && map[*i][*k])
        ft_error(WRONG_MAP_FORMAT);
    *k = *i;
    while(*k > 0 && map[*k][*j] == ' ')
        *k = *k - 1;
    if (map[*k][*j] != '1' && *k != 0 && (map[*k] <= (map[*k - 1])))
        ft_error(WRONG_MAP_FORMAT);
    *k = *i;
    while(map[*k] != NULL && map[*k][*j] == ' ')
        *k = *k + 1;
    if (map[*k] != NULL && map[*k][*j] != '1' && (map[*k] <= (map[*k + 1])))
        ft_error(WRONG_MAP_FORMAT);
}

void ft_zero_algo(int *i, int *j, int *k, char **map)
{    
    while(*k > 0 && map[*i][*k] != '1')
        *k = *k - 1;
    if (map[*i][*k] != '1' && *k != 0)
       ft_error(WRONG_MAP_FORMAT);
    *k = *j;
    while(map[*i][*k] && map[*i][*k] != '1')
        *k = *k + 1;
    if (map[*i][*k] != '1' && map[*i - 1][*k] && map[*i + 1][*k])
       ft_error(WRONG_MAP_FORMAT);
    *k = *i;
    while(*k > 0 && map[*k][*j] != '1')
    {
        if (map[*k][*j] == ' ')
           ft_error(WRONG_MAP_FORMAT);
        *k = *k - 1;
    }
    *k = *i;
    while(map[*k] && *k > 0 && map[*k][*j] != '1')
    {
        if (map[*k][*j] == ' ')
           ft_error(WRONG_MAP_FORMAT);
        *k = *k + 1;
    }
    if (!map[*k])
       ft_error(WRONG_MAP_FORMAT);
}



int ft_check_space(char **map)
{
    int i;
    int j;
    int k;

    i = -1;
    j = 0;
    k = 0;
    while(map[++i])
    {
        while(map[i][++j])
        {
            if (map[i][j] == ' ')
            {
                k = j;
                ft_void_algo(&i, &j, &k, map);
            }
            if (map[i][j] == '0')
            {
                k = j;
                ft_zero_algo(&i, &j, &k, map);
            }
        }
        j = -1;
    }
    return (TRUE);
}

