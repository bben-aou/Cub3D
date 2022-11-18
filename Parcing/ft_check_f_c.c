/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_f_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:18:41 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 09:56:54 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* The main function of cheking errors and storing the data if it's valide */

void	ft_check_floor_ceilling(t_var *var, int *valid_id)
{
	if (ft_strcmp(var->tmp_map[0], "F") == 0 \
	|| ft_strcmp(var->tmp_map[0], "C") == 0)
	{
		ft_check_floor_ceil(var);
		ft_which_id(var);
		store_data_floor_ceil(var);
		*valid_id = 1;
		ft_check_double_id(var);
	}
}

void	ft_check_floor_ceil(t_var *var)
{
	ft_calcul_components(var);
	if (var->components != 2)
	{
		ft_free_array2d(var->tmp_map);
		ft_msg_error("\033[91mInvalid Syntax Floor or Ceilling !\033[91m", var);
	}
}

void	store_data_floor_ceil(t_var *var)
{
	if (var->status == 5)
	{
		var->floor->id = 'F';
		ft_split_convert_rgb(var);
	}
	if (var->status == 6)
	{
		var->ceilling->id = 'C';
		ft_split_convert_rgb(var);
	}
}

void	ft_check_double_id(t_var *var)
{
	if (var->txt->n_txt->only_one > 1)
		ft_msg_error("\033[91mDouble txt NO!\033[91m", var);
	if (var->txt->s_txt->only_one > 1)
		ft_msg_error("\033[91mDouble txt SO !\033[91m", var);
	if (var->txt->w_txt->only_one > 1)
		ft_msg_error("\033[91mDouble txt WE!\033[91m", var);
	if (var->txt->e_txt->only_one > 1)
		ft_msg_error("\033[91mDouble txt EA!\033[91m", var);
	if (var->floor->only_f > 1)
		ft_msg_error("\033[91mDouble Id F!\033[91m", var);
	if (var->ceilling->only_c > 1)
		ft_msg_error("\033[91mDouble Id C!\033[91m", var);
}
