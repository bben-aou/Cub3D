/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:33:03 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 11:52:25 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

void draw_cube_bonus(t_varb *var, int width, int height, char *color)
{
    int i;
    int j;

    i = height;
    while (i < (height + T_S))
    {
        j = width;
        while (j < (width + T_S))
        {
            if (ft_strcmp(color, "wall") == 0)
                my_img_pix_put_bonus(var, j * SCALE_MINI_MAP, i * SCALE_MINI_MAP, 0x466986);
            else if (ft_strcmp(color, "empty") == 0)
                my_img_pix_put_bonus(var, j * SCALE_MINI_MAP, i * SCALE_MINI_MAP, 0xc9d9cf);
            j++;
        }
        i++;
    }
}

void draw_player_bonus(t_varb *var)
{
    int i;
    int j;

    i = var->player->x;
    j = var->player->y;
    my_img_pix_put_bonus(var, i * SCALE_MINI_MAP, j * SCALE_MINI_MAP, 0xFF0000);
}

void draw_mini_mapB(t_varb *var)
{
    int y;
    int x;

    y = -1;
    while (++y < var->count_line)
    {
        x = -1;
        while (++x < ft_strlen1(var->map[y]))
        {
            if (var->map[y][x] == '1' || var->map[y][x] == ' ')
                draw_cube_bonus(var, (x * T_S), (y * T_S), "wall");
            else if (var->map[y][x] == '0')
                draw_cube_bonus(var, (x * T_S), (y * T_S), "empty");
            else if ((var->map[y][x] == 'N' || var->map[y][x] == 'S' || var->map[y][x] == 'E' || var->map[y][x] == 'W'))
            {
                draw_cube_bonus(var, (x * T_S), (y * T_S), "empty");
            }
            if (x == ft_strlen1(var->map[y]) - 1)
                while (++x < var->mlx->max_len)
                    draw_cube_bonus(var, (x * T_S), (y * T_S), "wall");
        }
    }
    drawLineBonus(var);
}

// void set_map_size_bonus(t_varb *var)
// {
//     int next;
//     int y;

//     y = 0;
//     var->mlx->max_len = ft_strlen1(var->map[0]);
//     while (++y < var->count_line)
//     {
//         next = ft_strlen1(var->map[y]);
//         if (var->mlx->max_len < next)
//             var->mlx->max_len = next;
//     }
//     var->mlx->width = var->mlx->max_len * T_S;
//     var->mlx->height = var->count_line * T_S;
// }

// int    reprint_map_(void *var)
// {
//     drawAll((t_var *)var);
//     keyPressedAction(var);

//     return (1);
// }

// void    ft_draw_map(t_var *var)
// {
//     var->mlx->init = mlx_init();
//     set_map_size(var);
//     var->mlx->win = mlx_new_window(var->mlx->init, var->mlx->width, var->mlx->height, "Window");
//     // var->mlx->img.img = mlx_new_image(var->mlx->init, var->mlx->width , var->mlx->height);
//     // var->mlx->img.addr = mlx_get_data_addr(var->mlx->img.img, &var->mlx->img.bpp, &var->mlx->img.line_len,
//     // 							&var->mlx->img.endian);
//     var->mlx->imgWall->img = mlx_new_image(var->mlx->init, var->mlx->width , var->mlx->height);
//     var->mlx->imgWall->addr = mlx_get_data_addr(var->mlx->imgWall->img, &var->mlx->imgWall->bpp, &var->mlx->imgWall->line_len,
//     							&var->mlx->imgWall->endian);

//     var->mlx->miniMap->img = mlx_new_image(var->mlx->init, var->mlx->width * 4, var->mlx->height * 4 );
//     var->mlx->miniMap->addr = mlx_get_data_addr(var->mlx->miniMap->img, &var->mlx->miniMap->bpp, &var->mlx->miniMap->line_len,
//     							&var->mlx->miniMap->endian);

//     setUpAll(var);
//     mlx_hook(var->mlx->win, 2,1L<<2, key_hook, var);
//     mlx_hook(var->mlx->win, 3, 1L<<0, key_release, var);
// 	mlx_hook(var->mlx->win, 17, 1L << 17, cross, var);
//     mlx_loop_hook(var->mlx->init, reprint_map, var);
//     mlx_loop(var->mlx->init);
// }