/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:15:06 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:30:46 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	normalize_angleb(t_varb *var)
{
	var->player->rotatin_angle = fmod(var->player->rotatin_angle, 2 * M_PI);
	if (var->player->rotatin_angle < 0)
		var->player->rotatin_angle += 2 * M_PI;
}

void	normalizingray_angleb(t_varb *var)
{
	var->ray->ray_angle = fmod(var->ray->ray_angle, 2 * M_PI);
	if (var->ray->ray_angle < 0)
		var->ray->ray_angle += 2 * M_PI;
}
