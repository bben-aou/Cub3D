/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:20:49 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/10 10:28:32 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_walls_bonus(t_varb *var)
{
    int y;
    int x;

    y = var->count_line;
    while (--y >= 0)
    {
        x = ft_strlen1(var->map[y]) - 1;
        if (var->map[y][0] != ' ' && var->map[y][0] != '1')
            error_mapB("Left Side of Wall", var);
        else if (var->map[y][x] != ' ' && var->map[y][x] != '1')
            error_mapB("Right Side of Wall", var); 
    }
}

void    handle_space_in_linesB(t_varb *var, int x, char *str)
{
    int y;

    y = var->count_line - 1;
    if (ft_strcmpB(str, "first") == 0)
    {
        if (var->map[1][x] != ' ' && var->map[1][x] != '1' && var->map[1][x] != '\0')
                error_mapB("Around space In first Line", var);
        if (x > 0)
            if ((var->map[0][x - 1] != ' ' && var->map[0][x - 1] != '1'))
                error_mapB("Around space in First Line", var);
        if (x != ft_strlen1(var->map[0]) - 1)
            if ((var->map[0][x + 1] != ' ' && var->map[0][x + 1] != '1'))
				error_mapB("Around space in First Line", var);
	}
    else if (ft_strcmpB(str, "last") == 0)
    {
        if (var->map[y - 1][x] != ' ' && var->map[y - 1][x] != '1' && var->map[y - 1][x] != '\0')
                error_mapB("Around space In Last Line", var);
        if (x > 0)
            if ((var->map[y][x - 1] != ' ' && var->map[y][x - 1] != '1'))
                error_mapB("eAround space in Last Line", var);
        if (x != ft_strlen1(var->map[y]) - 1)
            if ((var->map[y][x + 1] != ' ' && var->map[y][x + 1] != '1'))
				error_mapB("Around space in Last Line", var);
    }      
}

void    check_lines_bonus(t_varb *var)
{
	int x;
	int y;

	x = 0;
	y = var->count_line - 1;
	while (var->map[0][x] && var->map[0][x] != '\n')
    {
        if (var->map[0][x] == ' ')
            handle_space_in_linesB(var, x, "first");
		if (var->map[0][x] != ' ' && var->map[0][x] != '1')
			error_mapB("First Line", var);
        x++;
    }
	x = 0;
	while (var->map[y][x] && var->map[y][x] != '\n')
    {
        if (var->map[y][x] == ' ')
            handle_space_in_linesB(var, x, "last");
		if (var->map[y][x] != ' ' && var->map[y][x] != '1')
			error_mapB("Last Line", var);
        x++;
    }
}

void    handle_space_inside_mapB(t_varb *var, int y, int x)
{
    if (ft_strlen1(var->map[y + 1]) >= x)
        if ((var->map[y + 1][x] == '0') || (var->map[y + 1][x] == 'N')
		    || (var->map[y + 1][x]) == 'S' || (var->map[y + 1][x] == 'E')
		    || (var->map[y  + 1][x]) == 'W')
                error_mapB("Around space Inside Map", var);
    if (ft_strlen1(var->map[y - 1]) >= x)
        if ((var->map[y - 1][x] == '0') || (var->map[y - 1][x] == 'N')
		    || (var->map[y - 1][x]) == 'S' || (var->map[y - 1][x] == 'E')
		    || (var->map[y  - 1][x]) == 'W')
                error_mapB("Around space Inside Map", var);
    if (x > 0)
        if ((var->map[y][x - 1] != ' ' && var->map[y][x - 1] != '1'))
            error_mapB("Around space Inside Map", var);
    if (x != ft_strlen1(var->map[y]) - 1)
        if ((var->map[y][x + 1] != ' ' && var->map[y][x + 1] != '1'))
			error_mapB("Around space Inside Map", var);
}

void    check_line_size_bonus(t_varb *var, int y)
{
    int len;

    len = ft_strlen1(var->map[y - 1]);
    if (len < ft_strlen1(var->map[y + 1]))
        len = ft_strlen1(var->map[y + 1]);
    if (len < ft_strlen1(var->map[y]))
    {
        while (var->map[y][len] && var->map[y][len] != '\n')
        {
            if(var->map[y][len] != ' ' && var->map[y][len] != '1')
                error_mapB("Map Not Arrounded by Walls", var);
            len++;            
        }
    }
}

void    getPlayerPosition_bonus(t_varb *var ,int x, int y)
{
    var->player->x = (double)x * TILE_SIZE + TILE_SIZE / 2.0; 
    var->player->y = (double)y * TILE_SIZE + TILE_SIZE / 2.0 ;
}

void    getAngleValue_bonus(char c, t_varb *var)
{
    if (c == 'N')
        var->player->rotationAngle = 3 * (M_PI / 2);
    if (c == 'S')
        var->player->rotationAngle = M_PI / 2;
    if (c == 'E')
        var->player->rotationAngle = 0;
    if (c == 'W')
    var->player->rotationAngle = M_PI;
}

void    check_char_bonus(t_varb *var, int y, int x)
{
    if (var->map[y][x] == ' ')
		handle_space_inside_mapB(var, y, x);
    if (var->map[y][x] == 'N' || var->map[y][x] == 'S'
        || var->map[y][x] == 'E'|| var->map[y][x] == 'W')
        {
            var->count_player++;
            getAngleValue_bonus(var->map[y][x], var);
            getPlayerPosition_bonus(var ,x ,y);   // init the player's position 
        }
    if (var->count_player > 1 )
        error_mapB("More than One Player", var);
	if (var->map[y][x] != ' ' && var->map[y][x] != '1'
		&& var->map[y][x] != '0' && var->map[y][x] != 'N'
		&& var->map[y][x] != 'S' && var->map[y][x] != 'E'
		&& var->map[y][x] != 'W')
		error_mapB("Invalid character Inside Map", var);
}

void    check_map_bonus(t_varb *var)
{
    int y;
    int x;

    y = 1;
	check_lines_bonus(var);
	check_walls_bonus(var);
    while (y < var->count_line - 1)
    {
		x = 0;
        check_line_size_bonus(var, y);
		while (var->map[y][x] != '\n' && var->map[y][x])
		{
			check_char_bonus(var, y, x);
			x++;
		}
        y++;
    }
    if ( var->count_player == 0)
        error_mapB("there is No Player", var);
}