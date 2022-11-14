/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:48:35 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 10:01:57 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

int cross_bonus(t_varb *var)
{
    write(1, "Bye\n", 4);
    var->unsedAvoid = 1; // need to free here;
    exit(1);
}

//     ----------------------- Function of drawing All the element of map frame by frame : ---------------------------- //

void draw_all_bonus(t_varb *var)
{
    var->player->rotationAngle += var->player->turnLeftRight * var->player->rotationSpeed;
    mlx_clear_window(var->mlx, var->mlx->win);
    rendering_3d_bonus(var);
}

int reprint_map_bonus(void *var)
{
    draw_all_bonus((t_varb *)var);
    keyPressedAction_bonus(var);

    return (1);
}

int main(int argc, char **argv)
{
    t_varb var;

    if (argc != 2)
        ft_messageErrorB("Invalid arguments !");
    ft_init_bonus(&var);
    initKeys_bonus(&var);
    ft_parcing_bonus(&var, argv[1]);
    var.mlx->init = mlx_init();
    set_map_size_bonus(&var);
    var.mlx->win = mlx_new_window(var.mlx->init, var.mlx->width, var.mlx->height, "Cub3D");
    var.mlx->imgWall->img = mlx_new_image(var.mlx->init, var.mlx->width, var.mlx->height);
    var.mlx->imgWall->addr = mlx_get_data_addr(var.mlx->imgWall->img, &var.mlx->imgWall->bpp, &var.mlx->imgWall->line_len,
                                               &var.mlx->imgWall->endian);

    set_up_all_bonus(&var);
    mlx_hook(var.mlx->win, 2, 1L << 2, key_hook_bonus, &var);
    mlx_hook(var.mlx->win, 3, 1L << 0, key_release_bonus, &var);
    mlx_hook(var.mlx->win, 17, 1L << 17, cross_bonus, &var);
    mlx_loop_hook(var.mlx->init, reprint_map_bonus, &var);
    mlx_loop(var.mlx->init);
}