/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapb.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:20:49 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/15 18:04:33 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	handle_space_inside_mapb(t_varb *var, int y, int x)
{
	if (ft_strlenb(var->map[y + 1]) >= x)
		if ((var->map[y + 1][x] == '0') || (var->map[y + 1][x] == 'N') \
			|| (var->map[y + 1][x]) == 'S' || (var->map[y + 1][x] == 'E') \
				|| (var->map[y + 1][x]) == 'W')
			error_map_b("Around space Inside Map", var);
	if (ft_strlenb(var->map[y - 1]) >= x)
		if ((var->map[y - 1][x] == '0') || (var->map[y - 1][x] == 'N') \
			|| (var->map[y - 1][x]) == 'S' || (var->map[y - 1][x] == 'E') \
				|| (var->map[y - 1][x]) == 'W')
			error_map_b("Around space Inside Map", var);
	if (x > 0)
		if ((var->map[y][x - 1] != ' ' && var->map[y][x - 1] != '1'))
			error_map_b("Around space Inside Map", var);
	if (x != ft_strlenb(var->map[y]) - 1)
		if ((var->map[y][x + 1] != ' ' && var->map[y][x + 1] != '1'))
			error_map_b("Around space Inside Map", var);
}

void	check_line_sizeb(t_varb *var, int y)
{
	int	len;

	len = ft_strlenb(var->map[y - 1]);
	if (len > ft_strlenb(var->map[y + 1]))
		len = ft_strlenb(var->map[y + 1]);
	if (len < ft_strlenb(var->map[y]))
	{
		while (var->map[y][len] && var->map[y][len] != '\n')
		{
			if (var->map[y][len] != ' ' && var->map[y][len] != '1')
				error_map_b("Map Not Arrounded by Walls", var);
			len++;
		}
	}
}

void	get_angle_valueb(char c, t_varb *var)
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

void	check_charb(t_varb *var, int y, int x)
{
	if (var->map[y][x] == ' ')
		handle_space_inside_mapb(var, y, x);
	if (var->map[y][x] == 'N' || var->map[y][x] == 'S' \
		|| var->map[y][x] == 'E' || var->map[y][x] == 'W')
	{
		var->count_playerb++;
		get_angle_valueb(var->map[y][x], var);
		get_playerb_postionb(var, x, y);
	}
	if (var->count_playerb > 1)
		error_map_b("More than One Player", var);
	if (var->map[y][x] != ' ' && var->map[y][x] != '1' && var->map[y][x] != '0' \
		&& var->map[y][x] != 'N' && var->map[y][x] != 'S' \
			&& var->map[y][x] != 'E' && var->map[y][x] != 'W')
		error_map_b("Invalid character Inside Map", var);
}

void	check_mapb(t_varb *var)
{
	int	y;
	int	x;

	y = 1;
	check_linesb(var);
	check_wallbsb(var);
	while (y < var->count_line - 1)
	{
		x = 0;
		check_line_sizeb(var, y);
		while (var->map[y][x] != '\n' && var->map[y][x])
		{
			check_charb(var, y, x);
			x++;
		}
		y++;
	}
	if (var->count_playerb == 0)
		error_map_b("there is No Player", var);
}
