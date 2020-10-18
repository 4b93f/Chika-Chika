/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:05:55 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 23:41:39 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save(t_params *params, t_bmp *bmp)
{
    
    char HEADER[54] = {};
    memcpy(HEADER, bmp->filetype, 2);
    memcpy(HEADER + 2, &bmp->filesize, 4);
    memcpy(HEADER + 10, &bmp->pixeldataoffset, 4);
    memcpy(HEADER + 14, &bmp->headersize, 4);
    memcpy(HEADER + 18, &bmp->img_width, 4);
    memcpy(HEADER + 22, &bmp->img_height, 4);
    memcpy(HEADER + 26 , &bmp->planes, 2);
    memcpy(HEADER + 28, &bmp->bpp, 4);
    memcpy(HEADER + 34, &bmp->imgsize, 4);
    bmp->fd = open("test.bmp", O_WRONLY | O_CREAT, S_IRWXU);
    write(bmp->fd, HEADER, 54);
    write(bmp->fd, params->image->imgdata, bmp->imgsize);
    exit(0);
}

void parameters(t_params *params, int argc, char **argv)
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
