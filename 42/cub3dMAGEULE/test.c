/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:21:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/16 23:35:40 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

typedef struct  s_keys
{
  int           a:1;
  int           s:1;
  int           d:1;

}               t_keys;

int key_pressed(int key, void *params)
{
    if (key == 13)
        printf("W\n");
    if (key == 0)
        printf("A\n");
    if (key == 1)
        printf("S\n");
    if (key == 2)
        printf("D\n");
    if (key == 53)
        exit(0); 
    return(0);
}

int key_released(int key, void *params)
{
    //printf("COULER\n");        
    return(0);
}

/*
int which_key(int key, void *params)
{
    if (key == 13)
        printf("W\n");
    return(0);
}
*/

int     main(void)
{
    /*
    void    *mlx;
    void    *img;
    void    *window;
    char    *relative_path = "./textures/east.xpm";
    int     img_width;
    int     img_height;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 2000, 2000, "ok");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    printf("%s\n", img);    
    mlx_put_image_to_window(mlx, window, img, 0,0);
   
    mlx_loop(mlx);
    */
   double x = 3.8;

   round(x);
}

