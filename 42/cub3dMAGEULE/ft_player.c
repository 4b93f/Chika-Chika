/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:36:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/15 19:15:44 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int intcmp(int x, int y)
{
    int total = y - x;
    printf("total = %d\n", total);
    if (total == 0)
        return (1);
    else
        return(0);
}
void ft_orientation(t_params *params, t_ray *ray)
{
    if (intcmp(params->player_orientation, 'N') == 1)
    {
        ray->dirX = -1.0;
        ray->planeY = -0.66;
    }
    if (intcmp(params->player_orientation,'S') == 1)
    {
        ray->dirX = 1.0;
        ray->planeY = 0.66;
    }
    if (intcmp(params->player_orientation, 'W') == 1)
    {
        ray->dirY = 1.0;
        ray->planeX = -0.66;
    }
    if (intcmp(params->player_orientation, 'E') == 1)
    {
        ray->dirY = -1.0;
        ray->planeX = 0.66;
    }
}