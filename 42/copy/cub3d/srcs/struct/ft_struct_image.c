/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:40:28 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/15 18:49:04 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_image	ft_create_image(void)
{
	t_image	image;

	image.bpp = 0;
	image.sizeline = 0;
	image.endian = 0;
	image.img_width = 0;
	image.img_height = 0;
	image.save = 0;
	image.img = NULL;
	image.imgdata = NULL;
	image.imgsave = NULL;
	return (image);
}

t_image			*ft_malloc_image(t_params *params)
{
	t_image	*malloc_image;

	if (!(malloc_image = malloc(sizeof(t_image))))
		quit(MALLOC_ERROR, params);
	*malloc_image = ft_create_image();
	return (malloc_image);
}
