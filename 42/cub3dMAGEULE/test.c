/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:21:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/16 01:50:29 by chly-huc         ###   ########.fr       */
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

int main()
{
    int bpp;
    int sizeline;
    int endian;
    void *mlx;
    void *window;
    void *img;
    int x;
    int a = 0;
    int y;

    x = 0;
    y = 0;
    unsigned char r;
    unsigned char g;
    unsigned char b;

    r = 255;
    g = 255;
    b = 0;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 1250, 1250, "Title");
    img = mlx_new_image(mlx, 1250, 1250);
    char *imgdata = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
    while(x < 1562500)
    {
        imgdata[x * 4 + y * sizeline] = r;
        imgdata[x * 4 + y * sizeline] = g;
        imgdata[x * 4 + y * sizeline] = r;
        x++;
    }
    printf("%d\n", sizeline);
    mlx_put_image_to_window(mlx, window, img, 0,0);
    mlx_loop(mlx);
    return (0);
}

