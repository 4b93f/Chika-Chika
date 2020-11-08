/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/08 19:24:40 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_error(t_params *params, int error)
{
	if (params->image->img)
		mlx_destroy_image(params->ray->mlx, params->image->img);
	if (params->sp->mlx_sprite)
		mlx_destroy_image(params->ray->mlx, params->sp->mlx_sprite);
	if (params->mlx_txt_n)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_n);
	if (params->mlx_txt_s)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_s);
	if (params->mlx_txt_w)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_w);
	if (params->mlx_txt_e)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_e);
	if (params->ray->window)
		mlx_destroy_window(params->ray->mlx, params->ray->window);
	quit(error, params);

	return (1);
}

int		mouse_event(t_params *params)
{
	ft_error(params, -1);
	return (1);
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
		ft_error(params, NO_MAP);
	if (ft_check_map(params, params->map) == 0)
		ft_error(params, WRONG_MAP_FORMAT);
	ft_orientation(params);
	ft_getpose_sprite(params->map, params);
	ft_getposray(params->map, params->player);

	params->image->img = mlx_new_image(params->ray->mlx, params->screenwidth,
			params->screenheight);
	params->image->imgdata = mlx_get_data_addr(params->image->img,
		&params->image->bpp, &params->image->sizeline, &params->image->endian);
	params->image->imgsave = mlx_get_data_addr(params->image->img,
		&params->image->bpp, &params->image->sizeline, &params->image->endian);
	mlx_hook(params->ray->window, 2, 1L << 0, key_pressed, params);
	mlx_hook(params->ray->window, 3, 1L << 0, key_released, params);
	mlx_hook(params->ray->window, 17, 1L << 17, mouse_event, params);
	mlx_loop_hook(params->ray->mlx, start, params);
	if (!(mlx_loop(params->ray->mlx) == 0))
		ft_error(params, -1);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_params	*params;

	params = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		quit(NO_MAPFILE, params);
	if (ft_strncmp(argv[1], ".cub", ft_strlen(argv[1])) == 0)
		quit(NO_MAPFILE, params);
	if (!(params = ft_malloc_params()))
		quit(MALLOC_ERROR, params);
	ft_init_game(params, fd);
	parameters(params, argc, argv);
	game(params);
	return (0);
}
