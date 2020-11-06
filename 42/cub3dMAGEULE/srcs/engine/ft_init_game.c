/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:19:44 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/06 21:17:12 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init(t_params *params)
{
	t_color			*color;
	t_draw_sprite	*sp;
	t_spvalues		*sv;

	color = ft_malloc_color();
	sp = ft_malloc_sprite(params);
	params->sp = sp;
	sv = ft_malloc_spvalues();
	params->sv = sv;
	params->color = color;
}

void	ft_init_2(t_params *params, t_draw_sprite *sp, int fd)
{
	t_sprite	*sprites;
	t_tex		*tex;
	t_image		*image;
	t_player	*player;

	player = ft_malloc_player();
	params->player = player;
	image = ft_malloc_image();
	params->image = image;
	if (!(sprites = malloc(sizeof(*sp))))
		ft_error(MALLOC_ERROR);
	params->sprites = sprites;
	tex = ft_malloc_tex();
	params->tex = tex;
	search_params(params, fd);
}

void	ft_init_3(t_params *params)
{
	t_event		*event;
	t_bmp		*bmp;
	t_ray		*ray;

	event = ft_malloc_event();
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
