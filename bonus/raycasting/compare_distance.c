/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:00:31 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:31:01 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

double	get_horz_distanceb(t_varb *var)
{
	double	value;
	double	delta_x;
	double	delta_y;

	delta_x = pow(var->ray->horz_wall_hit_x - var->player->x, 2);
	delta_y = pow(var->ray->horz_wall_hit_y - var->player->y, 2);
	value = sqrt(delta_x + delta_y);
	return (value);
}

double	get_vert_distanceb(t_varb *var)
{
	double	value;
	double	delta_x;
	double	delta_y;

	delta_x = pow(var->ray->vert_wall_hit_x - var->player->x, 2);
	delta_y = pow(var->ray->vert_wall_hit_y - var->player->y, 2);
	value = sqrt(delta_x + delta_y);
	return (value);
}

void	compare_distanceb_hereb(t_varb *var)
{
	if (var->ray->horz_distance < var->ray->vert_distance)
	{
		var->ray->x_wall_hit = var->ray->horz_wall_hit_x;
		var->ray->y_wall_hit = var->ray->horz_wall_hit_y;
	}
	else
	{
		var->ray->x_wall_hit = var->ray->vert_wall_hit_x;
		var->ray->y_wall_hit = var->ray->vert_wall_hit_y;
	}
	if (var->ray->horz_distance < var->ray->vert_distance)
		var->ray->distance = var->ray->horz_distance;
	else
		var->ray->distance = var->ray->vert_distance;
	if (var->ray->vert_distance < var->ray->horz_distance)
		var->ray->was_hit_vert = true;
	else
		var->ray->was_hit_vert = false;
}

void	compare_distanceb(t_varb *var)
{
	if (var->ray->horz_wall_found == true)
		var->ray->horz_distance = get_horz_distanceb(var);
	else
		var->ray->horz_distance = LONG_MAX;
	if (var->ray->vert_wall_found == true)
		var->ray->vert_distance = get_vert_distanceb(var);
	else
		var->ray->vert_distance = LONG_MAX;
	compare_distanceb_hereb(var);
}
