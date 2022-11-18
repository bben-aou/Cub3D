/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:37:41 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 17:52:05 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	move_forwardb(t_varb *var)
{
	if (var->key_pressed->key_w == 1)
	{
		if (check_wallb(var, 1) == 0)
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

void	move_backb(t_varb *var)
{
	if (var->key_pressed->key_s == 1)
	{
		if (check_wallb(var, 2) == 0)
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

void	move_right_sideb(t_varb *var)
{
	if (var->key_pressed->key_d == 1)
	{
		if (check_wallb(var, 3) == 0)
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

void	move_left_sideb(t_varb *var)
{
	if (var->key_pressed->key_a == 1)
	{
		if (check_wallb(var, 4) == 0)
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

void	key_pressed_actionb(t_varb *var)
{
	normalize_angleb(var);
	move_forwardb(var);
	move_backb(var);
	move_right_sideb(var);
	move_left_sideb(var);
	if (var->key_pressed->key_turn_left == 1)
		var->player->turn_left_right = -1;
	if (var->key_pressed->key_turn_right == 1)
		var->player->turn_left_right = 1;
}
