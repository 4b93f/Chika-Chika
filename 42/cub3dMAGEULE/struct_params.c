/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 01:14:46 by root              #+#    #+#             */
/*   Updated: 2020/08/08 16:55:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_params ft_create_struct(char *path)
{
    t_params params;
    params.resx = 0;
    params.resy = 0;
    params.map_find = 0;
    params.res = NULL;
    params.textno = NULL;
    params.textso = NULL;
    params.textwe = NULL;
    params.textea = NULL;
    params.textsp = NULL;
    params.textp = NULL;
    params.colorc = NULL;
    params.colorf = NULL;
    params.map = NULL;
    return(params);
}

t_params *ft_malloc_struct(char *path)
{
    t_params *malloc_struct;
    malloc_struct = malloc(sizeof(t_params));
    *malloc_struct = ft_create_struct(path);
    return(malloc_struct);
}

void ft_free_struct(t_params *to_free)
{
    int i;

    i = -1;
    while(to_free->map[++i])
        free(to_free->map[i]);
    free(to_free->map);
    free(to_free);
    
}