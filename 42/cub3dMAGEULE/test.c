/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:21:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/10 22:58:17 by chly-huc         ###   ########.fr       */
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
    void *mlx;
    void *window;
    t_keys *params;
    params = malloc(sizeof(t_keys));
    mlx = mlx_init();
    window = mlx_new_window(mlx, 1000, 1000, "Title");
    
    int i = 0;

    while(i++ < 100)
        mlx_pixel_put(mlx, window, 100, i, 255);
    //mlx_hook(window, 2, 1L << 0, key, params);
    mlx_hook(window, 2, 1L << 0, key_pressed, params);
    mlx_hook(window, 3, 1L << 1, key_released, params);
    //mlx_key_hook(window, which_key, params);
    mlx_loop(mlx);
    return (0);
}