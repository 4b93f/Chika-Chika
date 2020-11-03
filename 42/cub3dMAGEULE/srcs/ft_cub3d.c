/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/03 17:56:42 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_event(t_params *params)
{
	exit(FALSE);
}

int		start(t_params *params)
{
	ft_raycast(params, params->ray, params->color);
	if (params->image->save == 1)
		save(params);
	mlx_put_image_to_window(params->ray->mlx, params->ray->window,
			params->image->img, 0, 0);
	key_event(params);
	return (TRUE);
}

void	game(t_params *params)
{
	ft_get_tex(params);
	ft_get_sprite(params, params->textsp);
	if (params->map_find == 0)
		ft_error(NO_MAP);
	if (ft_check_map(params, params->map) == 0)
		ft_error(WRONG_MAP_FORMAT);
	ft_orientation(params, params->ray);
	ft_getpose_sprite(params->map, params->sp, params->sprites);
	ft_getposray(params->map, params->player);
	params->image->img = mlx_new_image(params->mlx, params->screenwidth,
			params->screenheight);
	params->image->imgdata = mlx_get_data_addr(params->image->img,
		&params->image->bpp, &params->image->sizeline, &params->image->endian);
	params->image->imgsave = mlx_get_data_addr(params->image->img,
		&params->image->bpp, &params->image->sizeline, &params->image->endian);
	mlx_hook(params->ray->window, 2, 1L << 0, key_pressed, params);
	mlx_hook(params->ray->window, 3, 1L << 0, key_released, params);
	mlx_hook(params->ray->window, 17, 1L << 17, mouse_event, params);
	mlx_loop_hook(params->mlx, start, params);
	if (!(mlx_loop(params->mlx) == 0))
		exit(TRUE);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_params	*params;

	fd = open(argv[1], O_RDONLY);
	params = ft_malloc_params();
	ft_init_game(params, fd);
	parameters(params, argc, argv);
	game(params);
}
