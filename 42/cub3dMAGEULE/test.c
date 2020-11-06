/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:03:59 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/06 16:21:00 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int main(void)
{
    
    char **tex[4];
    char *ok;

    void *mlx_ptr;
    int bpp;
    int sizeline;
    int endian;
    void *mlx;
    char *mlxdata;
    int width;
    void *win;
    int height;
    
    mlx_ptr = mlx_init();
    win = mlx_new_window(mlx_ptr, 1000, 1000, "oui"); 
	mlx = mlx_xpm_file_to_image(mlx, "./textures/south.xpm", &width, &height);
	//mlxdata = mlx_get_data_addr(mlx, &bpp, &sizeline, &endian);
	//ok = mlxdata;
    mlx_put_image_to_window(mlx_ptr, win, mlx, 0, 0);
    mlx = mlx_xpm_file_to_image(mlx, "./textures/north.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win, mlx, 500, 500);
    mlx_loop(mlx_ptr);
    
}