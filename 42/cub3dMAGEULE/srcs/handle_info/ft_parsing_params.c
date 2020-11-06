/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:35:00 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/06 15:45:08 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*taking_info(char *line, char *s)
{
	int i;

	i = 0;
	if (s != NULL)
		ft_error(DUPLICATE_PARAMETERS);
	while (line[i] && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r' && line[i] != '\v'
			&& line[i] != '\f' && line[i] != ' ' && ft_isalpha(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	free(s);
	return (line + i);
}

void	trim_info(t_params *params)
{
	cut(params->textsp);
	cut(params->res);
	cut(params->textea);
	cut(params->textwe);
	cut(params->textso);
	cut(params->textno);
	cut(params->colorf);
	cut(params->colorc);
}

int		ft_params_format(t_params *params)
{
	int i;
	trim_info(params);
	if (!(params->argbcolorf = ft_split(params->colorf, ',')))
		ft_error(RGB_MISSING);
	if (!(params->argbcolorc = ft_split(params->colorc, ',')))
		ft_error(RGB_MISSING);
	if (params->argbcolorc[0] == NULL || params->argbcolorc[1] == NULL ||
			params->argbcolorc[2] == NULL || params->argbcolorc[3])
		ft_error(RGB_MISSING);
	if (params->argbcolorf[0] == NULL || params->argbcolorf[1] == NULL ||
			params->argbcolorf[2] == NULL || params->argbcolorf[3])
		ft_error(RGB_MISSING);
	params->color->cell_r = ft_atoi(params->argbcolorc[0]);
	params->color->cell_g = ft_atoi(params->argbcolorc[1]);
	params->color->cell_b = ft_atoi(params->argbcolorc[2]);
	params->color->floor_r = ft_atoi(params->argbcolorf[0]);
	params->color->floor_g = ft_atoi(params->argbcolorf[1]);
	params->color->floor_b = ft_atoi(params->argbcolorf[2]);
	ft_check_cell(params);
	ft_check_floor(params);
	format_color(params);
	i = -1;
	while (params->argbcolorf[++i])
		free(params->argbcolorf[i]);
	free(params->argbcolorf);
	i = -1;
	while (params->argbcolorc[++i])
		free(params->argbcolorc[i]);
	free(params->argbcolorc);
	return (FALSE);
}

void	parse_info(t_params *params, int fd, char *line)
{
	if (!strncmp("S ", line, 2))
		params->textsp = taking_info(line, params->textsp);
	else if (!strncmp("NO", line, 2))
		params->textno = taking_info(line, params->textno);
	else if (!strncmp("SO", line, 2))
		params->textso = taking_info(line, params->textso);
	else if (!strncmp("WE", line, 2))
		params->textwe = taking_info(line, params->textwe);
	else if (!strncmp("EA", line, 2))
		params->textea = taking_info(line, params->textea);
	else if (!strncmp("F", line, 1))
		params->colorf = taking_info(line, params->colorf);
	else if (!strncmp("C", line, 1))
		params->colorc = taking_info(line, params->colorc);
	else if (!strncmp("R", line, 1))
		params->res = taking_info(line, params->res);
	else if (strchr(line, '1'))
	{
		params->map = ft_map_parsing(fd, line);
		params->map_find++;
	}
	else if ((strncmp(" ", line, 1)) && strncmp("", line, 1))
		ft_error(WRONG_PARAMS);
	else
		free(line);
}

int		search_params(t_params *params, int fd)
{
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		parse_info(params, fd, line);
	}
	ft_params_format(params);
	free(line);
	return (TRUE);
}
