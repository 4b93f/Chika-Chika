/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:36:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/14 18:37:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_getposplayer(char **map, t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
			map[i][j] == 'W' || map[i][j] == 'E')
			{
				player->posx = i + 0.5;
				player->posy = j + 0.5;
				map[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void		turn_left(t_params *params)
{
	double olddirx;
	double oldplanex;

	olddirx = params->player->dirx;
	oldplanex = params->player->planex;
	params->player->dirx = params->player->dirx * cos(-params->player->rotspeed)
	- params->player->diry * sin(-params->player->rotspeed);
	params->player->diry = olddirx * sin(-params->player->rotspeed) +
	params->player->diry * cos(-params->player->rotspeed);
	params->player->planex = params->player->planex *
	cos(-params->player->rotspeed) - params->player->planey *
	sin(-params->player->rotspeed);
	params->player->planey = oldplanex * sin(-params->player->rotspeed) +
	params->player->planey * cos(-params->player->rotspeed);
}

void		turn_right(t_params *params)
{
	double olddirx;
	double oldplanex;

	olddirx = params->player->dirx;
	oldplanex = params->player->planex;
	params->player->dirx = params->player->dirx *
	cos(params->player->rotspeed) - params->player->diry *
	sin(params->player->rotspeed);
	params->player->diry = olddirx * sin(params->player->rotspeed) +
	params->player->diry * cos(params->player->rotspeed);
	params->player->planex = params->player->planex *
	cos(params->player->rotspeed) - params->player->planey *
	sin(params->player->rotspeed);
	params->player->planey = oldplanex * sin(params->player->rotspeed)
	+ params->player->planey * cos(params->player->rotspeed);
}

static int	intcmp(int x, int y)
{
	int total;

	total = y - x;
	if (total == 0)
		return (TRUE);
	else
		return (FALSE);
}

void		ft_orientation(t_params *params)
{
	if (intcmp(params->player_orientation, 'N') == 1)
	{
		params->player->dirx = -1.0;
		params->player->planey = 0.66;
	}
	if (intcmp(params->player_orientation, 'S') == 1)
	{
		params->player->dirx = 1.0;
		params->player->planey = -0.66;
	}
	if (intcmp(params->player_orientation, 'W') == 1)
	{
		params->player->diry = -1.0;
		params->player->planex = -0.66;
	}
	if (intcmp(params->player_orientation, 'E') == 1)
	{
		params->player->diry = 1.0;
		params->player->planex = 0.66;
	}
}
