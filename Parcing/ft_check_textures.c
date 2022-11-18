/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:25:35 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 10:01:04 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_txts(t_var *var)
{
	ft_calcul_components(var);
	if (var->components != 2)
		ft_msg_error("\033[91mInvalid Syntax txts !\033[91m", var);
	if (open(var->tmp_map[1], O_RDONLY) == -1)
		error_map("\033[91mWrong Path or Permessions of txts !\033[91m", var);
}

void	store_data_txt(t_var *var)
{
	if (var->status == 1)
	{
		var->txt->n_txt->id = mystrdup("NO");
		var->txt->n_txt->path = mystrdup(var->tmp_map[1]);
		var->txt->n_txt->only_one += 1;
	}
	if (var->status == 2)
	{
		var->txt->s_txt->id = mystrdup("SO");
		var->txt->s_txt->path = mystrdup(var->tmp_map[1]);
		var->txt->s_txt->only_one += 1;
	}
	if (var->status == 3)
	{
		var->txt->w_txt->id = mystrdup("WE");
		var->txt->w_txt->path = mystrdup(var->tmp_map[1]);
		var->txt->w_txt->only_one += 1;
	}
	if (var->status == 4)
	{
		var->txt->e_txt->id = mystrdup("EA");
		var->txt->e_txt->path = mystrdup(var->tmp_map[1]);
		var->txt->e_txt->only_one += 1;
	}
}

void	ft_calcul_components(t_var *var)
{
	int	i;

	i = 0;
	while (var->tmp_map[i])
		i++;
	var->components = i;
}

void	ft_which_id(t_var *var)
{
	if (ft_strcmp(var->tmp_map[0], "NO") == 0)
		var->status = 1;
	if (ft_strcmp(var->tmp_map[0], "SO") == 0)
		var->status = 2;
	if (ft_strcmp(var->tmp_map[0], "WE") == 0)
		var->status = 3;
	if (ft_strcmp(var->tmp_map[0], "EA") == 0)
		var->status = 4;
	if (ft_strcmp(var->tmp_map[0], "F") == 0)
		var->status = 5;
	if (ft_strcmp(var->tmp_map[0], "C") == 0)
		var->status = 6;
}
