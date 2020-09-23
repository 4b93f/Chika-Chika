/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:21:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/23 02:30:52 by chly-huc         ###   ########.fr       */
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
    int width = 4;
    int height = 4;
    unsigned int bitcount = 24;
    
    int width_in_bytes = ((width * bitcount + 31 / 32) * 4);
    unsigned int imagesize =width_in_bytes * height;
    const unsigned int bisize = 40;
    const unsigned int bfoofbits = 54;
    unsigned int filesize = 54 + imagesize;
    unsigned int biplanes = 1;

    unsigned char header[54] = {0};
    memcpy(header, "BM", 2);
    memcpy(header + 2 , &filesize, 4);
    memcpy(header + 10, &bfoofbits, 4);
    memcpy(header + 14, &bisize, 4);
    memcpy(header + 18, &width, 4);
    memcpy(header + 22, &height, 4);
    memcpy(header + 26, &biplanes, 2);
    memcpy(header + 28, &bitcount, 2);
    memcpy(header + 34, &imagesize, 4);
    
    unsigned char* buf = malloc(imagesize);
    for(int row = height - 1; row >= 0; row--)
    {
        for(int col = 0; col < width; col++)
        {
            buf[row * width_in_bytes + col * 3 + 0] = 255;//blue
            buf[row * width_in_bytes + col * 3 + 1] = 0;//green
            buf[row * width_in_bytes + col * 3 + 2] = 0;//red
        }
    }

    FILE *fout = fopen("test.bmp", "wb");
    fwrite(header, 1, 54, fout);
    fwrite((char*)buf, 1, imagesize, fout);
    fclose(fout);
    free(buf);

    return 0;
}