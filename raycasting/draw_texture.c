/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:26:49 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/11 18:17:30 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void calcul_xoffset(t_var *var)
{
    if (var->ray->wasHitVertical)
        var->ray->offset_x = var->ray->yWallHit;
    else
        var->ray->offset_x = var->ray->xWallHit;
    var->ray->offset_x /= TILE_SIZE;
    var->ray->offset_x -= floor(var->ray->offset_x);
    var->ray->offset_x *= var->texture->north_texture->width_txt;
}

void get_color_from_texture(t_var *var)
{
    int pixel = 0;

    // pixel = NULL;
    if (var->ray->wasHitVertical)
    {
        if (var->view->facing_right)
            pixel = var->texture->east_texture->img->addr[((int)var->ray->offset_y  + (int)var->ray->offset_x)];
        else if (var->view->facing_left)
            pixel = var->texture->west_texture->img->addr[((int)var->ray->offset_y  + (int)var->ray->offset_x)];
    }
    else
    {
        if (var->view->facing_down)
            pixel = var->texture->south_texture->img->addr[((int)var->ray->offset_y  + (int)var->ray->offset_x)];
        else if (var->view->facing_up)
            pixel = var->texture->north_texture->img->addr[((int)var->ray->offset_y  + (int)var->ray->offset_x)];
    }
    var->ray->p_color = pixel;
}

void draw_texture(t_var *var, int id)
{
    // int     distance_from_top = 0;
    double y;

    y = var->ray->wall_top;
    calcul_xoffset(var);
    while (y < var->ray->wall_bottom)
    {
        var->ray->offset_y = y + (var->ray->wall_height / 2) - (var->mlx->height / 2);
        if (var->ray->offset_y < 0)
            var->ray->offset_y = 0;
        var->ray->offset_y = var->ray->offset_y * (var->texture->north_texture->height_txt / var->ray->wall_height);
        var->ray->offset_y = floor(var->ray->offset_y);
        var->ray->offset_y *= var->texture->north_texture->width_txt;
        get_color_from_texture(var);
        my_img_pix_put2(var, id, y, var->ray->p_color);
        y++;
    }
}