/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:04:49 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 17:33:50 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_malloc_texturesb(t_varb *var)
{
	var->txt->n_txt = (t_txtb_datab *)malloc(sizeof(t_txtb_datab));
	if (!var->txt->n_txt)
		ft_msg_errorb("Allocation Faild !", var);
	var->txt->s_txt = (t_txtb_datab *)malloc(sizeof(t_txtb_datab));
	if (!var->txt->s_txt)
		ft_msg_errorb("Allocation Faild !", var);
	var->txt->e_txt = (t_txtb_datab *)malloc(sizeof(t_txtb_datab));
	if (!var->txt->e_txt)
		ft_msg_errorb("Allocation Faild !", var);
	var->txt->w_txt = (t_txtb_datab *)malloc(sizeof(t_txtb_datab));
	if (!var->txt->w_txt)
		ft_msg_errorb("Allocation Faild !", var);
}

void	ft_malloc_f_cb(t_varb *var)
{
	var->floor = (t_floor_datab *)malloc(sizeof(t_floor_datab));
	if (!var->floor)
		ft_msg_errorb("Allocation Faild !", var);
	var->floor->color = (int *)malloc(sizeof(int) * 3);
	if (!var->floor->color)
		ft_msg_errorb("Allocation Faild !", var);
	var->ceilling = (t_ceillib_datab *)malloc(sizeof(t_ceillib_datab));
	if (!var->ceilling)
		ft_msg_errorb("Allocation Faild !", var);
	var->ceilling->color = (int *)malloc(sizeof(int) * 3);
	if (!var->ceilling->color)
		ft_msg_errorb("Allocation Faild !", var);
}

void	ft_malloc_imgb(t_varb *var)
{
	var->txt->n_txt->img = (t_imgb_txtb *)(malloc(sizeof(t_imgb_txtb)));
	if (!var->txt->n_txt->img)
		ft_msg_errorb("Allocation Faild !", var);
	var->txt->s_txt->img = (t_imgb_txtb *)(malloc(sizeof(t_imgb_txtb)));
	if (!var->txt->s_txt->img)
		ft_msg_errorb("Allocation Faild !", var);
	var->txt->e_txt->img = (t_imgb_txtb *)(malloc(sizeof(t_imgb_txtb)));
	if (!var->txt->e_txt->img)
		ft_msg_errorb("Allocation Faild !", var);
	var->txt->w_txt->img = (t_imgb_txtb *)(malloc(sizeof(t_imgb_txtb)));
	if (!var->txt->w_txt->img)
		ft_msg_errorb("Allocation Faild !", var);
}

void	ft_malloc_structb(t_varb *var)
{
	var->txt = (t_txtb *)malloc(sizeof(t_txtb) * 4);
	if (!var->txt)
		ft_msg_errorb("Allocation Faild !", var);
	var->player = (t_playerb *)malloc(sizeof(t_playerb));
	if (!var->player)
		ft_msg_errorb("Allocation Faild !", var);
	var->mlx = (t_mlxb *)malloc(sizeof(t_mlxb));
	if (!var->mlx)
		ft_msg_errorb("Allocation Faild !", var);
	var->key_pressed = (t_key_pressedb *)malloc(sizeof(t_key_pressedb));
	if (!var->key_pressed)
		ft_msg_errorb("Allocation Faild !", var);
	var->ray = (t_raycastingb *)malloc(sizeof(t_raycastingb));
	if (!var->ray)
		ft_msg_errorb("Allocation Faild !", var);
	var->view = (t_viewb *)malloc(sizeof(t_viewb));
	if (!var->view)
		ft_msg_errorb("Allocation Faild !", var);
	var->mlx->full_img = (t_imgb *)malloc(sizeof(t_imgb));
	if (!var->mlx->full_img)
		ft_msg_errorb("Allocation Faild !", var);
}

void	ft_allocation_varb(t_varb *var)
{
	ft_malloc_structb(var);
	ft_malloc_texturesb(var);
	ft_malloc_f_cb(var);
	ft_malloc_imgb(var);
}
