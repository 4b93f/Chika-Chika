/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:05:34 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/05 15:35:47 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_draw_sprite	ft_create_sprite(t_params *params)
{
	t_draw_sprite	sp;
	int				i;

	i = 0;
	sp.numsprite = 0;
	sp.sp_width = 0;
	sp.sp_height = 0;
	sp.x = 0;
	sp.y = 0;
	sp.sp = malloc(sizeof(char *) * 1);
	return (sp);
}

t_draw_sprite	*ft_malloc_sprite(t_params *params)
{
	t_draw_sprite			*malloc_sp;
	int						i;

	i = 0;
	malloc_sp = malloc(sizeof(t_draw_sprite));
	*malloc_sp = ft_create_sprite(params);
	return (malloc_sp);
}

void		ft_free_sprite(t_draw_sprite *to_free)
{
	int			i;

	i = -1;
	while (to_free->sp[++i])
		free(to_free->sp[i]);
	free(to_free->sp);
	free(to_free);
}
