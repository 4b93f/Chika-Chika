/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/10/11 19:30:34 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A CHANGER //

#define txtH 64
#define txtW 64
#define numsprite 1
#include "cub3d.h"

void ft_pixel_to_image(int x, int y, t_params *params)
{
    //printf("!");
    params->image->imgdata[x * 4 + y * params->image->sizeline + 0] = params->color->b;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = params->color->g;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = params->color->r;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 3] = params->color->a;
}

void ft_sprite_to_image(int x, int y, t_params *params, int Y, int stripe)
{
    /*
    params->image->imgdata[x * 4 + y * params->image->sizeline + 0] = params->color->b;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = params->color->g;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = params->color->r;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 3] = params->color->a;
    */
    //printf("ok\n");
    params->image->imgdata[stripe * 4 + Y * params->image->sizeline + 0] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 0];
    params->image->imgdata[stripe * 4 + Y * params->image->sizeline + 1] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 1];
    params->image->imgdata[stripe * 4 + Y * params->image->sizeline + 2] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 2];
    params->image->imgdata[stripe * 4 + Y * params->image->sizeline + 3] = params->sp->spdata[x * 4 + y * params->sp->sizeline + 3];
    
}

void verline(int x, int drawstart, int drawend, t_params *params)
{
    while (++drawstart <= drawend)
        ft_pixel_to_image(x, drawstart, params);
}

/*
void tmp(t_params *params, t_sprite *sp)
{
    ft_get_sprite(sp, params);
    int z;
    sp->x = 2;
    sp->y = 6;
    double zbuffer[params->screenwidth];  // 1D buffer

    //for sorting sprite
    int sprite_order[numsprite];    
    double sprite_distance[numsprite];
    //
    
    void sort_sprites(int * order, double *dist, int amount);
    zbuffer[z] = params->ray->perpwalldist;
    
    
    int i = -1;
    
    while(++i < numsprite)
    {
        sprite_order[i] = i;
        sprite_distance[i] = ((params->ray->posX - sp->x) * (params->ray->posX - sp->x) * (params->ray->posY - sp->y));
        
    }
    i = -1;    

    while(i++ < numsprite)
    {
        double spriteX = sp->x - params->ray->posX;
        double spriteY = sp->y - params->ray->posY;
        
        double invdet = 1.0 / (params->ray->planeX * params->ray->dirX - params->ray->dirX * params->ray->planeY);
        double transformX = invdet * (params->ray->dirY * spriteX - params->ray->dirX * spriteY);
        double transformY = invdet * (-params->ray->planeY * spriteX + params->ray->planeX * spriteY);
        int sprite_screenX = ((int)(params->screenwidth / 2) * (1 + transformX / transformY));
        int sprite_height = abs((int)(params->screenheight / transformY));
        int drawstarY = -sprite_height / 2 + params->screenwidth / 2;
        if (drawstarY < 0)
            drawstarY = 0;
        int drawendY = sprite_height / 2 + params->screenheight / 2;
        if (drawendY < 0)
            drawendY = 0;
        
        int sprite_width = abs((int)params->screenheight / transformY);
        int drawstartX = -sprite_height / 2 + sprite_screenX;
        if (drawstartX < 0)
            drawstartX = 0;
        int drawendX = sprite_width / 2 + sprite_screenX;
        if (drawendX < 0)
            drawendX = 0;

        int spX = 0;
        int spY = 0;;
        int stripe = drawstartX - 1;
        while(++stripe < drawendX)
        {
            spriteX = ((int)(256 * (stripe - (-sprite_width / 2 + sprite_screenX)) * txtW / sprite_width / 256));
            if (transformY > 0 && stripe > 0 && stripe < params->screenwidth && transformY < zbuffer[stripe])
            {
                params->color->b = sp->sp[0][spX * 4 + spY * sp->sizeline];
                params->color->g = sp->sp[0][spX * 4 + spY * sp->sizeline + 1];
                params->color->r = sp->sp[0][spX * 4 + spY * sp->sizeline + 2];
                params->color->a = sp->sp[0][spX * 4 + spY * sp->sizeline + 3];
                ft_pixel_to_image(x, stripe, params);
                int d = (stripe) * 256 - params->screenheight * 128 + sprite_height * 128;
                spriteY = ((d * txtH) / sprite_height) / 256;
            }
        }
    }
}
*/

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
    int texx = 0;;
    int stripe;
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


   
        int z;
        double zbuffer[params->screenwidth];  // 1D buffer
        zbuffer[z] = params->ray->perpwalldist;
        params->sp->x = 2;
        params->sp->y = 14;

        //for sorting sprite
        int sprite_order[numsprite];    
        double sprite_distance[numsprite];
        //
        
        void sort_sprites(int * order, double *dist, int amount);
        
        
        int i = 0;
        
        while(i < numsprite)
        {
            sprite_order[i] = i;
            sprite_distance[i] = ((params->ray->posX - params->sp->x) * (params->ray->posX - params->sp->x) * (params->ray->posY - params->sp->y));
            i++;
        }
        i = 0;    

        while(i < numsprite)
        {
            double spriteX = params->sp->x - params->ray->posX;
            double spriteY = params->sp->y - params->ray->posY;
            
            double invdet = 1.0 / (params->ray->planeX * params->ray->dirY - params->ray->dirX * params->ray->planeY);
            double transformX = invdet * (params->ray->dirY * spriteX - params->ray->dirX * spriteY);
            double transformY = invdet * (-params->ray->planeY * spriteX + params->ray->planeX * spriteY);
            int sprite_screenX = (int)((params->screenwidth / 2) * (1 + transformX / transformY));
            int sprite_height = abs((int)(params->screenheight / transformY));
            int drawstarY = -sprite_height / 2 + params->screenwidth / 2;
            if (drawstarY < 0)
                drawstarY = 0;
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
            stripe = drawstartX;
            int Y = drawstarY;
            //printf("%d\n", drawstarY);
            while(stripe < drawendX)
            {
                int spX = (int)(params->sp->sizeline * (stripe - (-sprite_width / 2 + sprite_screenX)) * txtW / sprite_width) / params->sp->sizeline;
                if (transformY > 0 && stripe > 0 && stripe < params->screenwidth && transformY < zbuffer[stripe])
                {
                    while(Y < drawendY)
                    {
                        
                        int d = Y * 256 - params->screenheight * 128 + sprite_height * 128;
                        int spY = ((d * txtH) / sprite_height) / 256;
                        /*
                        params->color->a = (unsigned char)0;
                        params->color->r = (unsigned char)255;
                        params->color->g = (unsigned char)255;
                        params->color->b = (unsigned char)0;
                        */
                        params->color->b = params->sp->spdata[spX * 4 + spY * params->sp->sizeline + 0];
                        params->color->g = params->sp->spdata[spX * 4 + spY * params->sp->sizeline + 1];
                        params->color->r = params->sp->spdata[spX * 4 + spY * params->sp->sizeline + 2];
                        params->color->a = params->sp->spdata[spX * 4 + spY * params->sp->sizeline + 3];
                        //printf("%d %d %d %d\n", params->color->a, params->color->r, params->color->g, params->color->b);
                        ft_sprite_to_image(spY, spX, params, Y, stripe);
                        Y++;
                    }
                }
                stripe++;
            }
            i++;
        }
    }
    return;
    
}