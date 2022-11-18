/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawFloorAndCeilling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:57:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 11:31:12 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_ceil_floor(t_var *var)
{
	int	t;
	int	v;

	t = 0;
	while (t < var->mlx->height)
	{
		v = 0;
		while (v < var->mlx->width)
		{
			if (t <= var->mlx->height / 2)
				my_img_pix_put2(var, v, t, var->floor->f_color);
			else
				my_img_pix_put2(var, v, t, var->ceilling->c_color);
			v++;
		}
		t++;
	}
}
