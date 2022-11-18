/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:09:41 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:29:07 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_initb_txtbs_varb(t_varb *var)
{
	var->txt->n_txt->only_one = 0;
	var->txt->s_txt->only_one = 0;
	var->txt->w_txt->only_one = 0;
	var->txt->e_txt->only_one = 0;
	var->floor->only_f = 0;
	var->ceilling->only_c = 0;
}

void	ft_initb_raycastingb_varb(t_varb *var)
{
	var->ray->x_wall_hit = 0;
	var->ray->y_wall_hit = 0;
	var->ray->horz_wall_found = 0;
	var->ray->horz_wall_hit_x = 0;
	var->ray->horz_wall_hit_y = 0;
	var->ray->vert_wall_hit_x = 0;
	var->ray->vert_wall_hit_y = 0;
	var->ray->vert_wall_found = 0;
	var->ray->distance = 0;
	var->ray->was_hit_vert = 0;
}

void	ft_initb_facing_varb(t_varb *var)
{
	var->view->facing_down = 0;
	var->view->facing_up = 0;
	var->view->facing_right = 0;
	var->view->facing_left = 0;
}

void	ft_initb(t_varb *var)
{
	ft_allocation_varb(var);
	ft_initb_txtbs_varb(var);
	ft_initb_raycastingb_varb(var);
	ft_initb_facing_varb(var);
	var->components = 0;
	var->status = 0;
	var->count_playerb = 0;
}

void	init_keysb(t_varb *var)
{
	var->key_pressed->key_w = 0;
	var->key_pressed->key_s = 0;
	var->key_pressed->key_d = 0;
	var->key_pressed->key_a = 0;
	var->key_pressed->key_turn_left = 0;
	var->key_pressed->key_turn_right = 0;
	var->mini_map_hook = 0;
}
