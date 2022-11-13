/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerTools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:22:44 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/13 14:13:41 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//     ----------------------- Function of setting Up All the data at the first run : ---------------------------- //

void set_up_all(t_var *var)
{
    var->player->size_player = 2;
    var->player->turn_left_right = 0;
    var->player->walk_back_forward = 0;
    var->player->rotation_speed = 5 * (M_PI / 180);
    var->player->move_speed = 5;
    var->ray->fov = 60 * (M_PI / 180);
}

//     ----------------------- Get Weight and Height : ---------------------------- //

void set_map_size(t_var *var)
{
    int next;
    int y;

    y = 0;
    var->mlx->max_len = ft_strlen1(var->map[0]);
    while (++y < var->count_line)
    {
        next = ft_strlen1(var->map[y]);
        if (var->mlx->max_len < next)
            var->mlx->max_len = next;
    }
    var->mlx->width = 1080;
    var->mlx->height = 1080;
}
