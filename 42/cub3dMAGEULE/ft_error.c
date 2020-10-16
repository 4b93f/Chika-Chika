/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:07:53 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/16 19:07:21 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_error(int num)
{
    static char *error[] = {
        "Error\nMap file not include\n",
        "Error\nWrong parameters in map file\n",
        "Error\nMap not found\n",
        "Error\nMalloc error\n",
        "Error\nx2 same parameters in map file\n",
        "Error\nAnomaly with textures\n",
        "Error\nRGB color need to be < 256 and >= 0\n",
        "Error\nMissing something in RGB Color\n",
        "Error\nMissing/Wrong Resolution\n",
        "Error\nPlayer not found\n",
        "Error\nAnomaly with sprite\n",
        "Error\nMissing parameters\n"
    };
    printf("%s", error[num]);
    exit(0);
}
