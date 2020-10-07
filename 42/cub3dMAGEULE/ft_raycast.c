/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/10/07 21:28:53 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// A CHANGER //

#define txtH 64
#define txtW 64
#include "cub3d.h"

void ft_pixel_to_image(int x, int y, t_params *params)
{
    //printf("!");
    params->image->imgdata[x * 4 + y * params->image->sizeline + 0] = params->color->b;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = params->color->g;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = params->color->r;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 3] = params->color->a;
}

void verline(int x, int drawstart, int drawend, t_params *params)
{
    while (++drawstart <= drawend)
        ft_pixel_to_image(x, drawstart, params);
}

/*
void tmp(t_params *params)
{
    numsprite = 19
    double zbuffer[screenwidth];
    int sprite_order[numsprite];
    double sprite_distance[numsprite];
    void sort_sprites(int * order, double *dist, int amount);

    
}


*/



void ft_raycast(t_params *params,t_ray *ray, t_color *color)
{

    int x;
    int texnum = 0;
    void *txt;
    
    x = 0;
    double texpos;
    double step;
    int texy = 0;
    int y;
    int texx;
    //printf("oui = %d\n", params->screenheight);
    while(++x < params->screenwidth)
    {
        ray->hit = 0;
        ray->camX = (2 * x) / (double)(params->screenwidth) - 1;
        ray->raydirX = ray->dirX + ray->planeX * ray->camX;
        ray->raydirY = ray->dirY + ray->planeY * ray->camX;
        ray->mapX = (int)ray->posX;
        ray->mapY = (int)ray->posY;
        ray->deltadistX = (ray->raydirY == 0) ? 0 : ((ray->raydirX == 0) ? 1 : fabs(1 / ray->raydirX));
        ray->deltadistY = (ray->raydirX == 0) ? 0 : ((ray->raydirY == 0) ? 1 : fabs(1 / ray->raydirY));
        if (ray->raydirX < 0)
        {
            ray->stepX = -1;
            ray->sidedistX = (ray->posX - ray->mapX) * ray->deltadistX;
        }
        else
        {
            ray->stepX = 1;
            ray->sidedistX = (ray->mapX + 1.0 - ray->posX) * ray->deltadistX;
        } 
        if (ray->raydirY < 0)
        {
            ray->stepY = - 1;
            ray->sidedistY = (ray->posY - ray->mapY) * ray->deltadistY;
        }
        else
        {
            ray->stepY = 1;
            ray->sidedistY = (ray->mapY + 1.0 - ray->posY) * ray->deltadistY;
        }
        while (ray->hit == 0)
        {
            if (ray->sidedistX < ray->sidedistY)
            {
                ray->sidedistX += ray->deltadistX;
                ray->mapX += ray->stepX;
                ray->side = 0;
                texnum = ray->raydirX < 0 ? 2 : 3;
            //si ray x < 0 alors load texture 0 sinon texture 2
            }
            else
            {
                ray->sidedistY += ray->deltadistY;
                ray->mapY += ray->stepY;
                ray->side = 1;
                texnum = ray->raydirY < 0 ? 1 : 0;
            //si ray y < 0 alors load texture 1 sinon texture 3
            }
            if (params->map[ray->mapX][ray->mapY] == '1') 
                ray->hit = 1;
        }
        if (ray->side == 0)
            ray->perpwalldist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->raydirX;
        else
            ray->perpwalldist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->raydirY;
        ray->lineheight = (params->screenheight / ray->perpwalldist);
        ray->drawstart = (-ray->lineheight / 2 + (params->screenheight / 2));
        if (ray->drawstart < 0)
            ray->drawstart = 0;
        ray->drawend = ray->lineheight / 2 + (int)params->screenheight / 2;
        if (ray->drawend >= params->screenheight)
            ray->drawend = params->screenheight - 1;
        
        double wallx;
        if(params->ray->side == 0)
            wallx = params->ray->posY + params->ray->perpwalldist * params->ray->raydirY;
        else
            wallx = params->ray->posX + params->ray->perpwalldist * params->ray->raydirX;
        wallx -= floor((wallx));
        
        texx = (int)(wallx * (double)txtW);
        if (params->ray->side == 0 && params->ray->raydirX > 0)
            texx = txtW - texx - 1;
        if (params->ray->side == 1 && params->ray->raydirY < 0)
            texx = txtW - texx - 1;
            
        y = params->ray->drawstart - 1;
        
        step = 1.0 * txtH / params->ray->lineheight;
        texpos = (params->ray->drawstart - params->screenheight / 2 + params->ray->lineheight / 2) * step;
        //printf("X");


        int floor = 0;
        int cell = params->ray->drawend;
        while(floor < params->ray->drawstart)
        {        
            params->color->b = params->color->floor_b;
            params->color->g = params->color->floor_g;
            params->color->r = params->color->floor_r;
            params->color->a = (unsigned char)0;
            ft_pixel_to_image(x, floor, params);
            floor++;
                
        }
        while(y++ < params->ray->drawend)
        {
            params->color->b = params->tex->tex[texnum][texx * 4 + texy * params->tex->sizeline + 0];
            params->color->g = params->tex->tex[texnum][texx * 4 + texy * params->tex->sizeline + 1];
            params->color->r = params->tex->tex[texnum][texx * 4 + texy * params->tex->sizeline + 2];
            params->color->a = params->tex->tex[texnum][texx * 4 + texy * params->tex->sizeline + 3];
            ft_pixel_to_image(x, y, params);
            texy = (int)texpos;
            texpos += step;
        }
        while(cell < params->screenheight)
        {
            params->color->b = params->color->cell_b;
            params->color->g = params->color->cell_g;
            params->color->r = params->color->cell_r;
            params->color->a = (unsigned char)0;
            ft_pixel_to_image(x, cell, params);
            cell++;            
        }
        printf("!!!!\n");
    }
    return;
    
}