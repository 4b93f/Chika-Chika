/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 01:14:46 by root              #+#    #+#             */
/*   Updated: 2020/10/16 18:47:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_params ft_create_params()
{
    t_params params;
    params.screenwidth = 0;
    params.map_find = 0;
    params.find_pos = 0;
    params.player_orientation = 0;
    params.screenheight = 0;
    params.res = NULL;
    params.textno = NULL;
    params.textso = NULL;
    params.textwe = NULL;
    params.textea = NULL;
    params.textsp = NULL;
    params.textp = NULL;
    params.textf = NULL;
    params.colorc = NULL;
    if (!(params.argbcolorc = malloc(sizeof(char*) * 3)))
        ft_error(MALLOC_ERROR);
    params.colorf = NULL;
    if (!(params.argbcolorf = malloc(sizeof(char*) * 3)))
        ft_error(MALLOC_ERROR);
    params.map = NULL;
    return(params);
}

t_params *ft_malloc_params()
{
    t_params *malloc_params;
    malloc_params = malloc(sizeof(t_params));
    *malloc_params = ft_create_params();
    return(malloc_params);
}

void ft_free_params(t_params *to_free)
{
    int i;

    i = -1;
    while(to_free->map[++i])
        free(to_free->map[i]);
    free(to_free->map);
    free(to_free);
}