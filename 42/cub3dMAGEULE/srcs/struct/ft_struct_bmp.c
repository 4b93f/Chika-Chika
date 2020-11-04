/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:36:05 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/04 20:39:51 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bmp	ft_create_bmp(t_params *params)
{
	t_bmp bmp;

	bmp.fd = 0;
	bmp.filetype = "BM";
	bmp.headersize = 40;
	bmp.img_height = params->screenheight;
	bmp.img_width = params->screenwidth;
	bmp.bpp = 32;
	bmp.bytes_in_width = (bmp.img_width * bmp.bpp + 31) / 32 * 4;
	bmp.planes = 1;
	bmp.imgsize = bmp.img_height * bmp.bytes_in_width;
	bmp.pixeldataoffset = 54;
	bmp.filesize = 54 + bmp.imgsize;
	return (bmp);
}

t_bmp	*ft_malloc_bmp(t_params *params)
{
	t_bmp *malloc_bmp;

	if (!(malloc_bmp = malloc(sizeof(t_bmp))))
		ft_error(MALLOC_ERROR);
	*malloc_bmp = ft_create_bmp(params);
	return (malloc_bmp);
}
