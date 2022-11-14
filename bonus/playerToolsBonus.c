/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerToolsBonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:52:34 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 11:52:25 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

//     ----------------------- Function of setting Up All the data at the first run : ---------------------------- //

void set_up_all_bonus(t_varb *var)
{
    var->player->sizePlayer = 2;
    var->player->turnLeftRight = 0;
    var->player->walkBackForward = 0;
    var->player->rotationSpeed = 5 * (M_PI / 180);
    var->player->moveSpeed = 5;
    var->ray->fov = 60 * (M_PI / 180);
}

//     ----------------------- Get Weight and Height : ---------------------------- //

void set_map_size_bonus(t_varb *var)
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
    var->mlx->width = var->mlx->max_len * T_S;
    var->mlx->height = var->count_line * T_S;
}