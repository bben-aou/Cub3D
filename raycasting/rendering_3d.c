/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:28:45 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 13:05:57 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	facing_up_down(t_var *var)
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

void	facing_right_left(t_var *var)
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

void	get_intersection(t_var *var)
{
	facing_up_down(var);
	facing_right_left(var);
	get_intersection_horz(var);
	get_intersection_vert(var);
}

void	calcul_for_3d(t_var *var)
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

void	rendering_3d(t_var *var)
{
	int	id;

	id = 0;
	var->ray->ray_angle = var->player->rotatin_angle - var->ray->fov / 2;
	var->mlx->full_img->img = mlx_new_image(var->mlx->init, \
		var->mlx->width, var->mlx->height);
	var->mlx->full_img->addr = mlx_get_data_addr(var->mlx->full_img->img, \
		&var->mlx->full_img->bpp, &var->mlx->full_img->line_len, \
			&var->mlx->full_img->endian);
	draw_ceil_floor(var);
	while (id < var->mlx->width)
	{
		normalizingray_angle(var);
		get_intersection(var);
		compare_distance(var);
		calcul_for_3d(var);
		draw_txt(var, id);
		var->ray->ray_angle += var->ray->fov / var->mlx->width;
		id++;
	}
	mlx_put_image_to_window(var->mlx->init, var->mlx->win, \
		var->mlx->full_img->img, 0, 0);
	mlx_destroy_image(var->mlx->init, var->mlx->full_img->img);
}
