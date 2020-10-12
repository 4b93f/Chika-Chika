/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/12 17:34:40 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define txtH 64
#define txtW 64

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

}

void reset_image(t_params *params)
{
    int x = 0;
    int y = 0;
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    
    while(x < (params->screenwidth * params->screenheight))
    {
        params->image->imgdata[x * 4 + y * params->image->sizeline] = r;
        params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = g;
        params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = b;
        x++;
    }
}


void ft_error()
{
    printf("error\n");
    exit(0);
}

void ft_resolution(t_params *params)
{
    char **tmp; 
    int res_x;
    int res_y;
    
    tmp = ft_split(params->res, ' ');
    //mlx_get_screen_size(params->ray->mlx, &res_x, &res_y);
    params->screenwidth = ft_atoi(tmp[0]);
    params->screenheight = ft_atoi(tmp[1]);
    //params->screenwidth = params->screenwidth > res_x ? res_x : params->screenwidth;
    //params->screenheight = params->screenheight > res_y ? res_y : params->screenheight;
    return;
}

void AVANCE(t_params *params)
{
    //printf("pos joueur = {%f} {%f}\n ", params->ray->posX, params->ray->posY);
    if(params->map[(int)(params->ray->posX + params->ray->dirX * params->ray->movespeed)][(int)params->ray->posY] == '0' && 
    params->map[(int)(params->ray->posX + params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0' && 
    params->map[(int)(params->ray->posX + params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0')
    {
        params->ray->posX += params->ray->dirX * 0.1;
    }
    if(params->map[(int)params->ray->posX][(int)(params->ray->posY + params->ray->dirY * params->ray->movespeed)] == '0' && 
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY + 0.01 + params->ray->dirY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY - 0.01 + params->ray->dirY * params->ray->movespeed)] == '0')
    {
        params->ray->posY += params->ray->dirY * 0.1;
    }
    reset_image(params);
}

void RECULE(t_params *params)
{   
    if(params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)params->ray->posY]== '0' && 
    params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0' &&
    params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0')
         params->ray->posX -= params->ray->dirX * 0.1;

    if(params->map[(int)params->ray->posX][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)]== '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)]== '0' &&
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)]== '0')
        params->ray->posY -= params->ray->dirY * 0.1;
    reset_image(params);
}
        
void STRAFE_GAUCHE(t_params *params)
{
    if (params->map[(int)(params->ray->posX - params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY)] == '0' &&
    params->map[(int)(params->ray->posX - params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0' &&
    params->map[(int)(params->ray->posX - params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0')
        params->ray->posX -=  params->ray->planeX * 0.1;
    if (params->map[(int)params->ray->posX][(int)(params->ray->posY - params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY - params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY - params->ray->planeY * params->ray->movespeed)] == '0')
        params->ray->posY -=  params->ray->planeY * 0.1;
    reset_image(params);
}

void STRAFE_DROITE(t_params *params)
{
    if (params->map[(int)(params->ray->posX + params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY)] == '0' && 
    params->map[(int)(params->ray->posX + params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0' &&
    params->map[(int)(params->ray->posX + params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0')
        params->ray->posX += params->ray->planeX * 0.1;
    if (params->map[(int)params->ray->posX][(int)(params->ray->posY + params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY + params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY + params->ray->planeY * params->ray->movespeed)] == '0')
         params->ray->posY += params->ray->planeY * 0.1;
    reset_image(params);
}

void GAUCHE(t_params *params)
{
    double olddirx;
    double oldplanex;
    olddirx = params->ray->dirX;
    oldplanex = params->ray->planeX;

    params->ray->dirX =  params->ray->dirX * cos(-params->ray->rotspeed) - params->ray->dirY * sin (-params->ray->rotspeed);
    params->ray->dirY = olddirx * sin(-params->ray->rotspeed) + params->ray->dirY * cos(-params->ray->rotspeed);
    params->ray->planeX = params->ray->planeX * cos(-params->ray->rotspeed) - params->ray->planeY * sin(-params->ray->rotspeed);
    params->ray->planeY = oldplanex * sin(-params->ray->rotspeed) + params->ray->planeY * cos(-params->ray->rotspeed);
    reset_image(params);
}

void DROITE(t_params *params)
{
    double olddirx;
    double oldplanex;
    olddirx = params->ray->dirX;
    oldplanex = params->ray->planeX;

    params->ray->dirX =  params->ray->dirX * cos(params->ray->rotspeed) - params->ray->dirY * sin (params->ray->rotspeed);
    params->ray->dirY = olddirx * sin(params->ray->rotspeed) + params->ray->dirY * cos(params->ray->rotspeed);
    params->ray->planeX = params->ray->planeX * cos(params->ray->rotspeed) - params->ray->planeY * sin(params->ray->rotspeed);
    params->ray->planeY = oldplanex * sin(params->ray->rotspeed) + params->ray->planeY * cos(params->ray->rotspeed);
    reset_image(params);
}

int key_pressed(int key_pressed, t_params *params)
{
    //printf("%d\n", key_pressed);
    if (key_pressed == 13) 
        params->event->up = 1;
    if (key_pressed == 1)
        params->event->down = 1;
    if (key_pressed == 0)
        params->event->strafe_gauche = 1;
    if (key_pressed == 2)
        params->event->strafe_droite = 1;
    if (key_pressed == 123)
        params->event->left = 1;
    if (key_pressed == 124)
        params->event->right = 1;
    if (key_pressed == 53)
        exit(0);
    return(0);
}

int key_released(int key_released, t_params *params)
{
    if (key_released == 13)
        params->event->up = 0;
    if (key_released == 1)
        params->event->down = 0;
    if (key_released == 0)
        params->event->strafe_gauche = 0;
    if (key_released == 2)
        params->event->strafe_droite = 0;
    if (key_released == 123)
        params->event->left = 0;
    if (key_released == 124)
        params->event->right = 0;

    return(0);
}

void key_event(t_params *params)
{
    if (params->event->up == 1)
        AVANCE(params);
    if (params->event->down == 1)
        RECULE(params);
    if(params->event->strafe_gauche == 1)
        STRAFE_GAUCHE(params);
    if (params->event->strafe_droite == 1)
        STRAFE_DROITE(params);
    if (params->event->left == 1)
        GAUCHE(params);
    if (params->event->right == 1)
        DROITE(params);
}

int mouse_event(t_params *params)
{
    exit(0);
}

int start(t_params *params)
{
    //printf("!!!!!\n");
    ft_raycast(params, params->ray, params->color);
    if (params->image->save == 1)
        save(params);
    mlx_put_image_to_window(params->ray->mlx, params->ray->window, params->image->img, 0,0);
    key_event(params);
    return(1);
}

void ft_getposray(char **map, t_ray *ray)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
            {
                ray->posX = i;
                ray->posY = j;
                map[i][j] = '0';
            }
            j++;
        }
        j = 0;
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exit(0);
    int fd;
    fd = open(argv[1], O_RDONLY);
    t_params *params;
    t_ray *ray;
    t_color *color;
    t_image *image;
    t_event *event;
    t_tex *tex;
    t_sprite *sp;
    
        
    params = ft_malloc_params();
    color = ft_malloc_color();
    event = ft_malloc_event();
    image = ft_malloc_image();
    sp = ft_malloc_sprite();
    tex = ft_malloc_tex();
    params->color = color;
    if (search_params(params, fd) == 0)
        ft_error();
    ft_resolution(params);
    ray = ft_malloc_ray(params);
    params->ray = ray;
    params->event = event;
    params->image = image;
    params->tex = tex;
    params->sp = sp;
    ft_get_tex(params);
    ft_get_sprite(params, "./textures/pillar.xpm");
    image->img = mlx_new_image(ray->mlx, params->screenwidth, params->screenheight);
    image->imgdata = mlx_get_data_addr(image->img, &image->bpp, &image->sizeline, &image->endian);
    image->imgsave = mlx_get_data_addr(image->img, &image->bpp, &image->sizeline, &image->endian);
    
    if (argv[2] != NULL && strncmp(argv[2], "--save", 4) == 0)
        params->image->save = 1;
    if (params->map_find == 0)
        ft_error();
    if (ft_check_map(params->map) == 0)
        ft_error();
    ft_getposray(params->map, ray);
    mlx_hook(ray->window, 2, 1L << 0, key_pressed, params);
    mlx_hook(ray->window, 3, 1L << 0, key_released, params);
    mlx_hook(ray->window, 17, 1L << 17, mouse_event, params);
    mlx_loop_hook(ray->mlx, start, params);
    if(!(mlx_loop(ray->mlx) == 0))
        exit(0);
    //ft_free_struct(params);
}
