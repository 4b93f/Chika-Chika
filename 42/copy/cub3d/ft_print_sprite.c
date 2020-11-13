/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:10:57 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/13 19:02:38 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sortsprites(t_params *params)
{
	double	first;
	double	second;
	int		i;

	i = 0;
	while (i < params->sp->numsprite && i + 1 != params->sp->numsprite)
	{
		first = ((params->player->posx - params->sprites[i].x) *
		(params->player->posx - params->sprites[i].x) + (params->player->posy
		- params->sprites[i].y) * (params->player->posy -
		params->sprites[i].y));
		second = ((params->player->posx - params->sprites[i + 1].x)
		* (params->player->posx - params->sprites[i + 1].x)
		+ (params->player->posy - params->sprites[i + 1].y) *
		(params->player->posy - params->sprites[i + 1].y));
		if (first < second)
		{
			params->sv->tmp = params->sprites[i];
			params->sprites[i] = params->sprites[i + 1];
			params->sprites[i + 1] = params->sv->tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	algo(t_params *params, int i)
{
	double spritex;
	double spritey;

	spritex = params->sprites[i].x - params->player->posx - 0.5;
	spritey = params->sprites[i].y - params->player->posy - 0.5;
	params->sv->invdet = 1.0 / (params->player->planex * params->player->diry
			- params->player->dirx * params->player->planey);
	params->sv->transformx = params->sv->invdet * (params->player->diry *
			spritex - params->player->dirx * spritey);
	params->sv->transformy = params->sv->invdet * (-params->player->planey
			* spritex + params->player->planex * spritey);
	params->sv->sprite_screenx = (int)((params->screenwidth / 2)
			* (1 + params->sv->transformx / params->sv->transformy));
	params->sv->sprite_height = abs((int)(params->screenheight /
				params->sv->transformy));
	params->sv->drawstarty = -params->sv->sprite_height / 2 +
		params->screenheight / 2;
}

static void	calc_values(t_params *params)
{
	if (params->sv->drawstarty < 0)
		params->sv->drawstarty = 0;
	params->sv->drawendy = params->sv->sprite_height / 2
		+ params->screenheight / 2;
	if (params->sv->drawendy >= params->screenheight)
		params->sv->drawendy = params->screenheight - 1;
	params->sv->sprite_width = abs((int)(params->screenheight
	/ params->sv->transformy));
	params->sv->drawstartx = -params->sv->sprite_width
	/ 2 + params->sv->sprite_screenx;
	if (params->sv->drawstartx < 0)
		params->sv->drawstartx = 0;
	params->sv->drawendx = params->sv->sprite_width
	/ 2 + params->sv->sprite_screenx;
	if (params->sv->drawendx >= params->screenwidth)
		params->sv->drawendx = params->screenwidth - 1;
}

static void	print_sprite(t_params *params, double *zbuffer, int *i)
{
	params->sv->x = params->sv->drawstartx;
	while (params->sv->x < params->sv->drawendx)
	{
		params->sv->spx = (int)(256 * (params->sv->x -
		(-params->sv->sprite_width
		/ 2 + params->sv->sprite_screenx)) * TXTW
		/ params->sv->sprite_width) / 256;
		if (params->sv->transformy > 0 && params->sv->x > 0 && params->sv->x
		< params->screenwidth && params->sv->transformy
		< zbuffer[params->sv->x])
		{
			params->sv->y = params->sv->drawstarty;
			while (++params->sv->y < params->sv->drawendy)
			{
				params->sv->j = params->sv->y * 256 - params->screenheight
				* 128 + params->sv->sprite_height * 128;
				params->sv->spy = ((params->sv->j * TXTH)
				/ params->sv->sprite_height) / 256;
				ft_sprite_to_image(params);
			}
		}
		params->sv->x++;
	}
	*i = *i + 1;
}

void		sprite(t_params *params, double *zbuffer)
{
	int		i;
	int		*sprite_order;
	double	*sprite_distance;

	i = -1;
	if (!(sprite_order = malloc(sizeof(int) * params->sp->numsprite)))
		quit("MALLOC_ERROR");
	if (!(sprite_distance = malloc(sizeof(double) * params->sp->numsprite)))
		quit("MALLOC_ERROR");
	sortsprites(params);
	while (++i < params->sp->numsprite)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((params->player->posx - params->sprites[i].x) *
		(params->player->posx - params->sprites[i].x) * (params->player->posy
		- params->sprites[i].y));
	}
	i = 0;
	while (i < params->sp->numsprite)
	{
		algo(params, i);
		calc_values(params);
		print_sprite(params, zbuffer, &i);
	}
	return ;
}
