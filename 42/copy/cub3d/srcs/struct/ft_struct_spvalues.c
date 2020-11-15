/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_spvalues.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:50:16 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/15 18:50:24 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_spvalues	ft_create_spvalues(void)
{
	t_spvalues	sv;

	sv.invdet = 0;
	sv.y = 0;
	sv.j = 0;
	sv.transformx = 0;
	sv.transformy = 0;
	sv.sprite_screenx = 0;
	sv.sprite_height = 0;
	sv.sprite_width = 0;
	sv.drawstartx = 0;
	sv.drawstarty = 0;
	sv.drawendx = 0;
	sv.drawendy = 0;
	sv.x = 0;
	sv.spx = 0;
	sv.spy = 0;
	return (sv);
}

t_spvalues			*ft_malloc_spvalues(t_params *params)
{
	t_spvalues	*malloc_spvalues;

	if (!(malloc_spvalues = malloc(sizeof(t_spvalues))))
		quit(MALLOC_ERROR, params);
	*malloc_spvalues = ft_create_spvalues();
	return (malloc_spvalues);
}

void				ft_free_spvalues(t_spvalues *to_free)
{
	free(to_free);
}
