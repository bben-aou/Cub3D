/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawFloorAndCeilling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:57:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/13 14:19:16 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_ceil_floor(t_var *var)
{
    int t = 0, v = 0;
    while (t < var->mlx->height)
    {
        v = 0;
        while (v < var->mlx->width)
        {
            if (t <= var->mlx->height / 2)
                my_img_pix_put2(var, v, t, (int)var->clrf->hex_color); // 0x509ee5
            else
                my_img_pix_put2(var, v, t, (int)var->clrc->hex_color); // 0xEEEEEE
            v++;
        }
        t++;
    }
}
