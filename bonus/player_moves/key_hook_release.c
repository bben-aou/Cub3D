/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:16:04 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:30:36 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	key_hookb(int key, t_varb *var)
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
	if (key == 46)
		var->mini_map_hook = 1;
	if (key == 53)
		crossb(var);
	return (0);
}

void	key_releaseb_part1b(int key, t_varb *var)
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

int	key_releaseb(int key, t_varb *var)
{
	key_releaseb_part1b(key, var);
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
		crossb(var);
	return (0);
}
