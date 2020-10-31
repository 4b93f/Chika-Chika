/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 23:00:36 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/31 15:42:08 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_event	ft_create_event(void)
{
	t_event	event;

	event.up = 0;
	event.down = 0;
	event.left = 0;
	event.right = 0;
	event.turn_left = 0;
	event.turn_right = 0;
	return (event);
}

t_event	*ft_malloc_event(void)
{
	t_event	*malloc_event;

	malloc_event = malloc(sizeof(t_event));
	*malloc_event = ft_create_event();
	return (malloc_event);
}
