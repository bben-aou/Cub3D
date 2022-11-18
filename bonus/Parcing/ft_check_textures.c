/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:25:35 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 17:39:15 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_check_txtsb(t_varb *var)
{
	ft_calcul_componentsb(var);
	if (var->components != 2)
		ft_msg_errorb("\033[91mInvalid Syntax txts !\033[91m", var);
	if (open(var->tmp_map[1], O_RDONLY) == -1)
		error_map_b("\033[91mWrong Path or Permessions of txts !\033[91m", var);
}

void	store_data_txtb(t_varb *var)
{
	if (var->status == 1)
	{
		var->txt->n_txt->id = mystrdupb("NO");
		var->txt->n_txt->path = mystrdupb(var->tmp_map[1]);
		var->txt->n_txt->only_one += 1;
	}
	if (var->status == 2)
	{
		var->txt->s_txt->id = mystrdupb("SO");
		var->txt->s_txt->path = mystrdupb(var->tmp_map[1]);
		var->txt->s_txt->only_one += 1;
	}
	if (var->status == 3)
	{
		var->txt->w_txt->id = mystrdupb("WE");
		var->txt->w_txt->path = mystrdupb(var->tmp_map[1]);
		var->txt->w_txt->only_one += 1;
	}
	if (var->status == 4)
	{
		var->txt->e_txt->id = mystrdupb("EA");
		var->txt->e_txt->path = mystrdupb(var->tmp_map[1]);
		var->txt->e_txt->only_one += 1;
	}
}

void	ft_calcul_componentsb(t_varb *var)
{
	int	i;

	i = 0;
	while (var->tmp_map[i])
		i++;
	var->components = i;
}

void	ft_which_idb(t_varb *var)
{
	if (ft_strcmp_bn(var->tmp_map[0], "NO") == 0)
		var->status = 1;
	if (ft_strcmp_bn(var->tmp_map[0], "SO") == 0)
		var->status = 2;
	if (ft_strcmp_bn(var->tmp_map[0], "WE") == 0)
		var->status = 3;
	if (ft_strcmp_bn(var->tmp_map[0], "EA") == 0)
		var->status = 4;
	if (ft_strcmp_bn(var->tmp_map[0], "F") == 0)
		var->status = 5;
	if (ft_strcmp_bn(var->tmp_map[0], "C") == 0)
		var->status = 6;
}
