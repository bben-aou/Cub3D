/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:16:04 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 12:25:49 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_hook(int key, t_var *var)
{
	if (key == 123)
		var->key_pressed->key_turn_left = 1;
	if (key == 124)
		var->key_pressed->key_turn_right = 1;
	if (key == 13)
		var->key_pressed->key_w = 1;
	if (key == 1)
		var->key_pressed->key_s = 1;
	if (key == 0)
		var->key_pressed->key_a = 1;
	if (key == 2)
		var->key_pressed->key_d = 1;
	if (key == 53)
		cross(var);
	return (0);
}

void	key_release_part1(int key, t_var *var)
{
	if (key == 123)
	{
		var->player->turn_left_right = 0;
		var->key_pressed->key_turn_left = 0;
	}
	if (key == 124)
	{
		var->player->turn_left_right = 0;
		var->key_pressed->key_turn_right = 0;
	}
	if (key == 13)
	{
		var->player->walk_back_forward = 0;
		var->key_pressed->key_w = 0;
	}
}

int	key_release(int key, t_var *var)
{
	key_release_part1(key, var);
	if (key == 1)
	{
		var->player->walk_back_forward = 0;
		var->key_pressed->key_s = 0;
	}
	if (key == 0)
	{
		var->player->walk_back_forward = 0;
		var->key_pressed->key_a = 0;
	}
	if (key == 2)
	{
		var->player->walk_back_forward = 0;
		var->key_pressed->key_d = 0;
	}
	if (key == 53)
		cross(var);
	return (0);
}
