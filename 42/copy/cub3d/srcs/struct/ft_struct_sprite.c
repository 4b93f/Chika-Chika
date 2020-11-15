/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:05:34 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/15 18:50:16 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_draw_sprite	ft_create_sprite(t_params *params)
{
	t_draw_sprite	sp;

	sp.bpp = 0;
	sp.sizeline = 0;
	sp.endian = 0;
	sp.pos_sprite = NULL;
	sp.numsprite = 0;
	sp.sp_width = 0;
	sp.sp_height = 0;
	sp.x = 0;
	sp.y = 0;
	sp.mlx_sprite = NULL;
	if (!(sp.sp = malloc(sizeof(char *) * 1)))
		quit(MALLOC_ERROR, params);
	sp.sp[0] = NULL;
	return (sp);
}

t_draw_sprite			*ft_malloc_sprite(t_params *params)
{
	t_draw_sprite			*malloc_sp;

	if (!(malloc_sp = malloc(sizeof(t_draw_sprite))))
		quit(MALLOC_ERROR, params);
	*malloc_sp = ft_create_sprite(params);
	return (malloc_sp);
}

void					ft_free_sprite(t_draw_sprite *to_free)
{
	free(to_free->sp);
	free(to_free);
}
