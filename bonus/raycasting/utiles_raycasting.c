/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:51:25 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/15 17:39:57 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

bool	check_if_wallb(t_varb *var, int next_x, int next_y)
{
	int	y;
	int	x;

	x = (int)floor(next_x / T_S);
	y = (int)floor(next_y / T_S);
	if (y >= var->count_line)
		return (0);
	if (var->map[y] && x >= ft_strlenb(var->map[y]))
		return (0);
	if (var->map[y][x] != '1')
		return (0);
	return (1);
}

void	my_img_pix_putb(t_varb *var, int x, int y, int color)
{
	char	*pixel;

	pixel = var->mlx->full_img->addr + (y * var->mlx->full_img->line_len + \
		x * (var->mlx->full_img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	init_rest_of_txtsb(t_varb *var)
{
	var->e_txt = mlx_xpm_file_to_image(var->mlx->init, \
		var->txt->e_txt->path, &var->txt->e_txt->width_txt, \
			&var->txt->e_txt->height_txtb);
	if (!var->e_txt)
		error_map_b("Occured during convert Third txt to img", var);
	var->txt->e_txt->img->addr = (int *)mlx_get_data_addr(\
		var->e_txt, &var->txt->e_txt->img->bpp, \
		&var->txt->e_txt->img->line_len, &var->txt->e_txt->img->endian);
	var->w_txt = mlx_xpm_file_to_image(var->mlx->init, \
		var->txt->w_txt->path, &var->txt->w_txt->width_txt, \
			&var->txt->w_txt->height_txtb);
	if (!var->w_txt)
		error_map_b("Occured during convert Fourth txt to img", var);
	var->txt->w_txt->img->addr = (int *)mlx_get_data_addr(var->w_txt, \
		&var->txt->w_txt->img->bpp, &var->txt->w_txt->img->line_len, \
			&var->txt->w_txt->img->endian);
}

void	init_txtb_imgb(t_varb *var)
{
	var->n_txt = mlx_xpm_file_to_image(var->mlx->init, var->txt->n_txt->path, \
		&var->txt->n_txt->width_txt, &var->txt->n_txt->height_txtb);
	if (!var->n_txt)
		error_map_b("Occured during convert first txt to img", var);
	var->txt->n_txt->img->addr = (int *)mlx_get_data_addr(var->n_txt, \
		&var->txt->n_txt->img->bpp, &var->txt->n_txt->img->line_len, \
			&var->txt->n_txt->img->endian);
	var->s_txt = mlx_xpm_file_to_image(var->mlx->init, var->txt->s_txt->path, \
		&var->txt->s_txt->width_txt, &var->txt->s_txt->height_txtb);
	if (!var->s_txt)
		error_map_b("Occured during convert second txt to img", var);
	var->txt->s_txt->img->addr = (int *)mlx_get_data_addr(var->s_txt, \
		&var->txt->s_txt->img->bpp, &var->txt->s_txt->img->line_len, \
			&var->txt->s_txt->img->endian);
	init_rest_of_txtsb(var);
}
