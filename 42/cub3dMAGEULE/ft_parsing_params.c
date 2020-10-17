#include "cub3d.h"

char *taking_info(char *line, char *s)
{
    int i;

    i = 0;
    if (s != NULL)
        ft_error(DUPLICATE_PARAMETERS);
    while (line[i] && line[i] != '\t' && line[i] != '\n' && line[i] != '\r'  && line[i] != '\v'
     && line[i] != '\f' && ft_isalpha(line[i]))
        i++;
    while(line[i] == ' ')
        i++;
    return (line + i);
}

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

void ft_check_floor(t_params *params)
{
    int i;
    int j;
    int k;
    int l;

    i = -1;
    j = 0;
    k = 0;
    l = 0;
    while(params->argbcolorf[++i])
    {
        while(params->argbcolorf[i][j] && !ft_isdigit(params->argbcolorf[i][j]))
            j++;
        while(ft_isdigit(params->argbcolorf[i][j]))
            j++;
        while(params->argbcolorf[i][j])
        {
            if(!ft_isspace(params->argbcolorf[i][j]) && ft_isascii(params->argbcolorf[i][j]))
                ft_error(WRONG_CHAR_IN_RGB);
            j++;
        }
        j = 0;
    }
}

int find_duplicate(char *str, int c)
{
    int i;
    int num;

    i = -1;
    num = 0;
    while (str[++i])
    {
        if (str[i] == c)
            num++;
    }
    return(num);
}

void ft_check_cell(t_params *params)
{
    int i;
    int j;
    int k;
    int l;

    i = -1;
    j = 0;
    k = 0;
    l = 0;
    while(params->argbcolorc[++i])
    {
        //printf("chaine = {%s}\n", params->argbcolorc[i]);
        while(params->argbcolorc[i][j] && !ft_isdigit(params->argbcolorc[i][j]))
            j++;
        while(ft_isdigit(params->argbcolorc[i][j]))
            j++;
        while(params->argbcolorc[i][j])
        {
            if(!ft_isspace(params->argbcolorc[i][j]) && ft_isascii(params->argbcolorc[i][j]))
                ft_error(WRONG_CHAR_IN_RGB);
            j++;
        }
        j = 0;
    }
    ft_check_floor(params);
}

int ft_params_format(t_params *params)
{
    if (params->colorf == NULL || params->colorc == NULL || params->res == NULL || params->textsp == NULL || 
    params->textno == NULL || params->textso == NULL || params->textwe == NULL || params->textea == NULL)
        ft_error(SOMETHING_IS_MISSING);
    if (find_duplicate(params->colorc, ',') != 2 || find_duplicate(params->colorf, ',') != 2)
        ft_error(WRONG_CHAR_IN_RGB);
    params->textsp = ft_strtrim(params->textsp, " ");
    params->res = ft_strtrim(params->res, " ");
    params->textno = ft_strtrim(params->textno, " ");
    params->textso = ft_strtrim(params->textso, " ");
    params->textwe = ft_strtrim(params->textwe, " ");
    params->textea = ft_strtrim(params->textea, " ");
    params->colorf = ft_strtrim(params->colorf, " ");
    params->colorc = ft_strtrim(params->colorc, " ");
    if (!(params->argbcolorf = ft_split(params->colorf, ',')))
        ft_error(RGB_MISSING);
    params->argbcolorc = ft_split(params->colorc, ',');
    if (params->argbcolorc[0] == NULL || params->argbcolorc[1] == NULL || params->argbcolorc[2] == NULL || params->argbcolorc[3])
        ft_error(RGB_MISSING);
    if (params->argbcolorf[0] == NULL || params->argbcolorf[1] == NULL || params->argbcolorf[2] == NULL || params->argbcolorf[3])
        ft_error(RGB_MISSING);
    ft_check_cell(params);
    params->color->cell_r = ft_atoi(params->argbcolorc[0]);
    params->color->cell_g = ft_atoi(params->argbcolorc[1]);
    params->color->cell_b = ft_atoi(params->argbcolorc[2]);
    params->color->floor_r = ft_atoi(params->argbcolorf[0]);
    params->color->floor_g = ft_atoi(params->argbcolorf[1]);
    params->color->floor_b = ft_atoi(params->argbcolorf[2]);
    if (params->color->cell_r > 255 && params->color->cell_g > 255 && params->color->cell_b > 255 && params->color->cell_r < 0 && params->color->cell_g < 0 && params->color->cell_b < 0)
        ft_error(RGB_ERROR);
    if (params->color->floor_r > 255 && params->color->floor_g > 255 && params->color->floor_g > 255 && params->color->floor_r < 0 && params->color->floor_g < 0 && params->color->floor_b < 0)
        ft_error(RGB_ERROR);
    return (0);
}

int search_params(t_params *params, int fd)
{
    char *line;

    while(get_next_line(fd, &line) > 0)
    {   
        //printf("1\n");
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
    }
    ft_params_format(params);
    return(TRUE);
}