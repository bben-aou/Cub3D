/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:54:08 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/08 14:56:56 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



void my_img_pix_put2(t_var *var, int x, int y, int color)
{
    char *pixel;

    pixel = var->mlx->imgWall->addr + (y * var->mlx->imgWall->line_len + x * (var->mlx->imgWall->bpp / 8));
    *(unsigned int *)pixel = color;
}



void	drawWall(double x1, double y1, double y2, double x2 ,t_var *var)
{
	
	double  deltaX;
    double  deltaY;
	double	newX;
	double	newY;
	double	step;
	int		i;
    double xr,yr ;



    xr = x2;
    yr = y2;

		

	deltaX = xr - x1;
	deltaY = yr - y1;
	

	if (fabs(deltaX) >= fabs(deltaY))
		step = fabs(deltaX);
	else
		step = fabs(deltaY);
	
	deltaX = deltaX / step;
  	deltaY = deltaY / step;
	newX = x1;  	
	newY =y1;

  	i = 1;
	while (i <= step)
	{
		my_img_pix_put2(var ,newX, newY ,0x636369); // bcbcbc best color
		newX = newX + deltaX;
		newY = newY + deltaY;
    	i++;
	}
}