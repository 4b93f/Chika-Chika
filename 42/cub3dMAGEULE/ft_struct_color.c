/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:07:25 by becentrale        #+#    #+#             */
/*   Updated: 2020/10/01 19:11:23 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color ft_create_color()
{
    t_color color;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    return(color);
}

t_color *ft_malloc_color()
{
    t_color *malloc_color;
    malloc_color = malloc(sizeof(t_color));
    *malloc_color = ft_create_color();
    return(malloc_color);
}