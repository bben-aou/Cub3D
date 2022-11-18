/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:28:45 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:31:11 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	facing_up_downb(t_varb *var)
{
	if (var->ray->ray_angle > 0 && var->ray->ray_angle < M_PI)
	{
		var->view->facing_down = 1;
		var->view->facing_up = 0;
	}
	else
	{
		var->view->facing_down = 0;
		var->view->facing_up = 1;
	}
}

void	facing_right_leftb(t_varb *var)
{
	if (var->ray->ray_angle < (0.5 * M_PI) \
		|| var->ray->ray_angle > (1.5 * M_PI))
	{
		var->view->facing_right = 1;
		var->view->facing_left = 0;
	}
	else
	{
		var->view->facing_left = 1;
		var->view->facing_right = 0;
	}
}

void	get_intersectionb(t_varb *var)
{
	facing_up_downb(var);
	facing_right_leftb(var);
	get_intersectionb_horzb(var);
	get_intersectionb_vertb(var);
}

void	calcul_for_3db(t_varb *var)
{
	double	distance_projectin_plan;
	double	correct_distance;

	correct_distance = var->ray->distance * cos(var->ray->ray_angle \
		- var->player->rotatin_angle);
	distance_projectin_plan = (var->mlx->width / 2) / tan(var->ray->fov / 2);
	var->ray->wall_height = (T_S / correct_distance) * distance_projectin_plan;
	var->ray->wall_top = (var->mlx->height / 2) - (var->ray->wall_height / 2);
	if (var->ray->wall_top < 0)
		var->ray->wall_top = 0;
	var->ray->wall_bottom = var->ray->wall_height + var->ray->wall_top;
	if (var->ray->wall_bottom > var->mlx->height)
		var->ray->wall_bottom = var->mlx->height;
}

void	rendering_3db(t_varb *var)
{
	int	id;

	id = 0;
	var->ray->ray_angle = var->player->rotatin_angle - var->ray->fov / 2;
	var->mlx->full_img->img = mlx_new_image(var->mlx->init, \
		var->mlx->width, var->mlx->height);
	var->mlx->full_img->addr = mlx_get_data_addr(var->mlx->full_img->img, \
		&var->mlx->full_img->bpp, &var->mlx->full_img->line_len, \
			&var->mlx->full_img->endian);
	draw_ceil_floorb(var);
	while (id < var->mlx->width)
	{
		normalizingray_angleb(var);
		get_intersectionb(var);
		compare_distanceb(var);
		calcul_for_3db(var);
		draw_txtb(var, id);
		var->ray->ray_angle += var->ray->fov / var->mlx->width;
		id++;
	}
	show_mini_map(var);
	mlx_put_image_to_window(var->mlx->init, var->mlx->win, \
		var->mlx->full_img->img, 0, 0);
	mlx_destroy_image(var->mlx->init, var->mlx->full_img->img);
}
