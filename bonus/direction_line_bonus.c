/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:54:47 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/10 10:29:49 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"


//     --------------------- Function of drawing line --------------------------- //
void	drawLineBonus(t_varb *var)
{
	
	double  deltaX;
    double  deltaY;
	double	newX;
	double	newY;
	double	step;
	int		i;
    double xr,yr ;



    xr = (var->player->x ) + cos(var->player->rotationAngle) * 20;
    yr = (var->player->y )+ sin(var->player->rotationAngle) *  20;

		

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
		 my_img_pix_put_bonus(var, newX * SCALE_MINI_MAP, newY * SCALE_MINI_MAP, 0xe56025);
		newX = newX + deltaX;
		newY = newY + deltaY;
    	i++;
	}
	
}








// -------------------------------------------------------------------------  //