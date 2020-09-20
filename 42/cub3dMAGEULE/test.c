/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:21:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/18 23:44:46 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

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

