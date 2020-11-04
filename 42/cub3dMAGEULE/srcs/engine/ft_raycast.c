/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/11/04 21:12:44 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_base_value(t_params *params, t_ray *ray, int x)
{
	ray->hit = 0;
	params->player->camx = 2 * x / (double)(params->screenwidth) - 1;
	ray->raydirx = params->player->dirx + params->player->planex
		* params->player->camx;
	ray->raydiry = params->player->diry + params->player->planey
		* params->player->camx;
	ray->mapx = (int)params->player->posx;
	ray->mapy = (int)params->player->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
}

void	get_next_value(t_params *params, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (params->player->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - params->player->posx)
			* ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (params->player->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - params->player->posy)
			* ray->deltadisty;
	}
}

void	wall_hit(t_params *params, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
			params->tex->texnum = ray->raydirx < 0 ? 2 : 3;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
			params->tex->texnum = ray->raydiry < 0 ? 1 : 0;
		}
		if (params->map[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
	}
}

void	wall_dist(t_params *params, t_ray *ray, double *wallx)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->mapx - params->player->posx
				+ (1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->mapy - params->player->posy
				+ (1 - ray->stepy) / 2) / ray->raydiry;
	ray->lineheight = (params->screenheight / ray->perpwalldist);
	ray->drawstart = (-ray->lineheight / 2 + (params->screenheight / 2));
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + (int)params->screenheight / 2;
	if (ray->drawend >= params->screenheight)
		ray->drawend = params->screenheight - 1;
	if (params->ray->side == 0)
		*wallx = params->player->posy + params->ray->perpwalldist
			* params->ray->raydiry;
	else
		*wallx = params->player->posx + params->ray->perpwalldist
			* params->ray->raydirx;
	*wallx -= floor((*wallx));
}

void	ft_raycast(t_params *params, t_ray *ray, t_color *color)
{
	int		x;
	int		y;
	double	wallx;
	double	zbuffer[params->screenwidth];

	x = 0;
	y = 0;
	while (++x < params->screenwidth)
	{
		init_base_value(params, ray, x);
		get_next_value(params, ray);
		wall_hit(params, ray);
		wall_dist(params, ray, &wallx);
		get_next_value_bis(params, x, wallx, &y);
		print_cell_floor(params, color, x);
		print_wall(params, x, y);
		zbuffer[x] = params->ray->perpwalldist;
	}
	sprite(params, zbuffer);
	//system("leaks Cub3D");
}
