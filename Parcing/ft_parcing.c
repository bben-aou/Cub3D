/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:38:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/12 13:20:51 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

    //   ------   The function of creating and checking the file descriptor   ------   //

void    ft_creatFd(t_var *var, char *str)
{
    var->fd = open(str,O_RDONLY);
    if ((var->fd) < 0)
        ft_messageError("\033[91mFile doesn't exist !\033[91m");
}

    //   ------   The function of initializing and allocation the data   ------   //
        
void    ft_allocation_var(t_var *var)
{
    var->texture = (t_texture *)malloc (sizeof(t_texture) * 4);
    var->texture->north_texture =(t_textureData *)malloc(sizeof(t_textureData ));
    var->texture->south_texture =(t_textureData *)malloc(sizeof(t_textureData ));
    var->texture->west_texture =(t_textureData *)malloc(sizeof(t_textureData ));
    var->texture->east_texture =(t_textureData *)malloc(sizeof(t_textureData ));
    var->player = (t_player *)malloc(sizeof(t_player));
    var->mlx = (t_mlx *)malloc(sizeof(t_mlx));
    var->floor = (t_floorData *)malloc(sizeof(t_floorData));
    var->floor->color = (int *)malloc(sizeof(int) * 3);
    var->ceilling = (t_ceillibData *)malloc(sizeof(t_ceillibData));
    var->ceilling->color = (int *)malloc(sizeof(int) * 3);
    var->keyPerssed = (t_keyPressed *)malloc(sizeof(t_keyPressed));
    var->ray = (t_raycasting *)malloc(sizeof(t_raycasting));
    var->view = (t_view *)malloc(sizeof(t_view));
    var->mlx->imgWall = (t_img *)malloc(sizeof(t_img));
    var->mlx->miniMap = (t_img *)malloc(sizeof(t_img));
    var->texture->north_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
    var->texture->south_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
    var->texture->east_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
    var->texture->west_texture->img = (t_img_txt *)(malloc(sizeof(t_img_txt)));
}

void    ft_init_textures_var(t_var *var)
{
    var->texture->north_texture->onlyOne = 0;
    var->texture->south_texture->onlyOne = 0;
    var->texture->west_texture->onlyOne = 0;
    var->texture->east_texture->onlyOne = 0;
    var->floor->onlyF = 0;
    var->ceilling->onlyC = 0;
}

void    ft_init_raycasting_var(t_var *var)
{
    //      Horizontal vars    //
    var->ray->xWallHit = 0;
    var->ray->yWallHit = 0;
    var->ray->horz_wall_found = 0;
    var->ray->horizontalWallHitX = 0;
    var->ray->horizontalWallHitY = 0;

    //      Vertical vars    //
    var->ray->vert_wall_hit_x = 0;
    var->ray->vert_wall_hit_y = 0;
    var->ray->vert_wall_found = 0;
    var->ray->distance = 0;
    var->ray->wasHitVertical = 0;
}

void    ft_init_facing_var(t_var *var)
{
    var->view->facing_down = 0;
    var->view->facing_up = 0;
    var->view->facing_right = 0;
    var->view->facing_left = 0;
}

void    ft_init_colors(t_var *var)
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

void    ft_init(t_var *var)
{
    ft_allocation_var(var);
    ft_init_textures_var(var);
    ft_init_raycasting_var(var);
    ft_init_facing_var(var);
    ft_init_colors(var);
    var->components = 0;
    var->status = 0;
    var->count_player = 0;
    var->miniMapHook = 0;
}

        //   ------   The function of giving int value to each ID   ------   //

void    ft_whichId(t_var *var)
{
    if (ft_strcmp(var->tmpMap[0], "NO") == 0)
        var->status = 1;
    if (ft_strcmp(var->tmpMap[0], "SO") == 0)
        var->status = 2;
    if (ft_strcmp(var->tmpMap[0], "WE") == 0)
        var->status = 3;
    if (ft_strcmp(var->tmpMap[0], "EA") == 0)
        var->status = 4;
    if (ft_strcmp(var->tmpMap[0], "F") == 0)
        var->status = 5;
    if (ft_strcmp(var->tmpMap[0], "C") == 0)
        var->status = 6;       
}

        //   ------   The function of storing the Textures data   ------   //

void    storeDataTexture(t_var *var)
{
    if (var->status == 1)
    {
        var->texture->north_texture->id = mystrdup("NO");
        var->texture->north_texture->path = mystrdup(var->tmpMap[1]);
        var->texture->north_texture->onlyOne += 1;
    }
    if (var->status == 2)
    {
        var->texture->south_texture->id = mystrdup("SO");
        var->texture->south_texture->path = mystrdup(var->tmpMap[1]);
        var->texture->south_texture->onlyOne += 1;
    }
    if (var->status == 3)
    {
        var->texture->west_texture->id = mystrdup("WE");
        var->texture->west_texture->path = mystrdup(var->tmpMap[1]);
        var->texture->west_texture->onlyOne += 1;
    }
    if (var->status == 4)
    {
        var->texture->east_texture->id = mystrdup("EA");
        var->texture->east_texture->path = mystrdup(var->tmpMap[1]);
        var->texture->east_texture->onlyOne += 1;
    }
}

      //   ------   The function of checking the RGB values   ------   //  

void    ft_validValue(int nbr)
{
    if (nbr < 0)
        ft_messageError("\033[91mNegative Value in RGB !\033[91m");
    if (nbr > 255)
        ft_messageError("\033[91mValue > 255 !\033[91m");   
}

        //   ------   The function of checking the RGB syntax   ------   //

void    ft_checkValidRgb(t_var *var)
{
    int i;

    i = 0;
    while (var->tmpRgb[i])
        i++;
    if (i != 3)
        error_mapB("\033[91mThe RGB Vaue should be in this form exp : 0, 255, 255 !\033[91m", var);
}

        //   ------   The function of parcing and storing the data of RGB     ------   //

void    ft_splitConvertRgb(t_var *var)
{
    int i;

    i = 0;
    var->tmpRgb = ft_split(var->tmpMap[1], ',');
    if (var->tmpRgb == NULL)
        ft_messageError("\033[91mInvalid RGB syntax !\033[91m");
    ft_checkValidRgb(var);
    if (var->status == 5)
    {
        while (i < 3)
        {
            var->floor->color[i] = ft_atoi(var->tmpRgb[i]);
            ft_validValue(var->floor->color[i]);
            i++;
        }
        var->floor->onlyF += 1;
    }
    i = 0;
    if (var->status == 6)
    {
        while (i < 3)
        {
            var->ceilling->color[i] = ft_atoi(var->tmpRgb[i]);
            ft_validValue(var->ceilling->color[i]);
            i++;
        }
        var->ceilling->onlyC += 1;
    }
}

        //   ------   The function of storing the data of Floor and Ceilling    ------   //

void    storeDataFloorCeilling(t_var *var)
{
    if (var->status == 5)
    {
        var->floor->id = 'F';
        ft_splitConvertRgb(var);    // Check and parce the RGB values of Floor
    }
    if (var->status == 6)
    {
        var->ceilling->id = 'C';
        ft_splitConvertRgb(var);    // Check and parce the RGB values of Ceilling
    }
}

        //   ------   The function of calculating the components    ------   //

void    ft_calculComponents(t_var *var)
{
    int i;

    i = 0;
    while (var->tmpMap[i])
        i++;
    var->components = i;
}

        //   ------   The function of checking the syntax of Textures    ------   //

void    ft_checkTextures(t_var *var)
{
    ft_calculComponents(var);
    if(var->components != 2 )
        ft_messageError("\033[91mInvalid Syntax textures !\033[91m");
    if (open(var->tmpMap[1], O_RDONLY) == -1)
        error_mapB("\033[91mWrong Path or Permessions of textures !\033[91m", var);
}

        //   ------   The function of checking the syntax of Floor and Ceillig    ------   //

void    ft_checkFloorCeilling(t_var *var)
{
    ft_calculComponents(var);
    if(var->components != 2)
        ft_messageError("\033[91mInvalid Syntax Floor or Ceilling !\033[91m");
}

        //   ------   The function of checking the double data (textures/Floor/Ceilling Ids)    ------   //

void    ft_checkDoubleId(t_var *var)
{
    if (var->texture->north_texture->onlyOne > 1)
        ft_messageError("\033[91mDouble Texture NO!\033[91m");
    if (var->texture->south_texture->onlyOne > 1)
        ft_messageError("\033[91mDouble Texture SO !\033[91m");
    if (var->texture->west_texture->onlyOne > 1)
        ft_messageError("\033[91mDouble Texture WE!\033[91m");
    if (var->texture->east_texture->onlyOne > 1)
        ft_messageError("\033[91mDouble Texture EA!\033[91m");
    if (var->floor->onlyF > 1)
        ft_messageError("\033[91mDouble Id F!\033[91m");
    if (var->ceilling->onlyC > 1)
        ft_messageError("\033[91mDouble Id C!\033[91m");
}

        //   ------   The main function of cheking errors and storing the data if it's valide    ------   //

void    ft_check_id(t_var *var)
{
    int     i;
    int     validId;   // to check if the identifier is valide 

    var->idTextures = ft_split("NO,SO,WE,EA", ',');
    i = 0;
    validId = 0;
    while (i < 4)
    {
        if (ft_strcmp(var->tmpMap[0], var->idTextures[i]) == 0)
        {
            ft_checkTextures(var);    //  check error of textures !!
            ft_whichId(var);         //   determinate the status : NO || SO || ....
            storeDataTexture(var);  //    if everthing is correct store the data 
            validId = 1;
            ft_checkDoubleId(var);
        }
        i++;
    }
    if (ft_strcmp(var->tmpMap[0], "F") == 0 || ft_strcmp(var->tmpMap[0], "C") == 0)
    {
        ft_checkFloorCeilling(var);     //  check error of textures !!
        ft_whichId(var);               //   determinate the status : F  || C || ....
        storeDataFloorCeilling(var);  //    if everthing is correct store the data  (needs to convert! !)
        validId = 1;
        ft_checkDoubleId(var);
    }
    if (var->tmpMap[0][0] == '1')
        ft_messageError("\033[91mSome informations missed from the file (4 Textures, Floor and Ceilling data should be exist) !\033[91m");
    if (validId == 0)
        ft_messageError("\033[91mInvalid ID !\033[91m");
}

        //   ------   The function of freeing 2D table     ------   //

void    ft_freeArray2d(char **arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

        //   ------   The function of reading one line each time     ------   //

void    ft_read(t_var *var)
{
    int i;

    i =0;
    var->tmp = get_next_line(var->fd);
    var->tmpMap = ft_multisplit(var->tmp, " \n");
    free(var->tmp);
    
}
        //   ------   The main function of reading , checking and storing the data     ------   //

void    ft_readAndCheck(t_var   *var)
{
    int i;

    i = 0;
    while ( i  < 6 )
    {
        ft_read(var);    
        while  (var->tmpMap[0] == NULL)
            ft_read(var);
        i++;
        ft_check_id(var);
    }
}
        //  -------  The fuction of initialize th keys   -------- //

void    initKeys(t_var *var)
{
    var->keyPerssed->keyW = 0;
    var->keyPerssed->keyS = 0;
    var->keyPerssed->keyD = 0;
    var->keyPerssed->keyA = 0;
    var->keyPerssed->keyTurnLeft = 0;
    var->keyPerssed->keyTurnRight = 0;
}               

        //   ------   The main function of parcing    ------   //

void    ft_parcing(t_var *var, char *str)
{
    ft_creatFd(var, str);
    if (!ft_check_extension(str))
        ft_messageError("\033[91mInvalid extension !\033[91m"); 
    ft_readAndCheck(var);
    
        //   ------    Part 2 : reading and parcing map    ------   //
    read_map(var);
}