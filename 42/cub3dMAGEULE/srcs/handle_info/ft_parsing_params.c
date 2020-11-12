/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:35:00 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/12 14:55:58 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*taking_info(t_params *params, char *line, char *s)
{
	int i;

	i = 0;
	if (s != NULL)
		ft_error(params, DUPLICATE_PARAMETERS);
	while (ft_isalpha(line[i]))
		i++;
	if (!ft_isspace(line[i]))
		quit(WRONG_PARAMS, params);
	i++;
	while (line[i] && ft_isspace(line[i]) && ft_isalpha(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	free(s);
	return (line + i);
}

static void	trim_info(t_params *params)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	cut(params->textsp, params);
	cut(params->res, params);
	cut(params->textea, params);
	cut(params->textwe, params);
	cut(params->textso, params);
	cut(params->textno, params);
	cut(params->colorf, params);
	cut(params->colorc, params);
	while (params->colorf[++i])
		if (params->colorf[i] == ',')
			j++;
	i = -1;
	while (params->colorc[++i])
		if (params->colorc[i] == ',')
			k++;
	if (k > 2 || j > 2)
		quit(WRONG_CHAR_IN_RGB, params);
}

static void	ft_params_format(t_params *params)
{
	int i;

	trim_info(params);
	if (!(params->argbcolorf = ft_split(params->colorf, ',')))
		quit(WRONG_PARAMS, params);
	if (!(params->argbcolorc = ft_split(params->colorc, ',')))
		quit(WRONG_PARAMS, params);
	if (params->argbcolorc[0] == NULL || params->argbcolorc[1] == NULL ||
			params->argbcolorc[2] == NULL)
		quit(RGB_MISSING, params);
	if (params->argbcolorf[0] == NULL || params->argbcolorf[1] == NULL ||
			params->argbcolorf[2] == NULL)
		quit(RGB_MISSING, params);
	atoi_info(params);
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
}

static void	parse_info(t_params *params, int fd, char *line)
{
	if (!strncmp("SO", line, 2))
		params->textso = taking_info(params, line, params->textso);
	else if (!strncmp("NO", line, 2))
		params->textno = taking_info(params, line, params->textno);
	else if (!strncmp("S", line, 1))
		params->textsp = taking_info(params, line, params->textsp);
	else if (!strncmp("WE", line, 2))
		params->textwe = taking_info(params, line, params->textwe);
	else if (!strncmp("EA", line, 2))
		params->textea = taking_info(params, line, params->textea);
	else if (!strncmp("F", line, 1))
		params->colorf = taking_info(params, line, params->colorf);
	else if (!strncmp("C", line, 1))
		params->colorc = taking_info(params, line, params->colorc);
	else if (!strncmp("R", line, 1))
		params->res = taking_info(params, line, params->res);
	else if (strchr(line, '1'))
	{
		params->map = ft_map_parsing(params, fd, line);
		params->map_find++;
	}
	else if (!check_line(line))
		quit(WRONG_PARAMS, params);
	else
		free(line);
}

int			search_params(t_params *params, int fd)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
		parse_info(params, fd, line);
	ft_params_format(params);
	free(line);
	return (TRUE);
}
