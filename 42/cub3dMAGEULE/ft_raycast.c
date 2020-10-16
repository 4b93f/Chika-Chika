/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/10/16 17:55:07 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A CHANGER //

#define txtH 64
#define txtW 64
//#define params->sp->numsprite 
#include "cub3d.h"


void ft_pixel_to_image(int x, int y, t_params *params)
{
    params->image->imgdata[x * 4 + y * params->image->sizeline + 0] = params->color->b;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = params->color->g;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = params->color->r;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 3] = params->color->a;
}

void ft_sprite_to_image(int x, int y, t_params *params, int Y, int X)
{
    int isblack;

    isblack = params->sp->spdata[x * 4 + y * params->sp->sizeline + 1] + params->sp->spdata[x * 4 + y * params->sp->sizeline + 2] + params->sp->spdata[x * 4 + y * params->sp->sizeline + 3];
    /*
    params->image->imgdata[x * 4 + y * params->image->sizeline + 0] = params->color->b;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = params->color->g;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = params->color->r;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 3] = params->color->a;
    */
    //printf("ok\n");
if (isblack)
    {
        params->image->imgdata[X * 4 + Y * params->image->sizeline + 0] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 0];
        params->image->imgdata[X * 4 + Y * params->image->sizeline + 1] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 1];
        params->image->imgdata[X * 4 + Y * params->image->sizeline + 2] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 2];
        params->image->imgdata[X * 4 + Y * params->image->sizeline + 3] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 3];
    }
    
}

void verline(int x, int drawstart, int drawend, t_params *params)
{
    while (++drawstart <= drawend)
        ft_pixel_to_image(x, drawstart, params);
}

void test(t_params *params, t_ray *ray, t_color *color, int x);


void sortSprites(t_params *params)
{
    double first;
    double second;
    int i;
    t_sprite tmp;

    i = 0;
    while(i < params->sp->numsprite && i + 1 != params->sp->numsprite)
    {
        first = ((params->ray->posX - params->sprites[i].x) * (params->ray->posX - params->sprites[i].x) + (params->ray->posY - params->sprites[i].y) * (params->ray->posY - params->sprites[i].y));
        second = ((params->ray->posX - params->sprites[i + 1].x) * (params->ray->posX - params->sprites[i + 1].x) + (params->ray->posY - params->sprites[i + 1].y) * (params->ray->posY - params->sprites[i + 1].y));
        if (first < second)
        {
            tmp = params->sprites[i];
            params->sprites[i] = params->sprites[i + 1];
            params->sprites[i + 1] = tmp;
            i = 0;    
        }
        else
            i++;
    }
}


void ft_raycast(t_params *params,t_ray *ray, t_color *color)
{
    int x;
    int texnum = 0;
    void *txt;
    
    x = 0;
    double texpos = 0;;
    double step = 0;;
    int texy = 0;
    int y = 0;
    int texx = 0;
    double zbuffer[params->screenwidth];
    int a = 0;
    int tx = 0;
    int ty = 0;
    int o = 0;
    while(params->map[o])
    {
        //printf("{%s}\n", params->map[o]);
        o++;
    }
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
            }
            else
            {
                ray->sidedistY += ray->deltadistY;
                ray->mapY += ray->stepY;
                ray->side = 1;
                texnum = ray->raydirY < 0 ? 1 : 0;
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
        zbuffer[x] = params->ray->perpwalldist;
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
            ft_pixel_to_image(x, cell, params);
            cell++;
        }
    }
        int sprite_order[params->sp->numsprite];    
        double sprite_distance[params->sp->numsprite];
        sortSprites(params);
        
        int i = 0;
        while(i < params->sp->numsprite)
        {
            sprite_order[i] = i;
            sprite_distance[i] = ((params->ray->posX - params->sprites[i].x) * (params->ray->posX - params->sprites[i].x) * (params->ray->posY - params->sprites[i].y));
            i++;
        }
        i = 0;
        while(i < params->sp->numsprite)
        {
            double spriteX = params->sprites[i].x - params->ray->posX - 0.5;
            double spriteY = params->sprites[i].y - params->ray->posY - 0.5;
            
            double invdet = 1.0 / (params->ray->planeX * params->ray->dirY - params->ray->dirX * params->ray->planeY);
            double transformX = invdet * (params->ray->dirY * spriteX - params->ray->dirX * spriteY);
            double transformY = invdet * (-params->ray->planeY * spriteX + params->ray->planeX * spriteY);
            int sprite_screenX = (int)((params->screenwidth / 2) * (1 + transformX / transformY));
            int sprite_height = abs((int)(params->screenheight / transformY));
            int drawstartY = -sprite_height / 2 + params->screenheight / 2;
            if (drawstartY < 0)
                drawstartY = 0;
            int drawendY = sprite_height / 2 + params->screenheight / 2;
            if (drawendY >= params->screenheight)
                drawendY = params->screenheight - 1;

            int sprite_width = abs((int)(params->screenheight / transformY));
            int drawstartX = -sprite_width / 2 + sprite_screenX;
            if (drawstartX < 0)
                drawstartX = 0;
            int drawendX = sprite_width / 2 + sprite_screenX;
            if (drawendX >= params->screenwidth)
                drawendX = params->screenwidth - 1;
            int X = drawstartX;
            
            while(X < drawendX)
            {
                int spX = (int)(256 * (X - (-sprite_width / 2 + sprite_screenX)) * txtW / sprite_width) / 256;
                if (transformY > 0 && X > 0 && X < params->screenwidth && transformY < zbuffer[X])
                {
                    for(int Y = drawstartY; Y < drawendY; Y++)
                    {
                        int d = Y * 256 - params->screenheight * 128 + sprite_height * 128;
                        int spY = ((d * txtH) / sprite_height) / 256;
                        ft_sprite_to_image(spX, spY, params, Y, X);
                    }
                }
                X++;
            }
            i++;
        }
        return;
    }