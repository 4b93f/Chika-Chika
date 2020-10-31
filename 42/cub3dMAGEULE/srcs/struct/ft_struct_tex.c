/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:45:32 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/31 15:42:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_tex	ft_create_tex(void)
{
	t_tex tex;

	tex.tex_width = 0;
	tex.tex_height = 0;
	tex.tex = malloc(sizeof(char *) * 4);
	return (tex);
}

t_tex	*ft_malloc_tex(void)
{
	t_tex *malloc_tex;

	malloc_tex = malloc(sizeof(t_tex));
	*malloc_tex = ft_create_tex();
	return (malloc_tex);
}
