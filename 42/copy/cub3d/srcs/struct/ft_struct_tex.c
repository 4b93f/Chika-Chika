/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:45:32 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/15 18:50:34 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_tex	ft_create_tex(t_params *params)
{
	t_tex tex;

	tex.bpp = 0;
	tex.sizeline = 0;
	tex.endian = 0;
	tex.tex_width = 0;
	tex.tex_height = 0;
	tex.texnum = 0;
	tex.texpos = 0;
	tex.step = 0;
	tex.texx = 0;
	tex.texy = 0;
	if (!(tex.tex = malloc(sizeof(char *) * 4)))
		quit(MALLOC_ERROR, params);
	tex.tex[0] = NULL;
	tex.tex[1] = NULL;
	tex.tex[2] = NULL;
	tex.tex[3] = NULL;
	return (tex);
}

t_tex			*ft_malloc_tex(t_params *params)
{
	t_tex *malloc_tex;

	if (!(malloc_tex = malloc(sizeof(t_tex))))
		quit(MALLOC_ERROR, params);
	*malloc_tex = ft_create_tex(params);
	return (malloc_tex);
}

void			ft_free_tex(t_tex *to_free)
{
	free(to_free->tex);
	free(to_free);
}
