/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:05:55 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 22:59:13 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save(t_params *params)
{
    int fd;
    char *filetype = "BM";
    unsigned int headersize = 40;
    int img_height = params->screenwidth;
    int img_width = params->screenheight;
    unsigned int bpp = 32;
    int bytes_in_width = ((img_width * bpp + 31) / 32) * 4;
    unsigned int planes = 1;
    unsigned int compression = 0;
    unsigned int imgsize = bytes_in_width * img_height;
    unsigned int pixeldataoffset = 54;
    unsigned int filesize = 54 + imgsize;
    
    char HEADER[54] = {};
    memcpy(HEADER, filetype, 2);
    memcpy(HEADER + 2, &filesize, 4);
    memcpy(HEADER + 10, &pixeldataoffset, 4);
    memcpy(HEADER + 14, &headersize, 4);
    memcpy(HEADER + 18, &img_width, 4);
    memcpy(HEADER + 22, &img_height, 4);
    memcpy(HEADER + 26 , &planes, 2);
    memcpy(HEADER + 28, &bpp, 4);
    memcpy(HEADER + 34, &imgsize, 4);
    fd = open("test.bmp", O_WRONLY | O_CREAT, S_IRWXU);
    write(fd, HEADER, 54);
    write(fd, params->image->imgdata, imgsize);
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
