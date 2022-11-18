/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:37:41 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 12:44:19 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_var *var)
{
	if (var->key_pressed->key_w == 1)
	{
		if (check_wall(var, 1) == 0)
		{
			var->player->walk_back_forward = 1;
			var->player->move_step = var->player->walk_back_forward * \
			var->player->move_speed;
			var->player->x += cos(var->player->rotatin_angle) * \
			var->player->move_speed;
			var->player->y += sin(var->player->rotatin_angle) * \
			var->player->move_speed;
		}
	}
}

void	move_back(t_var *var)
{
	if (var->key_pressed->key_s == 1)
	{
		if (check_wall(var, 2) == 0)
		{
			var->player->walk_back_forward = -1;
			var->player->move_step = var->player->walk_back_forward * \
			var->player->move_speed;
			var->player->x -= cos(var->player->rotatin_angle) * \
			var->player->move_speed;
			var->player->y -= sin(var->player->rotatin_angle) * \
			var->player->move_speed;
		}
	}
}

void	move_right_side(t_var *var)
{
	if (var->key_pressed->key_d == 1)
	{
		if (check_wall(var, 3) == 0)
		{
			var->player->walk_back_forward = 1;
			var->player->move_step = var->player->walk_back_forward * \
			var->player->move_speed;
			var->player->x -= sin(var->player->rotatin_angle) * \
			var->player->move_speed;
			var->player->y += cos(var->player->rotatin_angle) * \
			var->player->move_speed;
		}
	}
}

void	move_left_side(t_var *var)
{
	if (var->key_pressed->key_a == 1)
	{
		if (check_wall(var, 4) == 0)
		{
			var->player->walk_back_forward = -1;
			var->player->move_step = var->player->walk_back_forward * \
			var->player->move_speed;
			var->player->x += sin(var->player->rotatin_angle) * \
			var->player->move_speed;
			var->player->y -= cos(var->player->rotatin_angle) * \
			var->player->move_speed;
		}
	}
}

void	key_pressed_action(t_var *var)
{
	normalize_angle(var);
	move_forward(var);
	move_back(var);
	move_right_side(var);
	move_left_side(var);
	if (var->key_pressed->key_turn_left == 1)
		var->player->turn_left_right = -1;
	if (var->key_pressed->key_turn_right == 1)
		var->player->turn_left_right = 1;
}
