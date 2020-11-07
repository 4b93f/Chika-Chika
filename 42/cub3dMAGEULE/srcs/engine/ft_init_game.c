/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:19:44 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/07 18:52:09 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init(t_params *params)
{
	t_color			*color;
	t_draw_sprite	*sp;
	t_spvalues		*sv;

	color = ft_malloc_color(params);
	params->color = color;
	sp = ft_malloc_sprite(params);
	params->sp = sp;
	sv = ft_malloc_spvalues(params);
	params->sv = sv;
}

void	ft_init_2(t_params *params, t_draw_sprite *sp, int fd)
{
	t_sprite	*sprites;
	t_tex		*tex;
	t_image		*image;
	t_player	*player;

	player = ft_malloc_player(params);
	params->player = player;
	image = ft_malloc_image(params);
	params->image = image;
	if (!(sprites = malloc(sizeof(*sp))))
		quit(MALLOC_ERROR, params);
	params->sprites = sprites;
	tex = ft_malloc_tex(params);
	params->tex = tex;
	search_params(params, fd);
}

void	ft_init_3(t_params *params)
{
	t_event		*event;
	t_ray		*ray;
	t_bmp		*bmp;

	event = ft_malloc_event(params);
	params->event = event;
	ft_resolution(params);
	ray = ft_malloc_ray(params);
	params->ray = ray;
	bmp = ft_malloc_bmp(params);
	params->bmp = bmp;
}

void	ft_init_game(t_params *params, int fd)
{
	ft_init(params);
	ft_init_2(params, params->sp, fd);
	ft_init_3(params);
}
