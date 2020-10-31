/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:28:12 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/30 17:20:05 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parameters(t_params *params, int argc, char **argv)
{
	if (argc == 3)
	{
		if (strncmp(argv[2], "--save", 5) == 0)
			params->image->save = 1;
		else
			ft_error(ERROR_ARGUMENT);
	}
	else if (argc == 2)
		return ;
	else
		ft_error(ERROR_ARGUMENT);
}

void	save(t_params *params)
{
	char header[54];

	memcpy(header, params->bmp->filetype, 2);
	memcpy(header + 2, &params->bmp->filesize, 4);
	memcpy(header + 10, &params->bmp->pixeldataoffset, 4);
	memcpy(header + 14, &params->bmp->headersize, 4);
	memcpy(header + 18, &params->bmp->img_width, 4);
	memcpy(header + 22, &params->bmp->img_height, 4);
	memcpy(header + 26, &params->bmp->planes, 2);
	memcpy(header + 28, &params->bmp->bpp, 4);
	memcpy(header + 34, &params->bmp->imgsize, 4);
	params->bmp->fd = open("SS.bmp", O_WRONLY | O_CREAT, S_IRWXU);
	write(params->bmp->fd, header, 54);
	write(params->bmp->fd, params->image->imgdata, params->bmp->imgsize);
	exit(0);
}
