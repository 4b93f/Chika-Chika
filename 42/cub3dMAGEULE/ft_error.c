/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:07:53 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/16 15:50:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_error(int error)
{
    if (error == 0)
        printf("Error\nMap file not include\n");
    if (error == 1)
        printf("Error\nWrong parameters in map file\n");
    if (error == 2)
        printf("Error\nMap not find\n");
    exit(0);
}

