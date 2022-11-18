/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_in_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:58:33 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 13:13:32 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall_case1(t_var *var, int *ps_x, int *ps_y)
{
	if (var->map[*ps_y][*ps_x - 1] == '1' && \
	var->map[*ps_y + 1][*ps_x] == '1')
		if ((floor((var->player->y / T_S)) == *ps_y + 1) && \
		(floor((var->player->x / T_S)) == *ps_x - 1))
			return (1);
	if (var->map[*ps_y][*ps_x + 1] == '1' && \
	var->map[*ps_y - 1][*ps_x] == '1')
		if ((floor((var->player->y / T_S)) == *ps_y - 1) && \
		(floor((var->player->x / T_S)) == *ps_x + 1))
			return (1);
	return (0);
}

int	check_wall(t_var *var, int status)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	pos_y = 0;
	wall_status(var, status, &pos_x, &pos_y);
	if (var->map[pos_y][pos_x] == '1')
		return (1);
	check_wall_case1(var, &pos_x, &pos_y);
	if (var->map[pos_y][pos_x + 1] == '1' && \
	var->map[pos_y][pos_x + 1] == '1')
		if ((floor((var->player->y / T_S)) == pos_y + 1) && \
		(floor((var->player->x / T_S)) == pos_x + 1))
			return (1);
	if (var->map[pos_y][pos_x - 1] == '1' && \
	var->map[pos_y - 1][pos_x] == '1')
		if ((floor((var->player->y / T_S)) == pos_y - 1) && \
		(floor((var->player->x / T_S)) == pos_x - 1))
			return (1);
	return (0);
}
