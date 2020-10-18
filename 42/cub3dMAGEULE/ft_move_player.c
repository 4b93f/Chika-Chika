/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:08:45 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 23:09:42 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void up(t_params *params)
{
    if(params->map[(int)(params->player->posX + params->player->dirX * params->player->movespeed)][(int)params->player->posY] == '0' && 
    params->map[(int)(params->player->posX + params->player->dirX * params->player->movespeed)][(int)(params->player->posY - 0.01)] == '0' && 
    params->map[(int)(params->player->posX + params->player->dirX * params->player->movespeed)][(int)(params->player->posY + 0.01)] == '0')
    {
        params->player->posX += params->player->dirX * 0.1;
    }
    if(params->map[(int)params->player->posX][(int)(params->player->posY + params->player->dirY * params->player->movespeed)] == '0' && 
    params->map[(int)(params->player->posX - 0.01)][(int)(params->player->posY + 0.01 + params->player->dirY * params->player->movespeed)] == '0' &&
    params->map[(int)(params->player->posX + 0.01)][(int)(params->player->posY - 0.01 + params->player->dirY * params->player->movespeed)] == '0')
    {
        params->player->posY += params->player->dirY * 0.1;
    }
    reset_image(params);
}

void down(t_params *params)
{   
    if(params->map[(int)(params->player->posX - params->player->dirX * params->player->movespeed)][(int)params->player->posY]== '0' && 
    params->map[(int)(params->player->posX - params->player->dirX * params->player->movespeed)][(int)(params->player->posY + 0.01)] == '0' &&
    params->map[(int)(params->player->posX - params->player->dirX * params->player->movespeed)][(int)(params->player->posY - 0.01)] == '0')
         params->player->posX -= params->player->dirX * 0.1;

    if(params->map[(int)params->player->posX][(int)(params->player->posY - params->player->dirY * params->player->movespeed)]== '0' &&
    params->map[(int)(params->player->posX + 0.01)][(int)(params->player->posY - params->player->dirY * params->player->movespeed)]== '0' &&
    params->map[(int)(params->player->posX - 0.01)][(int)(params->player->posY - params->player->dirY * params->player->movespeed)]== '0')
        params->player->posY -= params->player->dirY * 0.1;
    reset_image(params);
}
        
void left(t_params *params)
{
    if (params->map[(int)(params->player->posX - params->player->planeX * params->player->movespeed)][(int)(params->player->posY)] == '0' &&
    params->map[(int)(params->player->posX - params->player->planeX * params->player->movespeed)][(int)(params->player->posY - 0.01)] == '0' &&
    params->map[(int)(params->player->posX - params->player->planeX * params->player->movespeed)][(int)(params->player->posY + 0.01)] == '0')
        params->player->posX -=  params->player->planeX * 0.1;
    if (params->map[(int)params->player->posX][(int)(params->player->posY - params->player->planeY * params->player->movespeed)] == '0' &&
    params->map[(int)(params->player->posX - 0.01)][(int)(params->player->posY - params->player->planeY * params->player->movespeed)] == '0' &&
    params->map[(int)(params->player->posX + 0.01)][(int)(params->player->posY - params->player->planeY * params->player->movespeed)] == '0')
        params->player->posY -=  params->player->planeY * 0.1;
    reset_image(params);
}

void right(t_params *params)
{
    if (params->map[(int)(params->player->posX + params->player->planeX * params->player->movespeed)][(int)(params->player->posY)] == '0' && 
    params->map[(int)(params->player->posX + params->player->planeX * params->player->movespeed)][(int)(params->player->posY + 0.01)] == '0' &&
    params->map[(int)(params->player->posX + params->player->planeX * params->player->movespeed)][(int)(params->player->posY - 0.01)] == '0')
        params->player->posX += params->player->planeX * 0.1;
    if (params->map[(int)params->player->posX][(int)(params->player->posY + params->player->planeY * params->player->movespeed)] == '0' &&
    params->map[(int)(params->player->posX + 0.01)][(int)(params->player->posY + params->player->planeY * params->player->movespeed)] == '0' &&
    params->map[(int)(params->player->posX - 0.01)][(int)(params->player->posY + params->player->planeY * params->player->movespeed)] == '0')
         params->player->posY += params->player->planeY * 0.1;
    reset_image(params);
}
