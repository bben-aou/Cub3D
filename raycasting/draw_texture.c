/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:26:49 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 12:06:24 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calcul_xoffset(t_var *var)
{
	if (var->ray->was_hit_vert)
		var->ray->offset_x = var->ray->y_wall_hit;
	else
		var->ray->offset_x = var->ray->x_wall_hit;
	var->ray->offset_x /= T_S;
	var->ray->offset_x -= floor(var->ray->offset_x);
	var->ray->offset_x *= var->txt->n_txt->width_txt;
}

void	get_color_from_txt(t_var *var)
{
	int	pixel;

	pixel = 0;
	if (var->ray->was_hit_vert)
	{
		if (var->view->facing_right)
			pixel = var->txt->e_txt->img->addr \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
		else if (var->view->facing_left)
			pixel = var->txt->w_txt->img->addr \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
	}
	else
	{
		if (var->view->facing_down)
			pixel = var->txt->s_txt->img->addr \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
		else if (var->view->facing_up)
			pixel = var->txt->n_txt->img->addr \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
	}
	var->ray->p_color = pixel;
}

void	draw_txt(t_var *var, int id)
{
	double	y;

	y = var->ray->wall_top;
	calcul_xoffset(var);
	while (y < var->ray->wall_bottom)
	{
		var->ray->offset_y = y + (var->ray->wall_height / 2) \
			- (var->mlx->height / 2);
		if (var->ray->offset_y < 0)
			var->ray->offset_y = 0;
		var->ray->offset_y = var->ray->offset_y * \
			(var->txt->n_txt->height_txt / var->ray->wall_height);
		var->ray->offset_y = floor(var->ray->offset_y);
		var->ray->offset_y *= var->txt->n_txt->width_txt;
		get_color_from_txt(var);
		my_img_pix_put2(var, id, y, var->ray->p_color);
		y++;
	}
}
