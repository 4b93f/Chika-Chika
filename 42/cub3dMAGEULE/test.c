/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:21:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/24 02:38:28 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
void	ft_bzero(void *b, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (n--)
		*str++ = '\0';
	return ;
}

int     main(void)
{
    
    void    *mlx;
    void    *img1;
    void    *img2;
    void    *window;
    char    *relative_path1 = "./textures/east.xpm";
    char    *relative_path2 = "./textures/north.xpm";
    int     img_width;
    int     img_height;
    void *texture[8];
    

    mlx = mlx_init();
    window = mlx_new_window(mlx, 1000, 1000, "ok");
    texture[0] = mlx_xpm_file_to_image(mlx, relative_path1, &img_width, &img_height);
    texture[1] = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
    img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
    img1 = texture[0];
    img2 = texture[1];

    mlx_put_image_to_window(mlx, window, img2, 500,500);
    system("leaks a.out");
    mlx_loop(mlx);
}

*/
    
int main(void)
{
    int fd;
    char *filetype = "BM";
    unsigned int imgsize = 0;
    unsigned int filesize = 54 + imgsize;
    unsigned int headersize = 40;
    int img_width = 4;
    int img_height = 4;
    unsigned int planes = 1;
    unsigned int bpp = 32;
    unsigned int compression = 0;
    unsigned int pixeldataoffset = 54;
    
    char HEADER[54] = {};
    memcpy(HEADER, "BM", 2);
    memcpy(HEADER + 2, &filesize, 4);
    memcpy(HEADER + 10, &pixeldataoffset, 4);
    memcpy(HEADER + 14, &headersize, 4);
    memcpy(HEADER + 18, &img_width, 4);
    memcpy(HEADER + 22, &img_height, 4);
    memcpy(HEADER + 26 , &planes, 2);
    memcpy(HEADER + 28, &bpp, 4);
    
    fd = open("test.bpm", O_WRONLY | O_CREAT, S_IRUSR | S_IRWXU);
    write(fd, HEADER, 32);
    
    return 0;
}