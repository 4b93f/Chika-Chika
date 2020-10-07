/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:14:06 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/07 20:50:12 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *ft_new_sp(t_params *params, char *path)
{
    int i;

    void *sp;
    char *spdata;
    
    sp = mlx_xpm_file_to_image(params->ray->mlx, path, &params->sp->sp_width, &params->sp->sp_height);
    spdata = mlx_get_data_addr(sp, &params->sp->bpp, &params->sp->sizeline, &params->sp->endian);
    return(spdata);
}

void ft_get_sp(t_params *params)
{
    params->sp->sp[0] = ft_new_sp(params, params->sp);

    return;
}

