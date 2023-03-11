/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:18:56 by bben-aou          #+#    #+#             */
/*   Updated: 2023/03/11 10:54:15 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

void	dda_line(t_varb *var)
{
	int	i;

	var->dda_data.xr = (var->player->x) + cos(var->player->rotatin_angle) * 20;
	var->dda_data.yr = (var->player->y) + sin(var->player->rotatin_angle) * 20;
	var->dda_data.delta_x = var->dda_data.xr - var->player->x;
	var->dda_data.delta_y = var->dda_data.yr - var->player->y;
	if (fabs(var->dda_data.delta_x) >= fabs(var->dda_data.delta_y))
		var->dda_data.step = fabs(var->dda_data.delta_x);
	else
		var->dda_data.step = fabs(var->dda_data.delta_y);
	var->dda_data.delta_x = var->dda_data.delta_x / var->dda_data.step;
	var->dda_data.delta_y = var->dda_data.delta_y / var->dda_data.step;
	var->dda_data.new_x = var->player->x;
	var->dda_data.new_y = var->player->y;
	i = 1;
	while (i <= var->dda_data.step)
	{
		my_img_pix_putb(var, var->dda_data.new_x * 0.2, \
			var->dda_data.new_y * 0.2, 0xF1C40F );
		var->dda_data.new_x = var->dda_data.new_x + var->dda_data.delta_x;
		var->dda_data.new_y = var->dda_data.new_y + var->dda_data.delta_y;
		i++;
	}
}
