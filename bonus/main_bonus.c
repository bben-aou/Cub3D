/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:31:53 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 20:07:42 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

int	crossb(t_varb *var)
{
	(void)var;
	write(1, "Good Bye\n", 10);
	exit(1);
}

void	draw_all(t_varb *var)
{
	var->player->rotatin_angle += var->player->turn_left_right \
		* var->player->rotation_speed;
	mlx_clear_window(var->mlx, var->mlx->win);
	rendering_3db(var);
}

int	reprint_map(void *var)
{
	draw_all((t_varb *)var);
	key_pressed_actionb(var);
	return (1);
}

int	mouse_moves(int x, int y, t_varb *var)
{
	(void)y;
	if (x > 0 && x < var->mlx->width && y > 0 && y < var->mlx->height)
	{
		if (var->mouse.x_mouse - x > 0 && var->mouse.mouse_move)
		{
			var->player->rotatin_angle -= var->player->rotation_speed;
			var->mouse.x_mouse = x;
		}
		if (var->mouse.x_mouse - x < 0 && var->mouse.mouse_move)
		{
			var->player->rotatin_angle += var->player->rotation_speed;
			var->mouse.x_mouse = x;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_varb	var;

	if (argc != 2)
		ft_msg_errorb("Invalid arguments !", &var);
	ft_initb(&var);
	init_keysb(&var);
	ft_parcingb(&var, argv[1]);
	var.mlx->init = mlx_init();
	set_map_sizeb(&var);
	var.mlx->win = mlx_new_window(var.mlx->init, var.mlx->width, \
		var.mlx->height, "Cub3D_bonus");
	set_up_allb(&var);
	var.ceilling->c_color = create_rgbb(var.ceilling->color[0], \
		var.ceilling->color[1], var.ceilling->color[2]);
	var.floor->f_color = create_rgbb(var.floor->color[0], \
		var.floor->color[1], var.floor->color[2]);
	init_txtb_imgb(&var);
	mlx_hook(var.mlx->win, 2, 1L << 2, key_hookb, &var);
	mlx_hook(var.mlx->win, 3, 1L << 0, key_releaseb, &var);
	mlx_hook(var.mlx->win, 17, 1L << 17, crossb, &var);
	mlx_hook(var.mlx->win, 4, 0, mouse_hook, &var);
	mlx_hook(var.mlx->win, 5, 0, ft_mouse_release, &var);
	mlx_hook(var.mlx->win, 6, 0, mouse_moves, &var);
	mlx_loop_hook(var.mlx->init, reprint_map, &var);
	mlx_loop(var.mlx->init);
}
