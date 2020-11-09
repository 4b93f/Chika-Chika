/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:19:44 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/09 18:13:43 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init(t_params *params, int fd)
{
	params->color = ft_malloc_color(params);
	params->sp = ft_malloc_sprite(params);
	params->sv = ft_malloc_spvalues(params);
	params->player = ft_malloc_player(params);
	params->image = ft_malloc_image(params);
	params->sprites = malloc(sizeof(params->sp) * 50);
	params->tex = ft_malloc_tex(params);
	search_params(params, fd);
	params->event = ft_malloc_event(params);
	ft_resolution(params);
	params->ray = ft_malloc_ray(params);
	params->bmp = ft_malloc_bmp(params);
}

void	ft_init_game(t_params *params, int fd)
{
	ft_init(params, fd);
}
