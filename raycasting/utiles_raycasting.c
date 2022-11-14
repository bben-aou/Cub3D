/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:51:25 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 11:11:34 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool check_if_wall(t_var *var, int next_x, int next_y)
{
    int y;
    int x;

    x = (int)floor(next_x / TILE_SIZE);
    y = (int)floor(next_y / TILE_SIZE);
    if (y >= var->count_line)
        return (0);
    if (var->map[y] && x >= ft_strlen1(var->map[y]))
        return 0;
    if (var->map[y][x] != '1')
        return (0);
    return (1);
}

void my_img_pix_put2(t_var *var, int x, int y, int color)
{
    char *pixel;

    pixel = var->mlx->full_img->addr + (y * var->mlx->full_img->line_len + x * (var->mlx->full_img->bpp / 8));
    *(unsigned int *)pixel = color;
}

void init_rest_of_textures(t_var *var)
{

    var->e_texture = mlx_xpm_file_to_image(var->mlx->init, var->texture->east_texture->path,
        &var->texture->east_texture->width_txt, &var->texture->east_texture->height_txt);
    if (!var->e_texture)
        error_map("Occured during convert Third texture to img", var);

    var->texture->east_texture->img->addr = (int *)mlx_get_data_addr(var->e_texture,
        &var->texture->east_texture->img->bpp, &var->texture->east_texture->img->line_len,
        &var->texture->east_texture->img->endian);

    var->w_texture = mlx_xpm_file_to_image(var->mlx->init, var->texture->west_texture->path,
        &var->texture->west_texture->width_txt, &var->texture->west_texture->height_txt);
    if (!var->w_texture)
        error_map("Occured during convert Fourth texture to img", var);
    var->texture->west_texture->img->addr = (int *)mlx_get_data_addr(var->w_texture,
        &var->texture->west_texture->img->bpp, &var->texture->west_texture->img->line_len,
        &var->texture->west_texture->img->endian);
}

void init_texture_img(t_var *var)
{
    var->n_texture = mlx_xpm_file_to_image(var->mlx->init, var->texture->north_texture->path,
        &var->texture->north_texture->width_txt, &var->texture->north_texture->height_txt);
    if (!var->n_texture)
        error_map("Occured during convert first texture to img", var);

    var->texture->north_texture->img->addr = (int *)mlx_get_data_addr(var->n_texture,
        &var->texture->north_texture->img->bpp, &var->texture->north_texture->img->line_len,
        &var->texture->north_texture->img->endian);

    var->s_texture = mlx_xpm_file_to_image(var->mlx->init, var->texture->south_texture->path,
        &var->texture->south_texture->width_txt, &var->texture->south_texture->height_txt);
    if (!var->s_texture)
        error_map("Occured during convert second texture to img", var);

    var->texture->south_texture->img->addr = (int *)mlx_get_data_addr(var->s_texture,
        &var->texture->south_texture->img->bpp, &var->texture->south_texture->img->line_len,
        &var->texture->south_texture->img->endian);
    init_rest_of_textures(var);
}