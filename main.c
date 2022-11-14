/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:31:53 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 12:36:28 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cross(t_var *var)
{
    (void)var;
    write(1, "Bye\n", 4);
    var->unsed_avoid = 1; // need to free here;
    exit(1);
}

void draw_all(t_var *var)
{

    var->player->rotatin_angle += var->player->turn_left_right * var->player->rotation_speed;
    mlx_clear_window(var->mlx, var->mlx->win);
    rendering_3d(var);
}

int reprint_map(void *var)
{
    draw_all((t_var *)var);
    key_pressed_action(var);

    return (1);
}

int main(int argc, char **argv)
{
    t_var var;

    if (argc != 2)
        ft_msg_error("Invalid arguments !");
    ft_init(&var);
    init_keys(&var);
    ft_parcing(&var, argv[1]);
    var.mlx->init = mlx_init();
    set_map_size(&var);
    var.mlx->win = mlx_new_window(var.mlx->init, var.mlx->width, var.mlx->height, "Cub3D");
    set_up_all(&var);
    convert_floor_colors(&var);
    convert_ceilling_colors(&var);
    init_txt_img(&var);
    mlx_hook(var.mlx->win, 2, 1L << 2, key_hook, &var);
    mlx_hook(var.mlx->win, 3, 1L << 0, key_release, &var);
    mlx_hook(var.mlx->win, 17, 1L << 17, cross, &var);
    mlx_loop_hook(var.mlx->init, reprint_map, &var);
    mlx_loop(var.mlx->init);
}