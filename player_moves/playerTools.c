/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerTools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:22:44 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/12 11:37:02 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//     ----------------------- Function of setting Up All the data at the first run : ---------------------------- //

void    setUpAll(t_var *var)
{
    var->player->sizePlayer = 2;
    var->player->turnLeftRight = 0;
    var->player->walkBackForward = 0;
    var->player->rotationSpeed = 5 * (M_PI / 180);
    var->player->moveSpeed = 5;
    var->ray->fov = 60 * (M_PI / 180 );
}


//     ----------------------- Get Weight and Height : ---------------------------- //


void    set_map_size(t_var *var)
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
