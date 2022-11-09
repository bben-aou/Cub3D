/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawFloorAndCeilling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:57:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/09 16:21:48 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void drawCeillingFloor(t_var *var)
{
    int t = 0 , v =0;
    while (t < var->mlx->height)
    {
        v = 0;
        while (v < var->mlx->width)
        {
            if (t <= var->mlx->height/2 )
		        my_img_pix_put2(var, v, t, 0x509ee5);
            else
		        my_img_pix_put2(var, v, t, 0xEEEEEE);
            v++;
        }
        t++;
    }
}

