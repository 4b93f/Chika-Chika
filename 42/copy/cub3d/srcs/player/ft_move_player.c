/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:27:25 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/14 18:36:10 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	up(t_params *params)
{
	if (params->map[(int)(params->player->posx + params->player->dirx *
	params->player->movespeed)][(int)params->player->posy] == '0' &&
	params->map[(int)(params->player->posx + params->player->dirx *
	params->player->movespeed)][(int)(params->player->posy - 0.01)] == '0' &&
	params->map[(int)(params->player->posx + params->player->dirx *
	params->player->movespeed)][(int)(params->player->posy + 0.01)] == '0')
		params->player->posx += params->player->dirx * 0.1;
	if (params->map[(int)params->player->posx][(int)(params->player->posy
	+ params->player->diry * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx - 0.01)][(int)(params->player->posy +
	0.01 + params->player->diry * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx + 0.01)][(int)(params->player->posy -
	0.01 + params->player->diry * params->player->movespeed)] == '0')
		params->player->posy += params->player->diry * 0.1;
}

void	down(t_params *params)
{
	if (params->map[(int)(params->player->posx - params->player->dirx *
	params->player->movespeed)][(int)params->player->posy] == '0' &&
	params->map[(int)(params->player->posx - params->player->dirx *
	params->player->movespeed)][(int)(params->player->posy + 0.01)] == '0' &&
	params->map[(int)(params->player->posx - params->player->dirx *
	params->player->movespeed)][(int)(params->player->posy - 0.01)] == '0')
		params->player->posx -= params->player->dirx * 0.1;
	if (params->map[(int)params->player->posx][(int)(params->player->posy -
	params->player->diry * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx + 0.01)][(int)(params->player->posy -
	params->player->diry * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx - 0.01)][(int)(params->player->posy -
	params->player->diry * params->player->movespeed)] == '0')
		params->player->posy -= params->player->diry * 0.1;
}

void	left(t_params *params)
{
	if (params->map[(int)(params->player->posx - params->player->planex *
	params->player->movespeed)][(int)(params->player->posy)] == '0' &&
	params->map[(int)(params->player->posx - params->player->planex *
	params->player->movespeed)][(int)(params->player->posy - 0.01)] == '0' &&
	params->map[(int)(params->player->posx - params->player->planex *
	params->player->movespeed)][(int)(params->player->posy + 0.01)] == '0')
		params->player->posx -= params->player->planex * 0.1;
	if (params->map[(int)params->player->posx][(int)(params->player->posy -
	params->player->planey * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx - 0.01)][(int)(params->player->posy -
	params->player->planey * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx + 0.01)][(int)(params->player->posy -
	params->player->planey * params->player->movespeed)] == '0')
		params->player->posy -= params->player->planey * 0.1;
}

void	right(t_params *params)
{
	if (params->map[(int)(params->player->posx + params->player->planex *
	params->player->movespeed)][(int)(params->player->posy)] == '0' &&
	params->map[(int)(params->player->posx + params->player->planex *
	params->player->movespeed)][(int)(params->player->posy + 0.01)] == '0' &&
	params->map[(int)(params->player->posx + params->player->planex *
	params->player->movespeed)][(int)(params->player->posy - 0.01)] == '0')
		params->player->posx += params->player->planex * 0.1;
	if (params->map[(int)params->player->posx][(int)(params->player->posy +
	params->player->planey * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx + 0.01)][(int)(params->player->posy +
	params->player->planey * params->player->movespeed)] == '0' &&
	params->map[(int)(params->player->posx - 0.01)][(int)(params->player->posy +
	params->player->planey * params->player->movespeed)] == '0')
		params->player->posy += params->player->planey * 0.1;
}
