/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:13:58 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/15 17:01:29 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	calcul_steps_hb(t_varb *var)
{
	var->ray->ystep = T_S;
	if (var->view->facing_up == 1)
		var->ray->ystep *= -1;
	var->ray->xstep = var->ray->ystep / tan(var->ray->ray_angle);
	if (var->view->facing_left && var->ray->xstep > 0)
		var->ray->xstep *= -1;
	if (var->view->facing_right && var->ray->xstep < 0)
		var->ray->xstep *= -1;
}

void	calcul_intercept_steps_hb(t_varb *var, double *next_x, double *next_y)
{
	var->ray->yintercept = floor(var->player->y / T_S) * T_S;
	if (var->view->facing_down == 1)
		var->ray->yintercept += T_S;
	var->ray->xintercept = var->player->x + \
		(var->ray->yintercept - var->player->y) / tan(var->ray->ray_angle);
	*next_x = var->ray->xintercept;
	*next_y = var->ray->yintercept;
	calcul_steps_hb(var);
}

void	get_intersectionb_horzb(t_varb *var)
{
	double	next_x;
	double	next_y;
	int		check;

	check = 0;
	var->ray->horz_wall_found = false;
	calcul_intercept_steps_hb(var, &next_x, &next_y);
	if (var->view->facing_up == 1)
		check = 1;
	while (next_x >= 0 && next_x <= var->mlx->max_len * T_S
		&& next_y - check >= 0 && next_y - check <= T_S * var->count_line)
	{
		if (check_if_wallb(var, next_x, next_y - check))
		{
			var->ray->horz_wall_found = true;
			var->ray->horz_wall_hit_x = next_x;
			var->ray->horz_wall_hit_y = next_y;
			break ;
		}
		else
		{
			next_x += var->ray->xstep;
			next_y += var->ray->ystep;
		}
	}
}
