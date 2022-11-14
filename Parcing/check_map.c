/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:20:49 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 11:34:14 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void handle_space_inside_map(t_var *var, int y, int x)
{
    if (ft_strlen1(var->map[y + 1]) >= x)
        if ((var->map[y + 1][x] == '0') || (var->map[y + 1][x] == 'N')
            || (var->map[y + 1][x]) == 'S' || (var->map[y + 1][x] == 'E')
            || (var->map[y + 1][x]) == 'W')
            error_map("Around space Inside Map", var);
    if (ft_strlen1(var->map[y - 1]) >= x)
        if ((var->map[y - 1][x] == '0') || (var->map[y - 1][x] == 'N')
            || (var->map[y - 1][x]) == 'S' || (var->map[y - 1][x] == 'E')
            || (var->map[y - 1][x]) == 'W')
            error_map("Around space Inside Map", var);
    if (x > 0)
        if ((var->map[y][x - 1] != ' ' && var->map[y][x - 1] != '1'))
            error_map("Around space Inside Map", var);
    if (x != ft_strlen1(var->map[y]) - 1)
        if ((var->map[y][x + 1] != ' ' && var->map[y][x + 1] != '1'))
            error_map("Around space Inside Map", var);
}

void check_line_size(t_var *var, int y)
{
    int len;

    len = ft_strlen1(var->map[y - 1]);
    if (len > ft_strlen1(var->map[y + 1]))
        len = ft_strlen1(var->map[y + 1]);
    if (len < ft_strlen1(var->map[y]))
    {
        while (var->map[y][len] && var->map[y][len] != '\n')
        {
            if (var->map[y][len] != ' ' && var->map[y][len] != '1')
                error_map("Map Not Arrounded by Walls", var);
            len++;
        }
    }
}


void get_angle_value(char c, t_var *var)
{
    if (c == 'N')
        var->player->rotatin_angle = 3 * (M_PI / 2);
    if (c == 'S')
        var->player->rotatin_angle = M_PI / 2;
    if (c == 'E')
        var->player->rotatin_angle = 0;
    if (c == 'W')
        var->player->rotatin_angle = M_PI;
}

void check_char(t_var *var, int y, int x)
{
    if (var->map[y][x] == ' ')
        handle_space_inside_map(var, y, x);
    if (var->map[y][x] == 'N' || var->map[y][x] == 'S'
        || var->map[y][x] == 'E' || var->map[y][x] == 'W')
    {
        var->count_player++;
        get_angle_value(var->map[y][x], var);
        get_player_postion(var, x, y); // init the player's position
    }
    if (var->count_player > 1)
        error_map("More than One Player", var);
    if (var->map[y][x] != ' ' && var->map[y][x] != '1' && var->map[y][x] != '0'
        && var->map[y][x] != 'N' && var->map[y][x] != 'S'
        && var->map[y][x] != 'E' && var->map[y][x] != 'W')
        error_map("Invalid character Inside Map", var);
}

void check_map(t_var *var)
{
    int y;
    int x;

    y = 1;
    check_lines(var);
    check_walls(var);
    while (y < var->count_line - 1)
    {
        x = 0;
        check_line_size(var, y);
        while (var->map[y][x] != '\n' && var->map[y][x])
        {
            check_char(var, y, x);
            x++;
        }
        y++;
    }
    if (var->count_player == 0)
        error_map("there is No Player", var);
}