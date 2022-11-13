/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:38:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/13 14:17:39 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//   ------   The function of creating and checking the file descriptor   ------   //

void ft_creat_fd(t_var *var, char *str)
{
    var->fd = open(str, O_RDONLY);
    if ((var->fd) < 0)
        ft_msg_error("\033[91mFile doesn't exist !\033[91m");
}

//   ------   The function of initializing and allocation the data   ------   //

void ft_allocation_var(t_var *var)
{
    var->texture = (t_texture *)malloc(sizeof(t_texture) * 4);
    var->texture->north_texture = (t_textureData *)malloc(sizeof(t_textureData));
    var->texture->south_texture = (t_textureData *)malloc(sizeof(t_textureData));
    var->texture->west_texture = (t_textureData *)malloc(sizeof(t_textureData));
    var->texture->east_texture = (t_textureData *)malloc(sizeof(t_textureData));
    var->player = (t_player *)malloc(sizeof(t_player));
    var->mlx = (t_mlx *)malloc(sizeof(t_mlx));
    var->floor = (t_floorData *)malloc(sizeof(t_floorData));
    var->floor->color = (int *)malloc(sizeof(int) * 3);
    var->ceilling = (t_ceillibData *)malloc(sizeof(t_ceillibData));
    var->ceilling->color = (int *)malloc(sizeof(int) * 3);
    var->keyPerssed = (t_keyPressed *)malloc(sizeof(t_keyPressed));
    var->ray = (t_raycasting *)malloc(sizeof(t_raycasting));
    var->view = (t_view *)malloc(sizeof(t_view));
    var->mlx->full_img = (t_img *)malloc(sizeof(t_img));
    var->mlx->mini_map = (t_img *)malloc(sizeof(t_img));
    var->texture->north_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
    var->texture->south_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
    var->texture->east_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
    var->texture->west_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
}

void ft_init_textures_var(t_var *var)
{
    var->texture->north_texture->only_one = 0;
    var->texture->south_texture->only_one = 0;
    var->texture->west_texture->only_one = 0;
    var->texture->east_texture->only_one = 0;
    var->floor->only_f = 0;
    var->ceilling->only_c = 0;
}

void ft_init_raycasting_var(t_var *var)
{
    //      Horizontal vars    //
    var->ray->x_wall_hit = 0;
    var->ray->y_wall_hit = 0;
    var->ray->horz_wall_found = 0;
    var->ray->horz_wall_hit_x = 0;
    var->ray->horz_wall_hit_y = 0;

    //      Vertical vars    //
    var->ray->vert_wall_hit_x = 0;
    var->ray->vert_wall_hit_y = 0;
    var->ray->vert_wall_found = 0;
    var->ray->distance = 0;
    var->ray->was_hit_vert = 0;
}

void ft_init_facing_var(t_var *var)
{
    var->view->facing_down = 0;
    var->view->facing_up = 0;
    var->view->facing_right = 0;
    var->view->facing_left = 0;
}

void ft_init_colors(t_var *var)
{
    var->clrf->i = 0;
    var->clrf->i = 0;
    var->clrf = (t_colors *)malloc(sizeof(t_colors));
    var->clrc = (t_colors *)malloc(sizeof(t_colors));
    var->clrf->r_hex = (char *)malloc(sizeof(char) * 3);
    var->clrf->g_hex = (char *)malloc(sizeof(char) * 3);
    var->clrf->b_hex = (char *)malloc(sizeof(char) * 3);
    var->clrc->r_hex = (char *)malloc(sizeof(char) * 3);
    var->clrc->g_hex = (char *)malloc(sizeof(char) * 3);
    var->clrc->b_hex = (char *)malloc(sizeof(char) * 3);
}

void ft_init(t_var *var)
{
    ft_allocation_var(var);
    ft_init_textures_var(var);
    ft_init_raycasting_var(var);
    ft_init_facing_var(var);
    ft_init_colors(var);
    var->components = 0;
    var->status = 0;
    var->count_player = 0;
    var->mini_mapHook = 0;
}

//   ------   The function of giving int value to each ID   ------   //

void ft_which_id(t_var *var)
{
    if (ft_strcmp(var->tmp_map[0], "NO") == 0)
        var->status = 1;
    if (ft_strcmp(var->tmp_map[0], "SO") == 0)
        var->status = 2;
    if (ft_strcmp(var->tmp_map[0], "WE") == 0)
        var->status = 3;
    if (ft_strcmp(var->tmp_map[0], "EA") == 0)
        var->status = 4;
    if (ft_strcmp(var->tmp_map[0], "F") == 0)
        var->status = 5;
    if (ft_strcmp(var->tmp_map[0], "C") == 0)
        var->status = 6;
}

//   ------   The function of storing the Textures data   ------   //

void store_data_texture(t_var *var)
{
    if (var->status == 1)
    {
        var->texture->north_texture->id = mystrdup("NO");
        var->texture->north_texture->path = mystrdup(var->tmp_map[1]);
        var->texture->north_texture->only_one += 1;
    }
    if (var->status == 2)
    {
        var->texture->south_texture->id = mystrdup("SO");
        var->texture->south_texture->path = mystrdup(var->tmp_map[1]);
        var->texture->south_texture->only_one += 1;
    }
    if (var->status == 3)
    {
        var->texture->west_texture->id = mystrdup("WE");
        var->texture->west_texture->path = mystrdup(var->tmp_map[1]);
        var->texture->west_texture->only_one += 1;
    }
    if (var->status == 4)
    {
        var->texture->east_texture->id = mystrdup("EA");
        var->texture->east_texture->path = mystrdup(var->tmp_map[1]);
        var->texture->east_texture->only_one += 1;
    }
}

//   ------   The function of checking the RGB values   ------   //

void ft_valid_value(int nbr)
{
    if (nbr < 0)
        ft_msg_error("\033[91mNegative Value in RGB !\033[91m");
    if (nbr > 255)
        ft_msg_error("\033[91mValue > 255 !\033[91m");
}

//   ------   The function of checking the RGB syntax   ------   //

void ft_check_valid_rgb(t_var *var)
{
    int i;

    i = 0;
    while (var->tmp_rgb[i])
        i++;
    if (i != 3)
        error_map("\033[91mThe RGB Vaue should be in this form exp : 0, 255, 255 !\033[91m", var);
}

//   ------   The function of parcing and storing the data of RGB     ------   //

void ft_split_convert_rgb(t_var *var)
{
    int i;

    i = 0;
    var->tmp_rgb = ft_split(var->tmp_map[1], ',');
    if (var->tmp_rgb == NULL)
        ft_msg_error("\033[91mInvalid RGB syntax !\033[91m");
    ft_check_valid_rgb(var);
    if (var->status == 5)
    {
        while (i < 3)
        {
            var->floor->color[i] = ft_atoi(var->tmp_rgb[i]);
            ft_valid_value(var->floor->color[i]);
            i++;
        }
        var->floor->only_f += 1;
    }
    i = 0;
    if (var->status == 6)
    {
        while (i < 3)
        {
            var->ceilling->color[i] = ft_atoi(var->tmp_rgb[i]);
            ft_valid_value(var->ceilling->color[i]);
            i++;
        }
        var->ceilling->only_c += 1;
    }
}

//   ------   The function of storing the data of Floor and Ceilling    ------   //

void store_data_floor_ceil(t_var *var)
{
    if (var->status == 5)
    {
        var->floor->id = 'F';
        ft_split_convert_rgb(var); // Check and parce the RGB values of Floor
    }
    if (var->status == 6)
    {
        var->ceilling->id = 'C';
        ft_split_convert_rgb(var); // Check and parce the RGB values of Ceilling
    }
}

//   ------   The function of calculating the components    ------   //

void ft_calcul_components(t_var *var)
{
    int i;

    i = 0;
    while (var->tmp_map[i])
        i++;
    var->components = i;
}

//   ------   The function of checking the syntax of Textures    ------   //

void ft_check_textures(t_var *var)
{
    ft_calcul_components(var);
    if (var->components != 2)
        ft_msg_error("\033[91mInvalid Syntax textures !\033[91m");
    if (open(var->tmp_map[1], O_RDONLY) == -1)
        error_map("\033[91mWrong Path or Permessions of textures !\033[91m", var);
}

//   ------   The function of checking the syntax of Floor and Ceillig    ------   //

void ft_check_floor_ceil(t_var *var)
{
    ft_calcul_components(var);
    if (var->components != 2)
        ft_msg_error("\033[91mInvalid Syntax Floor or Ceilling !\033[91m");
}

//   ------   The function of checking the double data (textures/Floor/Ceilling Ids)    ------   //

void ft_check_double_id(t_var *var)
{
    if (var->texture->north_texture->only_one > 1)
        ft_msg_error("\033[91mDouble Texture NO!\033[91m");
    if (var->texture->south_texture->only_one > 1)
        ft_msg_error("\033[91mDouble Texture SO !\033[91m");
    if (var->texture->west_texture->only_one > 1)
        ft_msg_error("\033[91mDouble Texture WE!\033[91m");
    if (var->texture->east_texture->only_one > 1)
        ft_msg_error("\033[91mDouble Texture EA!\033[91m");
    if (var->floor->only_f > 1)
        ft_msg_error("\033[91mDouble Id F!\033[91m");
    if (var->ceilling->only_c > 1)
        ft_msg_error("\033[91mDouble Id C!\033[91m");
}

//   ------   The main function of cheking errors and storing the data if it's valide    ------   //

void ft_check_id(t_var *var)
{
    int i;
    int validId; // to check if the identifier is valide

    var->id_textures = ft_split("NO,SO,WE,EA", ',');
    i = 0;
    validId = 0;
    while (i < 4)
    {
        if (ft_strcmp(var->tmp_map[0], var->id_textures[i]) == 0)
        {
            ft_check_textures(var);  //  check error of textures !!
            ft_which_id(var);        //   determinate the status : NO || SO || ....
            store_data_texture(var); //    if everthing is correct store the data
            validId = 1;
            ft_check_double_id(var);
        }
        i++;
    }
    if (ft_strcmp(var->tmp_map[0], "F") == 0 || ft_strcmp(var->tmp_map[0], "C") == 0)
    {
        ft_check_floor_ceil(var);   //  check error of textures !!
        ft_which_id(var);           //   determinate the status : F  || C || ....
        store_data_floor_ceil(var); //    if everthing is correct store the data  (needs to convert! !)
        validId = 1;
        ft_check_double_id(var);
    }
    if (var->tmp_map[0][0] == '1')
        ft_msg_error("\033[91mSome informations missed from the file (4 Textures, Floor and Ceilling data should be exist) !\033[91m");
    if (validId == 0)
        ft_msg_error("\033[91mInvalid ID !\033[91m");
}

//   ------   The function of freeing 2D table     ------   //

void ft_free_array_2d(char **arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

//   ------   The function of reading one line each time     ------   //

void ft_read(t_var *var)
{
    int i;

    i = 0;
    var->tmp = get_next_line(var->fd);
    var->tmp_map = ft_multisplit(var->tmp, " \n");
    free(var->tmp);
}
//   ------   The main function of reading , checking and storing the data     ------   //

void ft_read_and_check(t_var *var)
{
    int i;

    i = 0;
    while (i < 6)
    {
        ft_read(var);
        while (var->tmp_map[0] == NULL)
            ft_read(var);
        i++;
        ft_check_id(var);
    }
}
//  -------  The fuction of initialize th key_s   -------- //

void init_keys(t_var *var)
{
    var->keyPerssed->key_w = 0;
    var->keyPerssed->key_s = 0;
    var->keyPerssed->key_d = 0;
    var->keyPerssed->key_a = 0;
    var->keyPerssed->key_turn_left = 0;
    var->keyPerssed->key_turn_right = 0;
}

//   ------   The main function of parcing    ------   //

void ft_parcing(t_var *var, char *str)
{
    ft_creat_fd(var, str);
    if (!ft_check_extension(str))
        ft_msg_error("\033[91mInvalid extension !\033[91m");
    ft_read_and_check(var);

    //   ------    Part 2 : reading and parcing map    ------   //
    read_map(var);
}