/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:13:58 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 11:21:09 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void calcul_steps_h(t_var *var)
{
    var->ray->ystep = TILE_SIZE;
    if (var->view->facing_up == 1)
        var->ray->ystep *= -1;
    var->ray->xstep = var->ray->ystep / tan(var->ray->ray_angle);
    if (var->view->facing_left && var->ray->xstep > 0)
        var->ray->xstep *= -1;
    if (var->view->facing_right && var->ray->xstep < 0)
        var->ray->xstep *= -1;
}

void calcul_intercept_steps_h(t_var *var, double *next_x, double *next_y)
{
    var->ray->yintercept = floor(var->player->y / TILE_SIZE) * TILE_SIZE;
    if (var->view->facing_down == 1)
        var->ray->yintercept += TILE_SIZE;
    var->ray->xintercept = var->player->x + (var->ray->yintercept - var->player->y)
         / tan(var->ray->ray_angle);
    *next_x = var->ray->xintercept;
    *next_y = var->ray->yintercept;
    calcul_steps_h(var);
}

void get_intersection_horz(t_var *var)
{
    double next_x;
    double next_y;
    int check;

    check = 0;
    var->ray->horz_wall_found = false;
    calcul_intercept_steps_h(var, &next_x, &next_y);
    if (var->view->facing_up == 1)
        check = 1;
    while (next_x >= 0 && next_x <= var->mlx->max_len * TILE_SIZE 
        && next_y - check >= 0 && next_y - check <= TILE_SIZE * var->count_line)
    {
        if (check_if_wall(var, next_x, next_y - check))
        {
            var->ray->horz_wall_found = true;
            var->ray->horz_wall_hit_x = next_x;
            var->ray->horz_wall_hit_y = next_y;
            break;
        }
        else
        {
            next_x += var->ray->xstep;
            next_y += var->ray->ystep;
        }
    }
}