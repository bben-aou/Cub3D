/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:17:29 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:30:22 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	check_wallb_forwardb(t_varb *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x + cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y + sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	check_wallb_backb(t_varb *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x - cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y - sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	check_wallb_right_sideb(t_varb *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x - sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y + cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	check_wallb_left_sideb(t_varb *var, int *ps_x, int *ps_y)
{
	*ps_x = floor((var->player->x + sin(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
	*ps_y = floor((var->player->y - cos(var->player->rotatin_angle) * \
	var->player->move_speed) / T_S);
}

void	wall_statusb(t_varb *var, int status, int *ps_x, int *ps_y)
{
	if (status == 1)
		check_wallb_forwardb(var, ps_x, ps_y);
	else if (status == 2)
		check_wallb_backb(var, ps_x, ps_y);
	else if (status == 3)
		check_wallb_right_sideb(var, ps_x, ps_y);
	else if (status == 4)
		check_wallb_left_sideb(var, ps_x, ps_y);
}
