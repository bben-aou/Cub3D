/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:04:49 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:34:28 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_malloc_textures(t_var *var)
{
	var->txt->n_txt = (t_txt_data *)malloc(sizeof(t_txt_data));
	if (!var->txt->n_txt)
		ft_msg_error("Allocation Faild !", var);
	var->txt->s_txt = (t_txt_data *)malloc(sizeof(t_txt_data));
	if (!var->txt->s_txt)
		ft_msg_error("Allocation Faild !", var);
	var->txt->e_txt = (t_txt_data *)malloc(sizeof(t_txt_data));
	if (!var->txt->e_txt)
		ft_msg_error("Allocation Faild !", var);
	var->txt->w_txt = (t_txt_data *)malloc(sizeof(t_txt_data));
	if (!var->txt->w_txt)
		ft_msg_error("Allocation Faild !", var);
}

void	ft_malloc_f_c(t_var *var)
{
	var->floor = (t_floorData *)malloc(sizeof(t_floorData));
	if (!var->floor)
		ft_msg_error("Allocation Faild !", var);
	var->floor->color = (int *)malloc(sizeof(int) * 3);
	if (!var->floor->color)
		ft_msg_error("Allocation Faild !", var);
	var->ceilling = (t_ceillibData *)malloc(sizeof(t_ceillibData));
	if (!var->ceilling)
		ft_msg_error("Allocation Faild !", var);
	var->ceilling->color = (int *)malloc(sizeof(int) * 3);
	if (!var->ceilling->color)
		ft_msg_error("Allocation Faild !", var);
}

void	ft_malloc_img(t_var *var)
{
	var->txt->n_txt->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
	if (!var->txt->n_txt->img)
		ft_msg_error("Allocation Faild !", var);
	var->txt->s_txt->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
	if (!var->txt->s_txt->img)
		ft_msg_error("Allocation Faild !", var);
	var->txt->e_txt->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
	if (!var->txt->e_txt->img)
		ft_msg_error("Allocation Faild !", var);
	var->txt->w_txt->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
	if (!var->txt->w_txt->img)
		ft_msg_error("Allocation Faild !", var);
}

void	ft_malloc_struct(t_var *var)
{
	var->txt = (t_txt *)malloc(sizeof(t_txt) * 4);
	if (!var->txt)
		ft_msg_error("Allocation Faild !", var);
	var->player = (t_player *)malloc(sizeof(t_player));
	if (!var->player)
		ft_msg_error("Allocation Faild !", var);
	var->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!var->mlx)
		ft_msg_error("Allocation Faild !", var);
	var->key_pressed = (t_key_pressed *)malloc(sizeof(t_key_pressed));
	if (!var->key_pressed)
		ft_msg_error("Allocation Faild !", var);
	var->ray = (t_raycasting *)malloc(sizeof(t_raycasting));
	if (!var->ray)
		ft_msg_error("Allocation Faild !", var);
	var->view = (t_view *)malloc(sizeof(t_view));
	if (!var->view)
		ft_msg_error("Allocation Faild !", var);
	var->mlx->full_img = (t_img *)malloc(sizeof(t_img));
	if (!var->mlx->full_img)
		ft_msg_error("Allocation Faild !", var);
}

void	ft_allocation_var(t_var *var)
{
	ft_malloc_struct(var);
	ft_malloc_textures(var);
	ft_malloc_f_c(var);
	ft_malloc_img(var);
}
