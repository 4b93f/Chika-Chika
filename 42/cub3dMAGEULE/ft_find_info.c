/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:16:21 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/17 18:11:56 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int ft_check_map(t_params *params, char **map)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    if (!map[2])
        return (FALSE);
    if (ft_updownwall(map[0]) == 0)
        return (FALSE);
    while(map[i + 1] != NULL)
    {
        if (ft_check_char(params, map[i]) == FALSE)
            return (FALSE);
        i++;
    }
    if (ft_updownwall(map[i]) == 0)
        return (FALSE);
    if (ft_check_space(map) == 0)
        return (FALSE);
    if (params->find_pos != 1)
        ft_error(WRONG_PARAMS);
    return (TRUE);
}