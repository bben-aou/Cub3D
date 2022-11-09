/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:02:11 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/09 17:45:47 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    launchRays(t_var *var)
{
    double  deltaX;
    double  deltaY;
	double	newX;
	double	newY;
	double	step;
	int		i;
    double xr,yr ;



    xr = var->ray->xWallHit;
    yr = var->ray->yWallHit;

		

	deltaX = xr - var->player->x;
	deltaY = yr - var->player->y;
	

	if (fabs(deltaX) >= fabs(deltaY))
		step = fabs(deltaX);
	else
		step = fabs(deltaY);
	
	deltaX = deltaX / step;
  	deltaY = deltaY / step;
	newX = var->player->x;  	
	newY =var->player->y;

  	i = 1;
	while (i <= step)
	{
		mlx_pixel_put(var->mlx, var->mlx->win, newX * SCALE_MINI_MAP ,newY * SCALE_MINI_MAP, 0x0032a0);
		newX = newX + deltaX;
		newY = newY + deltaY;
    	i++;
	}
    
}