/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:15:06 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 12:24:35 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	normalize_angle(t_var *var)
{
	var->player->rotatin_angle = fmod(var->player->rotatin_angle, 2 * M_PI);
	if (var->player->rotatin_angle < 0)
		var->player->rotatin_angle += 2 * M_PI;
}

void	normalizingray_angle(t_var *var)
{
	var->ray->ray_angle = fmod(var->ray->ray_angle, 2 * M_PI);
	if (var->ray->ray_angle < 0)
		var->ray->ray_angle += 2 * M_PI;
}
