/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_f_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:18:41 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 17:02:24 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_check_floor_ceilblingb(t_varb *var, int *valid_id)
{
	if (ft_strcmp_bn(var->tmp_map[0], "F") == 0 \
	|| ft_strcmp_bn(var->tmp_map[0], "C") == 0)
	{
		ft_check_floor_ceilb(var);
		ft_which_idb(var);
		store_data_floor_ceilb(var);
		*valid_id = 1;
		ft_check_double_idb(var);
	}
}

void	ft_check_floor_ceilb(t_varb *var)
{
	ft_calcul_componentsb(var);
	if (var->components != 2)
	{
		ft_freeb_array2db(var->tmp_map);
		ft_msg_errorb("\033[91mInvalid Syntax Floor or Ceilling !\033[91m", var);
	}
}

void	store_data_floor_ceilb(t_varb *var)
{
	if (var->status == 5)
	{
		var->floor->id = 'F';
		ft_split_bonus_convert_rgbb(var);
	}
	if (var->status == 6)
	{
		var->ceilling->id = 'C';
		ft_split_bonus_convert_rgbb(var);
	}
}

void	ft_check_double_idb(t_varb *var)
{
	if (var->txt->n_txt->only_one > 1)
		ft_msg_errorb("\033[91mDouble txt NO!\033[91m", var);
	if (var->txt->s_txt->only_one > 1)
		ft_msg_errorb("\033[91mDouble txt SO !\033[91m", var);
	if (var->txt->w_txt->only_one > 1)
		ft_msg_errorb("\033[91mDouble txt WE!\033[91m", var);
	if (var->txt->e_txt->only_one > 1)
		ft_msg_errorb("\033[91mDouble txt EA!\033[91m", var);
	if (var->floor->only_f > 1)
		ft_msg_errorb("\033[91mDouble Id F!\033[91m", var);
	if (var->ceilling->only_c > 1)
		ft_msg_errorb("\033[91mDouble Id C!\033[91m", var);
}
