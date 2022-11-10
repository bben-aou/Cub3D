/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering3D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:28:45 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/10 16:01:11 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    rendering3D(t_var *var)
{
    int i;
    double distanceProjectionPlane;
    double  walllHeight;
    double  correctDistance ;
    double  y1;
    double  y2;

    i = 0;
    //  ----------------------------------  img of walls ---------------------------------------------------------------------//
    var->mlx->imgWall->img = mlx_new_image(var->mlx->init, var->mlx->width , var->mlx->height);
    var->mlx->imgWall->addr = mlx_get_data_addr(var->mlx->imgWall->img, &var->mlx->imgWall->bpp, &var->mlx->imgWall->line_len,
    							&var->mlx->imgWall->endian);
    // --------------------------------------------------------------------------------------------------------------------- //


    
    var->ray->rayAngle = var->player->rotationAngle - var->ray->fov / 2;
    
        // -------------- draw Ceilling and Floor --------- //
        drawCeillingFloor(var);
    while (i < var->mlx->width)
    {
        normalizingRayAngle(var);
        getIntersectionHorizontal(var);
        getIntersectionVertical(var);
            correctDistance = var->ray->distance * cos(var->ray->rayAngle - var->player->rotationAngle);
            distanceProjectionPlane = (var->mlx->width / 2) / tan(var->ray->fov / 2);
            walllHeight  = (TILE_SIZE / correctDistance) * distanceProjectionPlane ;
            y1 = (var->mlx->height / 2) - (walllHeight / 2);
            if (y1 < 0)
                y1 = 0;
            y2 = walllHeight + y1;
            if (y2 > var->mlx->height)
                y2 = var->mlx->height;

            //  ----------- draw Walls ------------- //    
            drawWall(i ,y1, y2,i,var); 
        var->ray->rayAngle += var->ray->fov / var->mlx->width;  
        i++;
    }
    mlx_put_image_to_window(var->mlx->init, var->mlx->win, var->mlx->imgWall->img, 0, 0);
    mlx_destroy_image(var->mlx->init, var->mlx->imgWall->img);
}