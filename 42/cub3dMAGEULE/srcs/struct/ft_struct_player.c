/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:03:43 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/01 17:53:49 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player	ft_create_player(void)
{
	t_player player;

	player.posx = 0;
	player.posy = 0;
	player.dirx = 0;
	player.diry = 0;
	player.planex = 0;
	player.planey = 0;
	player.rotspeed = 0.10;
	player.movespeed = 0.40;
	player.camx = 0;
	return (player);
}

t_player	*ft_malloc_player(void)
{
	t_player *malloc_player;

	malloc_player = malloc(sizeof(t_player));
	*malloc_player = ft_create_player();
	return (malloc_player);
}
