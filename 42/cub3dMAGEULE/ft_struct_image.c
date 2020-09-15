/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:40:28 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/15 20:43:01 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image ft_create_image()
{
    t_image image;
    image.img = NULL;
    image.imgdata = NULL;
    return(image);
}

t_image *ft_malloc_image()
{
    t_image *malloc_image;
    malloc_image = malloc(sizeof(t_image));
    *malloc_image = ft_create_image();
    return(malloc_image);
}
