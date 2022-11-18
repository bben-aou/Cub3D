/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:28:09 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 17:39:28 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_split_bonus_convert_rgbb_p1b(t_varb *var)
{
	int	i;

	i = 0;
	if (var->status == 5)
	{
		while (i < 3)
		{
			var->floor->color[i] = ft_atoi_b(var->tmp_rgb[i]);
			ft_valid_valueb(var->floor->color[i], var);
			i++;
		}
		var->floor->only_f += 1;
	}
}

void	ft_split_bonus_convert_rgbb(t_varb *var)
{
	int	i;

	i = 0;
	var->tmp_rgb = ft_split_bonus(var->tmp_map[1], ',');
	if (var->tmp_rgb == NULL)
		ft_msg_errorb("\033[91mInvalid RGB syntax !\033[91m", var);
	ft_check_valid_rgb(var);
	ft_split_bonus_convert_rgbb_p1b(var);
	if (var->status == 6)
	{
		while (i < 3)
		{
			var->ceilling->color[i] = ft_atoi_b(var->tmp_rgb[i]);
			ft_valid_valueb(var->ceilling->color[i], var);
			i++;
		}
		var->ceilling->only_c += 1;
	}
	ft_freeb_array2db(var->tmp_rgb);
	var->tmp_rgb = NULL;
}

void	ft_check_valid_rgb(t_varb *var)
{
	int	i;

	i = 0;
	while (var->tmp_rgb[i])
		i++;
	if (i != 3)
	{
		if (var->tmp_map)
		{
			ft_freeb_array2db(var->tmp_map);
			var->tmp_map = NULL;
		}
		error_map_b("RGB Value should be in this form exp : 0,255,255 !", var);
	}
}

void	ft_valid_valueb(int nbr, t_varb *var)
{
	if (nbr < 0)
		ft_msg_errorb("\033[91mNegative Value in RGB !\033[91m", var);
	if (nbr > 255)
		ft_msg_errorb("\033[91mValue > 255 !\033[91m", var);
}
