/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:03:43 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/31 15:42:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player	ft_create_player(void)
{
	t_player player;

	player.posX = 0;
	player.posY = 0;
	player.dirX = 0;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0;
	player.rotspeed = 0.10;
	player.movespeed = 0.40;
	player.camX = 0;
	return (player);
}

t_player	*ft_malloc_player(void)
{
	t_player *malloc_player;

	malloc_player = malloc(sizeof(t_player));
	*malloc_player = ft_create_player();
	return (malloc_player);
}
