/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:09:17 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/15 17:01:49 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	calcul_steps_vb(t_varb *var)
{
	var->ray->x_vert_step = T_S;
	if (var->view->facing_left == 1)
		var->ray->x_vert_step *= -1;
	var->ray->y_vert_step = var->ray->x_vert_step * tan(var->ray->ray_angle);
	if (var->view->facing_up && var->ray->y_vert_step > 0)
		var->ray->y_vert_step *= -1;
	if (var->view->facing_down && var->ray->y_vert_step < 0)
		var->ray->y_vert_step *= -1;
}

void	calcul_intercept_steps_vb(t_varb *var, double *next_x, double *next_y)
{
	var->ray->x_vert_intercept = floor(var->player->x / T_S) * T_S;
	if (var->view->facing_right == 1)
		var->ray->x_vert_intercept += T_S;
	var->ray->y_vert_intercept = var->player->y + \
		(var->ray->x_vert_intercept - var->player->x) \
			* tan(var->ray->ray_angle);
	*next_x = var->ray->x_vert_intercept;
	*next_y = var->ray->y_vert_intercept;
	calcul_steps_vb(var);
}

void	get_intersectionb_vertb(t_varb *var)
{
	double	next_x;
	double	next_y;
	int		check;

	check = 0;
	var->ray->vert_wall_found = false;
	calcul_intercept_steps_vb(var, &next_x, &next_y);
	if (var->view->facing_left)
		check = 1;
	while (next_x - check >= 0 && next_x - check <= var->mlx->max_len \
		* T_S && next_y >= 0 && next_y <= T_S * var->count_line)
	{
		if (check_if_wallb(var, next_x - check, next_y))
		{
			var->ray->vert_wall_found = true;
			var->ray->vert_wall_hit_x = next_x;
			var->ray->vert_wall_hit_y = next_y;
			break ;
		}
		else
		{
			next_x += var->ray->x_vert_step;
			next_y += var->ray->y_vert_step;
		}
	}
}
