/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:20:06 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/03 17:25:00 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_pressed(int key_pressed, t_params *params)
{
	if (key_pressed == 13)
		params->event->up = 1;
	if (key_pressed == 1)
		params->event->down = 1;
	if (key_pressed == 0)
		params->event->left = 1;
	if (key_pressed == 2)
		params->event->right = 1;
	if (key_pressed == 123)
		params->event->turn_left = 1;
	if (key_pressed == 124)
		params->event->turn_right = 1;
	if (key_pressed == 53)
		exit(FALSE);
	return (FALSE);
}

int		key_released(int key_released, t_params *params)
{
	if (key_released == 13)
		params->event->up = 0;
	if (key_released == 1)
		params->event->down = 0;
	if (key_released == 0)
		params->event->left = 0;
	if (key_released == 2)
		params->event->right = 0;
	if (key_released == 123)
		params->event->turn_left = 0;
	if (key_released == 124)
		params->event->turn_right = 0;
	return (FALSE);
}

void	key_event(t_params *params)
{
	if (params->event->up == 1)
		up(params);
	if (params->event->down == 1)
		down(params);
	if (params->event->left == 1)
		left(params);
	if (params->event->right == 1)
		right(params);
	if (params->event->turn_left == 1)
		turn_right(params);
	if (params->event->turn_right == 1)
		turn_left(params);
}
