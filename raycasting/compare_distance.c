/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:00:31 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/10 19:14:02 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double  get_horz_distance(t_var *var)
{
    double  value;
    double  deltaX;
    double  deltaY;
    
    deltaX = pow(var->ray->horizontalWallHitX - var->player->x, 2);
    deltaY = pow(var->ray->horizontalWallHitY - var->player->y, 2);
    value = sqrt(deltaX + deltaY);
    return (value);
}

double  get_vert_distance(t_var *var)
{
    double  value;
    double  deltaX;
    double deltaY;

    deltaX = pow(var->ray->vert_wall_hit_x - var->player->x, 2);
    deltaY = pow(var->ray->vert_wall_hit_y - var->player->y, 2);
    value = sqrt(deltaX + deltaY);
    return (value);
}

void compare_distance_here(t_var *var)
{
    if (var->ray->horizDistance < var->ray->verticDistance)
    {
        var->ray->xWallHit = var->ray->horizontalWallHitX;
        var->ray->yWallHit = var->ray->horizontalWallHitY;

    }
    else
    {
        var->ray->xWallHit = var->ray->vert_wall_hit_x;
        var->ray->yWallHit = var->ray->vert_wall_hit_y;

    }
    if (var->ray->horizDistance < var->ray->verticDistance)
        var->ray->distance = var->ray->horizDistance;
    else  
        var->ray->distance = var->ray->verticDistance;
    
    if (var->ray->verticDistance < var->ray->horizDistance)
        var->ray->wasHitVertical = true;
    else
        var->ray->wasHitVertical = false;
    
}

void compare_distance(t_var *var)
{
    if (var->ray->horz_wall_found == true)
        var->ray->horizDistance = get_horz_distance(var);
    else
        var->ray->horizDistance = LONG_MAX;
    if (var->ray->vert_wall_found == true)
        var->ray->verticDistance = get_vert_distance(var);
    else
        var->ray->verticDistance = LONG_MAX;
    compare_distance_here(var);
}
