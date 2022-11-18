/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:31:32 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 14:09:28 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player_postion(t_var *var, int x, int y)
{
	var->player->x = (double)x * T_S + T_S / 2.0;
	var->player->y = (double)y * T_S + T_S / 2.0;
}

void	check_last_line(t_var *var, int x)
{
	int	y;

	y = var->count_line - 1;
	if (ft_strlen1(var->map[y - 1]) >= x)
		if (var->map[y - 1][x] != ' ' && var->map[y - 1][x] != '1' \
			&& var->map[y - 1][x] != '\0')
			error_map("Around space In Last Line", var);
	if (x > 0)
		if ((var->map[y][x - 1] != ' ' && var->map[y][x - 1] != '1'))
			error_map("eAround space in Last Line", var);
	if (x != ft_strlen1(var->map[y]) - 1)
		if ((var->map[y][x + 1] != ' ' && var->map[y][x + 1] != '1'))
			error_map("Around space in Last Line", var);
}

void	check_walls(t_var *var)
{
	int	y;
	int	x;

	y = var->count_line;
	while (--y >= 0)
	{
		x = ft_strlen1(var->map[y]) - 1;
		if (var->map[y][0] != ' ' && var->map[y][0] != '1')
			error_map("Left Side of Wall", var);
		else if (var->map[y][x] != ' ' && var->map[y][x] != '1')
			error_map("Right Side of Wall", var);
	}
}

void	handle_space_in_lines(t_var *var, int x, char *str)
{
	if (ft_strcmp_b(str, "first") == 0)
	{
		if (ft_strlen1(var->map[1]) >= x)
			if (var->map[1][x] != ' ' && var->map[1][x] != '1' \
				&& var->map[1][x] != '\0')
				error_map("Around space In first Line", var);
		if (x > 0)
			if ((var->map[0][x - 1] != ' ' && var->map[0][x - 1] != '1'))
				error_map("Around space in First Line", var);
		if (x != ft_strlen1(var->map[0]) - 1)
			if ((var->map[0][x + 1] != ' ' && var->map[0][x + 1] != '1'))
				error_map("Around space in First Line", var);
	}
	else if (ft_strcmp_b(str, "last") == 0)
		check_last_line(var, x);
}

void	check_lines(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	y = var->count_line - 1;
	while (var->map[0][x] && var->map[0][x] != '\n')
	{
		if (var->map[0][x] == ' ')
			handle_space_in_lines(var, x, "first");
		if (var->map[0][x] != ' ' && var->map[0][x] != '1')
			error_map("First Line", var);
		x++;
	}
	x = 0;
	while (var->map[y][x] && var->map[y][x] != '\n')
	{
		if (var->map[y][x] == ' ')
			handle_space_in_lines(var, x, "last");
		if (var->map[y][x] != ' ' && var->map[y][x] != '1')
			error_map("Last Line", var);
		x++;
	}
}
