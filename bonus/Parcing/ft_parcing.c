/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:38:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:29:24 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_creat_fdb(t_varb *var, char *str)
{
	var->fd = open(str, O_RDONLY);
	if ((var->fd) < 0)
		ft_msg_errorb("\033[91mFile doesn't exist !\033[91m", var);
}

void	ft_check_idb(t_varb *var)
{
	int	i;
	int	valid_id;

	i = 0;
	valid_id = 0;
	while (i < 4)
	{
		if (ft_strcmp_bn(var->tmp_map[0], var->id_textures[i]) == 0)
		{
			ft_check_txtsb(var);
			ft_which_idb(var);
			store_data_txtb(var);
			valid_id = 1;
			ft_check_double_idb(var);
		}
		i++;
	}
	ft_check_floor_ceilblingb(var, &valid_id);
	if (var->tmp_map[0][0] == '1')
		ft_msg_errorb("Informations missed from the file !!", var);
	if (valid_id == 0)
		ft_msg_errorb("\033[91mInvalid ID !\033[91m", var);
}

void	ft_readb(t_varb *var)
{
	int	i;

	i = 0;
	var->tmp = get_next_line1(var->fd);
	ft_freeb_array2db(var->tmp_map);
	if ((var->tmp[0] == 'F' || var->tmp[0] == 'C'))
	{
		if (count_commab(var->tmp) != 2)
			ft_msg_errorb("Wrong RGB format !", var);
	}
	var->tmp_map = ft_multisplitb(var->tmp, " \n");
	free(var->tmp);
	var->tmp = NULL;
}

void	ft_readb_and_checkb(t_varb *var)
{
	int	i;

	i = 0;
	var->tmp_map = NULL;
	var->id_textures = ft_split_bonus("NO,SO,WE,EA", ',');
	while (i < 6)
	{
		ft_readb(var);
		while (var->tmp_map[0] == NULL)
			ft_readb(var);
		i++;
		ft_check_idb(var);
	}
	ft_freeb_array2db(var->id_textures);
}

void	ft_parcingb(t_varb *var, char *str)
{
	ft_creat_fdb(var, str);
	if (!ft_check_extensionb(str))
		ft_msg_errorb("\033[91mInvalid extension !\033[91m", var);
	ft_readb_and_checkb(var);
	read_mapb(var);
}
