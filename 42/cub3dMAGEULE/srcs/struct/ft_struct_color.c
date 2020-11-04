/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:07:25 by becentrale        #+#    #+#             */
/*   Updated: 2020/11/04 20:44:00 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_color	ft_create_color(void)
{
	t_color color;

	color.a = 0;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	color.cell_r = 0;
	color.cell_g = 0;
	color.cell_b = 0;
	color.cell_index = 0;
	color.floor_r = 0;
	color.floor_g = 0;
	color.floor_b = 0;
	color.floor_index = 0;
	return (color);
}

t_color	*ft_malloc_color(void)
{
	t_color *malloc_color;

	if (!(malloc_color = malloc(sizeof(t_color))))
		ft_error(MALLOC_ERROR);
	*malloc_color = ft_create_color();
	return (malloc_color);
}
