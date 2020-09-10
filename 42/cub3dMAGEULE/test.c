/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:21:51 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/10 20:51:36 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int main()
{
    void *mlx;
    void *window;
  
    mlx = mlx_init();
    window = mlx_new_window(mlx, 1000, 1000, "Title");
    
    int i = 0;

    while(i++ < 100)
        mlx_pixel_put(mlx, window, 100, i, 255);
    mlx_loop(mlx);
    return (0);
}