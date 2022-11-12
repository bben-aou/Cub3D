/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:31:53 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/12 11:03:04 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//     ----------------------- Function of closing the windows by clicking the X ---------------------------- //

int	cross(t_var *var)
{
    
	write(1, "Bye\n",4);
    var->unsedAvoid = 1; // need to free here;
    exit(1);
}



//     ----------------------- Function of drawing All the element of map frame by frame : ---------------------------- //

void    drawAll(t_var *var)
{

    var->player->rotationAngle += var->player->turnLeftRight * var->player->rotationSpeed;
    mlx_clear_window(var->mlx,var->mlx->win);
    rendering3D(var);
}




int    reprint_map(void *var)
{
    drawAll((t_var *)var);
    keyPressedAction(var);

    return (1);
}




int main(int argc, char **argv)
{
    t_var   var;

    if (argc != 2)
        ft_messageError("Invalid arguments !");
    ft_init(&var);
    initKeys(&var);
    ft_parcing(&var, argv[1]);
    var.mlx->init = mlx_init();
    set_map_size(&var);
    var.mlx->win = mlx_new_window(var.mlx->init, var.mlx->width, var.mlx->height, "Cub3D");
    var.mlx->imgWall->img = mlx_new_image(var.mlx->init, var.mlx->width , var.mlx->height);
    var.mlx->imgWall->addr = mlx_get_data_addr(var.mlx->imgWall->img, &var.mlx->imgWall->bpp, &var.mlx->imgWall->line_len,
    							&var.mlx->imgWall->endian);
    setUpAll(&var);
    convert_floor_colors(&var);
    convert_ceilling_colors(&var);
    mlx_hook(var.mlx->win, 2,1L<<2, key_hook, &var);
    mlx_hook(var.mlx->win, 3, 1L<<0, key_release, &var);
	mlx_hook(var.mlx->win, 17, 1L << 17, cross, &var);
    mlx_loop_hook(var.mlx->init, reprint_map, &var);
    mlx_loop(var.mlx->init);
    
}   