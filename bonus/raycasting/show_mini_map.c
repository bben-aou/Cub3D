/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:55:11 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:32:09 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	show_mini_map(t_varb *var)
{
	if (var->mini_map_hook == 1)
	{
		draw_player(var);
		draw_mini_map(var);
	}
}
