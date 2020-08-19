/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becentrale <becentrale@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/08/19 18:47:29 by becentrale       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_resolution(t_params *params)
{
    char **tmp;
    
    tmp = ft_split(params->res, ' ');
    params->screenwidth = ft_atoi(tmp[0]);
    params->screenheight = ft_atoi(tmp[1]);
    return;
}

void ft_getposplayer(char **map, t_ray *ray)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
            {
                ray->posX = i;
                ray->posY = j;
            }
            j++;
        }
        j = 0;
        i++;
    }    
}

void ft_raycast(t_params *params,t_ray *ray)
{
    ft_resolution(params);
    ft_getposplayer(params->map, ray);
    return;    
}