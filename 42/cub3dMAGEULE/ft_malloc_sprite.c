/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:05:34 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/07 20:09:47 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

t_sprite ft_create_sprite()
{
    t_sprite sp;
    sp.x = 0;
    sp.y = 0;
    sp.texture = 0;
 
    return(sp);
}

t_sprite *ft_malloc_sprite()
{
    t_sprite *malloc_sp;
    malloc_sp = malloc(sizeof(t_sprite));
    *malloc_sp = ft_create_sprite();
    return(malloc_sp);
}