/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showMiniMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:26:00 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 10:01:57 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

void rendering_3d_bonus(t_varb *var)
{
    int i;
    double distanceProjectionPlane;
    double walllHeight;
    double correctDistance;
    double y1;
    double y2;

    i = 0;
    //  ----------------------------------  img of walls ---------------------------------------------------------------------//
    var->mlx->imgWall->img = mlx_new_image(var->mlx->init, var->mlx->width, var->mlx->height);
    var->mlx->imgWall->addr = mlx_get_data_addr(var->mlx->imgWall->img, &var->mlx->imgWall->bpp, &var->mlx->imgWall->line_len,
                                                &var->mlx->imgWall->endian);
    // --------------------------------------------------------------------------------------------------------------------- //

    var->ray->rayAngle = var->player->rotationAngle - var->ray->fov / 2;

    // -------------- draw Ceilling and Floor --------- //
    drawCeillingFloorB(var);
    while (i < var->mlx->width)
    {
        normalizingRayAngleB(var);
        getIntersectionHorizontalB(var);
        getIntersectionVerticalB(var);
        correctDistance = var->ray->distance * cos(var->ray->rayAngle - var->player->rotationAngle);
        distanceProjectionPlane = (var->mlx->width / 2) / tan(var->ray->fov / 2);
        walllHeight = (TILE_SIZE / correctDistance) * distanceProjectionPlane;
        y1 = (var->mlx->height / 2) - (walllHeight / 2);
        if (y1 < 0)
            y1 = 0;
        y2 = walllHeight + y1;
        if (y2 > var->mlx->height)
            y2 = var->mlx->height;

        //  ----------- draw Walls ------------- //
        draw_wall_bonus(i, y1, y2, i, var);
        var->ray->rayAngle += var->ray->fov / var->mlx->width;
        i++;
    }
    if (var->miniMapHook == 1)
    {
        draw_player_bonus(var);
        draw_mini_mapB(var);
    }
    mlx_put_image_to_window(var->mlx->init, var->mlx->win, var->mlx->imgWall->img, 0, 0);
    mlx_destroy_image(var->mlx->init, var->mlx->imgWall->img);
}