/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering3D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:28:45 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/10 19:12:25 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void my_img_pix_put2(t_var *var, int x, int y, int color)
{
    char *pixel;

    pixel = var->mlx->imgWall->addr + (y * var->mlx->imgWall->line_len + x * (var->mlx->imgWall->bpp / 8));
    *(unsigned int *)pixel = color;
}

void    facing_up_down(t_var *var)
{
        if (var->ray->rayAngle > 0 && var->ray->rayAngle < M_PI)
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

void    facing_right_left(t_var *var)
{

    if (var->ray->rayAngle < (0.5 * M_PI) || var->ray->rayAngle > (1.5 * M_PI))
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

void    get_intersection(t_var *var)
{
    facing_up_down(var);
    facing_right_left(var);
    getIntersectionHorizontal(var);
    getIntersectionVertical(var);
}

void init_texture_img(t_var *var)
{
    var->mlx->imgWall->img = mlx_new_image(var->mlx->init, var->mlx->width, var->mlx->height);
    var->mlx->imgWall->addr = mlx_get_data_addr(var->mlx->imgWall->img, &var->mlx->imgWall->bpp, &var->mlx->imgWall->line_len,
                                                &var->mlx->imgWall->endian);
    var->n_texture = mlx_xpm_file_to_image(var->mlx->init, var->texture->north_texture->path,
                                           &var->texture->north_texture->width_txt, &var->texture->north_texture->height_txt);
    var->texture->north_texture->img->addr = (int *)mlx_get_data_addr(var->n_texture,\
		&var->texture->north_texture->img->bpp, &var->texture->north_texture->img->line_len,\
		&var->texture->north_texture->img->endian);
}

void calcul_for_3d(t_var *var)
{
    double distance_projectin_plan;
    double correct_distance;
	
    correct_distance = var->ray->distance * cos(var->ray->rayAngle - var->player->rotationAngle);
    distance_projectin_plan = (var->mlx->width / 2) / tan(var->ray->fov / 2);
    var->ray->wall_height = (TILE_SIZE / correct_distance) * distance_projectin_plan;
    var->ray->wall_top = (var->mlx->height / 2) - (var->ray->wall_height / 2);
    if (var->ray->wall_top < 0)
        var->ray->wall_top = 0;
    var->ray->wall_bottom = var->ray->wall_height + var->ray->wall_top;
    if (var->ray->wall_bottom > var->mlx->height)
    	var->ray->wall_bottom = var->mlx->height;
}

void rendering3D(t_var *var)
{
    int id;

    id = 0;
    var->ray->rayAngle = var->player->rotationAngle - var->ray->fov / 2;
    init_texture_img(var);
    drawCeillingFloor(var);
    while (id < var->mlx->width)
    {
        normalizingRayAngle(var);
        get_intersection(var);
        compare_distance(var);
		calcul_for_3d(var);
        draw_texture(var, id);
        var->ray->rayAngle += var->ray->fov / var->mlx->width;
        id++;
    }
    mlx_put_image_to_window(var->mlx->init, var->mlx->win, var->mlx->imgWall->img, 0, 0);
    mlx_destroy_image(var->mlx->init, var->mlx->imgWall->img);
}
