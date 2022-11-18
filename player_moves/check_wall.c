/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:17:29 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 13:10:04 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_wall_forward(t_var *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x + cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y + sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	check_wall_back(t_var *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x - cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y - sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	check_wall_right_side(t_var *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x - sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y + cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	check_wall_left_side(t_var *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x + sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y - cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	wall_status(t_var *var, int status, int *ps_x, int *ps_y)
{
	if (status == 1)
		check_wall_forward(var, ps_x, ps_y);
	else if (status == 2)
		check_wall_back(var, ps_x, ps_y);
	else if (status == 3)
		check_wall_right_side(var, ps_x, ps_y);
	else if (status == 4)
		check_wall_left_side(var, ps_x, ps_y);
}
