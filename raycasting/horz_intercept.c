/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:13:58 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/10 18:17:34 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void calcul_steps_h(t_var *var)
{
    var->ray->ystep = TILE_SIZE;
    if (var->view->facing_up == 1)
        var->ray->ystep *= -1;
    var->ray->xstep = var->ray->ystep / tan(var->ray->rayAngle);
    if (var->view->facing_left && var->ray->xstep > 0)
        var->ray->xstep *= -1;
    if (var->view->facing_right && var->ray->xstep < 0)
        var->ray->xstep *= -1; 
}

void calcul_first_intercept_h(t_var *var)
{
    var->ray->yintercept = floor(var->player->y / TILE_SIZE) * TILE_SIZE;
    if ( var->view->facing_down == 1)
        var->ray->yintercept += TILE_SIZE;
    var->ray->xintercept = var->player->x + (var->ray->yintercept - var->player->y) / tan(var->ray->rayAngle);
}

void    getIntersectionHorizontal(t_var *var)
{
    double  next_horz_x;
    double  next_horz_y;

    var->ray->horz_wall_found = false;
    calcul_first_intercept_h(var);
    calcul_steps_h(var);
    next_horz_x = var->ray->xintercept;
    next_horz_y = var->ray->yintercept;
    if (var->view->facing_up == 1)
        next_horz_y -= 1;
    while (next_horz_x >= 0 && next_horz_x <= var->mlx->width && next_horz_y >= 0 && next_horz_y <= var->mlx->height )
    {
        if (var->map[(int)floor(next_horz_y / TILE_SIZE)][(int)floor(next_horz_x / TILE_SIZE)] == '1')
        {
            var->ray->horz_wall_found = true;
            var->ray->horizontalWallHitX = next_horz_x;
            var->ray->horizontalWallHitY = next_horz_y + 1 ;
            break;
        }
        else
        {
            next_horz_x += var->ray->xstep;
            next_horz_y += var->ray->ystep;
        }
    }
}