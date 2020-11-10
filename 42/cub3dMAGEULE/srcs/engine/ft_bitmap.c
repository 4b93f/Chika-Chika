/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:28:12 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/10 21:37:35 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parameters(t_params *params, int argc, char **argv)
{
	if (argc > 1 && argc < 4)
	{
		if (argc == 3)
		{
			if (ft_strncmp(argv[2], "--save", 6) == 0)
				params->image->save = 1;
			else
				ft_error(params, ERROR_ARGUMENT);
		}
	}
	else
		ft_error(params, ERROR_ARGUMENT);
}

/*
void	reverse(t_params *params)
{
	int		x;
	int		y;
	int max = params->screenwidth * params->screenheight - 1;
	//int color = 0;
	x = 0;
	y = 0;
	int temp;
	printf("%d\n", params->image->sizeline);
	while (x < (params->screenwidth * params->screenheight) / 2)
	{
		temp = params->image->imgdata[(max) * 4 + y + 0];
		params->image->imgdata[(max) * 4 + y + 0] = params->image->imgdata[x * 4 + y + 0];
		params->image->imgdata[x * 4 + y + 0] = temp;

		temp = params->image->imgdata[(max) * 4 + y + 1];
		params->image->imgdata[(max) * 4 + y + 1] = params->image->imgdata[x * 4 + y + 1];
		params->image->imgdata[x * 4 + y + 1] = temp;
		
		temp = params->image->imgdata[(max) * 4 + y + 2];
		params->image->imgdata[(max) * 4 + y + 2] = params->image->imgdata[x * 4 + y + 2];
		params->image->imgdata[x * 4 + y + 2] = temp;
		x++;
		max--;
	}
}
*/

void	reverse(t_params *params)
{
	int		x;
	int		y;
	int max = params->screenwidth * params->screenheight - 1;
	//int color = 0;
	x = 0;
	y = 0;
	int temp;
	printf("%d\n", params->image->sizeline);

	while (x < params->screenwidth / 4)
	{
		temp = params->image->imgdata[(max) * 4 + y + 0];
		params->image->imgdata[(max) * 4 + y + 0] = params->image->imgdata[x * 4 + y + 0];
		params->image->imgdata[x * 4 + y + 0] = temp;

		temp = params->image->imgdata[(max) * 4 + y + 1];
		params->image->imgdata[(max) * 4 + y + 1] = params->image->imgdata[x * 4 + y + 1];
		params->image->imgdata[x * 4 + y + 1] = temp;
			
		temp = params->image->imgdata[(max) * 4 + y + 2];
		params->image->imgdata[(max) * 4 + y + 2] = params->image->imgdata[x * 4 + y + 2];
		params->image->imgdata[x * 4 + y + 2] = temp;
		x++;
		max--;
	}
}

void	save(t_params *params)
{
	static unsigned char header[54] = {0};

	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &params->bmp->filesize, 4);
	ft_memcpy(header + 10, &params->bmp->pixeldataoffset, 4);
	ft_memcpy(header + 14, &params->bmp->headersize, 4);
	ft_memcpy(header + 18, &params->bmp->img_width, 4);
	ft_memcpy(header + 22, &params->bmp->img_height, 4);
	ft_memcpy(header + 26, &params->bmp->planes, 2);
	ft_memcpy(header + 28, &params->bmp->bpp, 2);
	ft_memcpy(header + 34, &params->bmp->imgsize, 4);
	params->bmp->fd = open("SS.bmp", O_WRONLY | O_CREAT, S_IRWXU);
	write(params->bmp->fd, header, 54);
	reverse(params);
	write(params->bmp->fd, params->image->imgsave, params->bmp->imgsize);
	close(params->bmp->fd);
	free_struct(params);
	exit(0);
}
