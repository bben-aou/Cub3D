/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawFloorAndCeilling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:57:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 20:11:37 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	create_rgbb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_ceil_floorb(t_varb *var)
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
				my_img_pix_putb(var, v, t, var->floor->f_color);
			else
				my_img_pix_putb(var, v, t, var->ceilling->c_color);
			v++;
		}
		t++;
	}
}
