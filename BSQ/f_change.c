/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_change.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:03:18 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 15:32:58 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char **f_change(char **map)
{
    char *code;
    char **map_converted;
    code = ft_recup_code(map);
    map_converted = ft_map_setup_main(map, code);
    return(map_converted);
}