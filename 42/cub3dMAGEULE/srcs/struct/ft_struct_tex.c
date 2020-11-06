/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:45:32 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/06 19:01:00 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_tex	ft_create_tex(void)
{
	t_tex tex;
	tex.tex = malloc(sizeof(char *) * 4);
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
	return (tex);
}

t_tex	*ft_malloc_tex(void)
{
	t_tex *malloc_tex;

	malloc_tex = malloc(sizeof(t_tex));
	*malloc_tex = ft_create_tex();
	return (malloc_tex);
}

void		ft_free_tex(t_tex *to_free)
{
	int			i;

	i = -1;
	while (to_free->tex[++i])
		free(to_free->tex[i]);
	free(to_free->tex);
	free(to_free);
}
