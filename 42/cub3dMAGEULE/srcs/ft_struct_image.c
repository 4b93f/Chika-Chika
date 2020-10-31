/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:40:28 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 23:33:39 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	ft_create_image(void)
{
	t_image	image;

	image.img_width = 0;
	image.img_height = 0;
	image.save = 0;
	image.img = NULL;
	image.imgdata = NULL;
	image.imgsave = NULL;
	return (image);
}

t_image	*ft_malloc_image(void)
{
	t_image	*malloc_image;

	malloc_image = malloc(sizeof(t_image));
	*malloc_image = ft_create_image();
	return (malloc_image);
}
