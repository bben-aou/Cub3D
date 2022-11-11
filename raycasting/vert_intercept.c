/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:09:17 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/10 18:16:34 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void calcul_steps_v(t_var *var)
{
    var->ray->x_vert_step = TILE_SIZE;
    if (var->view->facing_left == 1)
        var->ray->x_vert_step *= -1;
    var->ray->y_vert_step = var->ray->x_vert_step * tan(var->ray->rayAngle);
    if (var->view->facing_up && var->ray->y_vert_step > 0)
        var->ray->y_vert_step *= -1;
    if (var->view->facing_down && var->ray->y_vert_step < 0)
        var->ray->y_vert_step *= -1;
    
}

void calcul_first_intercept_v(t_var *var)
{
    var->ray->x_vert_intercept = floor(var->player->x / TILE_SIZE) * TILE_SIZE;
    if (var->view->facing_right == 1)
        var->ray->x_vert_intercept += TILE_SIZE;
    var->ray->y_vert_intercept = var->player->y + (var->ray->x_vert_intercept - var->player->x) * tan(var->ray->rayAngle);
}

void    getIntersectionVertical(t_var *var)
{
    double  next_vert_x;
    double  next_vert_y;

    var->ray->vert_wall_found = false;
    calcul_first_intercept_v(var);
    calcul_steps_v(var);
    next_vert_x  = var->ray->x_vert_intercept;
    next_vert_y  = var->ray->y_vert_intercept;
    if (var->view->facing_left)
         next_vert_x -= 1 ;
    while (next_vert_x >= 0 && next_vert_x <= var->mlx->width && next_vert_y >= 0 && next_vert_y <= var->mlx->height)
    {
        if (var->map[(int)floor(next_vert_y/ TILE_SIZE)][(int)floor(next_vert_x / TILE_SIZE)] == '1')
        {
            var->ray->vert_wall_found = true;
            var->ray->vert_wall_hit_x = next_vert_x  + 1;
            var->ray->vert_wall_hit_y = next_vert_y ;
            break;
        }
        else
        {
            next_vert_x += var->ray->x_vert_step;
            next_vert_y += var->ray->y_vert_step;
        }
    }
}