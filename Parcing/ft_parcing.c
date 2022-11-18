/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:38:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 10:20:19 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_creat_fd(t_var *var, char *str)
{
	var->fd = open(str, O_RDONLY);
	if ((var->fd) < 0)
		ft_msg_error("\033[91mFile doesn't exist !\033[91m", var);
}

void	ft_check_id(t_var *var)
{
	int	i;
	int	valid_id;

	i = 0;
	valid_id = 0;
	while (i < 4)
	{
		if (ft_strcmp(var->tmp_map[0], var->id_textures[i]) == 0)
		{
			ft_check_txts(var);
			ft_which_id(var);
			store_data_txt(var);
			valid_id = 1;
			ft_check_double_id(var);
		}
		i++;
	}
	ft_check_floor_ceilling(var, &valid_id);
	if (var->tmp_map[0][0] == '1')
		ft_msg_error("Informations missed from the file !!", var);
	if (valid_id == 0)
		ft_msg_error("\033[91mInvalid ID !\033[91m", var);
}

void	ft_read(t_var *var)
{
	int	i;

	i = 0;
	var->tmp = get_next_line(var->fd);
	ft_free_array2d(var->tmp_map);
	if ((var->tmp[0] == 'F' || var->tmp[0] == 'C'))
	{
		if (count_comma(var->tmp) != 2)
			ft_msg_error("Wrong RGB format !", var);
	}
	var->tmp_map = ft_multisplit(var->tmp, " \n");
	free(var->tmp);
	var->tmp = NULL;
}

void	ft_read_and_check(t_var *var)
{
	int	i;

	i = 0;
	var->tmp_map = NULL;
	var->id_textures = ft_split("NO,SO,WE,EA", ',');
	while (i < 6)
	{
		ft_read(var);
		while (var->tmp_map[0] == NULL)
			ft_read(var);
		i++;
		ft_check_id(var);
	}
	ft_free_array2d(var->id_textures);
}

void	ft_parcing(t_var *var, char *str)
{
	ft_creat_fd(var, str);
	if (!ft_check_extension(str))
		ft_msg_error("\033[91mInvalid extension !\033[91m", var);
	ft_read_and_check(var);
	read_map(var);
}
