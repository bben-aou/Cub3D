/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:38:47 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 12:36:28 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

//   ------   The function of creating and checking the file descriptor   ------   //

void ft_creatFd_bonus(t_varb *var, char *str)
{
    var->fd = open(str, O_RDONLY);
    if ((var->fd) < 0)
        ft_messageErrorB("\033[91mFile doesn't exist !\033[91m");
}

//   ------   The function of initializing and allocation the data   ------   //

void ft_allocation_varB(t_varb *var)
{
    var->txt = (t_txtb *)malloc(sizeof(t_txtb) * 4);
    var->txt->n_txt = (t_txtDatab *)malloc(sizeof(t_txtDatab));
    var->txt->s_txt = (t_txtDatab *)malloc(sizeof(t_txtDatab));
    var->txt->w_txt = (t_txtDatab *)malloc(sizeof(t_txtDatab));
    var->txt->e_txt = (t_txtDatab *)malloc(sizeof(t_txtDatab));
    var->player = (t_playerb *)malloc(sizeof(t_playerb));
    var->mlx = (t_mlxb *)malloc(sizeof(t_mlxb));
    var->floor = (t_floorDatab *)malloc(sizeof(t_floorDatab));
    var->floor->color = (int *)malloc(sizeof(int) * 3);
    var->ceilling = (t_ceillibDatab *)malloc(sizeof(t_ceillibDatab));
    var->ceilling->color = (int *)malloc(sizeof(int) * 3);
    var->keyPerssed = (t_keyPressedb *)malloc(sizeof(t_keyPressedb));
    var->ray = (t_raycastingb *)malloc(sizeof(t_raycastingb));
    var->view = (t_viewb *)malloc(sizeof(t_viewb));
    var->mlx->imgWall = (t_imgb *)malloc(sizeof(t_imgb));
    var->mlx->miniMap = (t_imgb *)malloc(sizeof(t_imgb));
}

void ft_init_txts_varB(t_varb *var)
{
    var->txt->n_txt->onlyOne = 0;
    var->txt->s_txt->onlyOne = 0;
    var->txt->w_txt->onlyOne = 0;
    var->txt->e_txt->onlyOne = 0;
    var->floor->onlyF = 0;
    var->ceilling->onlyC = 0;
}

void ft_init_raycasting_varB(t_varb *var)
{
    //      Horizontal vars    //
    var->ray->xWallHit = 0;
    var->ray->yWallHit = 0;
    var->ray->horizontalWallFound = 0;
    var->ray->horizontalWallHitX = 0;
    var->ray->horizontalWallHitY = 0;

    //      Vertical vars    //
    var->ray->verticalWallHitX = 0;
    var->ray->verticalWallHitY = 0;
    var->ray->verticalWallFound = 0;
    var->ray->distance = 0;
    var->ray->wasHitVertical = 0;
}

void ft_init_facing_varB(t_varb *var)
{
    var->view->facingDown = 0;
    var->view->facingUp = 0;
    var->view->facingRight = 0;
    var->view->facingLeft = 0;
}

void ft_init_bonus(t_varb *var)
{
    ft_allocation_varB(var);
    ft_init_txts_varB(var);
    ft_init_raycasting_varB(var);
    ft_init_facing_varB(var);
    var->components = 0;
    var->status = 0;
    var->count_player = 0;
    var->miniMapHook = 0;
}

//   ------   The function of giving int value to each ID   ------   //

void ft_whichId_bonus(t_varb *var)
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

//   ------   The function of storing the txts data   ------   //

void storeDatatxtB(t_varb *var)
{
    if (var->status == 1)
    {
        var->txt->n_txt->id = mystrdupB("NO");
        var->txt->n_txt->path = mystrdupB(var->tmpMap[1]);
        var->txt->n_txt->onlyOne += 1;
    }
    if (var->status == 2)
    {
        var->txt->s_txt->id = mystrdupB("SO");
        var->txt->s_txt->path = mystrdupB(var->tmpMap[1]);
        var->txt->s_txt->onlyOne += 1;
    }
    if (var->status == 3)
    {
        var->txt->w_txt->id = mystrdupB("WE");
        var->txt->w_txt->path = mystrdupB(var->tmpMap[1]);
        var->txt->w_txt->onlyOne += 1;
    }
    if (var->status == 4)
    {
        var->txt->e_txt->id = mystrdupB("EA");
        var->txt->e_txt->path = mystrdupB(var->tmpMap[1]);
        var->txt->e_txt->onlyOne += 1;
    }
}

//   ------   The function of checking the RGB values   ------   //

void ft_validValueB(int nbr)
{
    if (nbr < 0)
        ft_messageErrorB("\033[91mNegative Value in RGB !\033[91m");
    if (nbr > 255)
        ft_messageErrorB("\033[91mValue > 255 !\033[91m");
}

//   ------   The function of checking the RGB syntax   ------   //

void ft_checkValidRgbB(t_varb *var)
{
    int i;

    i = 0;
    while (var->tmpRgb[i])
        i++;
    if (i != 3)
        ft_messageErrorB("\033[91mThe RGB Vaue should be in this form exp : 0, 255, 255 !\033[91m");
}

//   ------   The function of parcing and storing the data of RGB     ------   //

void ft_splitConvertRgbB(t_varb *var)
{
    int i;

    i = 0;
    var->tmpRgb = ft_split(var->tmpMap[1], ',');
    if (var->tmpRgb == NULL)
        ft_messageErrorB("\033[91mInvalid RGB syntax !\033[91m");
    ft_checkValidRgbB(var);
    if (var->status == 5)
    {
        while (i < 3)
        {
            var->floor->color[i] = ft_atoiB(var->tmpRgb[i]);
            ft_validValueB(var->floor->color[i]);
            i++;
        }
        var->floor->onlyF += 1;
    }
    i = 0;
    if (var->status == 6)
    {
        while (i < 3)
        {
            var->ceilling->color[i] = ft_atoiB(var->tmpRgb[i]);
            ft_validValueB(var->ceilling->color[i]);
            i++;
        }
        var->ceilling->onlyC += 1;
    }
}

//   ------   The function of storing the data of Floor and Ceilling    ------   //

void storeDataFloorCeillingB(t_varb *var)
{
    if (var->status == 5)
    {
        var->floor->id = 'F';
        ft_splitConvertRgbB(var); // Check and parce the RGB values of Floor
    }
    if (var->status == 6)
    {
        var->ceilling->id = 'C';
        ft_splitConvertRgbB(var); // Check and parce the RGB values of Ceilling
    }
}

//   ------   The function of calculating the components    ------   //

void ft_calculComponentsB(t_varb *var)
{
    int i;

    i = 0;
    while (var->tmpMap[i])
        i++;
    var->components = i;
}

//   ------   The function of checking the syntax of txts    ------   //

void ft_checktxtsB(t_varb *var)
{
    ft_calculComponentsB(var);
    if (var->components != 2)
        ft_messageErrorB("\033[91mInvalid Syntax txts !\033[91m");
    if (open(var->tmpMap[1], O_RDONLY) == -1)
        ft_messageErrorB("\033[91mWrong Path or Permessions of txts !\033[91m");
}

//   ------   The function of checking the syntax of Floor and Ceillig    ------   //

void ft_checkFloorCeillingB(t_varb *var)
{
    ft_calculComponentsB(var);
    if (var->components != 2)
        ft_messageErrorB("\033[91mInvalid Syntax Floor or Ceilling !\033[91m");
}

//   ------   The function of checking the double data (txts/Floor/Ceilling Ids)    ------   //

void ft_checkDoubleIdB(t_varb *var)
{
    if (var->txt->n_txt->onlyOne > 1)
        ft_messageErrorB("\033[91mDouble txt NO!\033[91m");
    if (var->txt->s_txt->onlyOne > 1)
        ft_messageErrorB("\033[91mDouble txt SO !\033[91m");
    if (var->txt->w_txt->onlyOne > 1)
        ft_messageErrorB("\033[91mDouble txt WE!\033[91m");
    if (var->txt->e_txt->onlyOne > 1)
        ft_messageErrorB("\033[91mDouble txt EA!\033[91m");
    if (var->floor->onlyF > 1)
        ft_messageErrorB("\033[91mDouble Id F!\033[91m");
    if (var->ceilling->onlyC > 1)
        ft_messageErrorB("\033[91mDouble Id C!\033[91m");
}

//   ------   The main function of cheking errors and storing the data if it's valide    ------   //

void ft_check_idB(t_varb *var)
{
    int i;
    int validId; // to check if the identifier is valide

    var->idtxts = ft_split("NO,SO,WE,EA", ',');
    i = 0;
    validId = 0;
    while (i < 4)
    {
        if (ft_strcmp(var->tmpMap[0], var->idtxts[i]) == 0)
        {
            ft_checktxtsB(var);    //  check error of txts !!
            ft_whichId_bonus(var); //   determinate the status : NO || SO || ....
            storeDatatxtB(var);    //    if everthing is correct store the data
            validId = 1;
            ft_checkDoubleIdB(var);
        }
        i++;
    }
    if (ft_strcmp(var->tmpMap[0], "F") == 0 || ft_strcmp(var->tmpMap[0], "C") == 0)
    {
        ft_checkFloorCeillingB(var);  //  check error of txts !!
        ft_whichId_bonus(var);        //   determinate the status : F  || C || ....
        storeDataFloorCeillingB(var); //    if everthing is correct store the data  (needs to convert! !)
        validId = 1;
        ft_checkDoubleIdB(var);
    }
    if (var->tmpMap[0][0] == '1')
        ft_messageErrorB("\033[91mSome informations missed from the file (4 txts, Floor and Ceilling data should be exist) !\033[91m");
    if (validId == 0)
        ft_messageErrorB("\033[91mInvalid ID !\033[91m");
}

//   ------   The function of freeing 2D table     ------   //

void ft_freeArray2dB(char **arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

//   ------   The function of reading one line each time     ------   //

void ft_read_bonus(t_varb *var)
{
    int i;

    i = 0;
    var->tmp = get_next_line(var->fd);
    var->tmpMap = ft_multisplit(var->tmp, " \n");
    free(var->tmp);
}
//   ------   The main function of reading , checking and storing the data     ------   //

void ft_readAndCheckB(t_varb *var)
{
    int i;

    i = 0;
    while (i < 6)
    {
        ft_read_bonus(var);
        while (var->tmpMap[0] == NULL)
            ft_read_bonus(var);
        i++;
        ft_check_idB(var);
    }
}
//  -------  The fuction of initialize th keys   -------- //

void initKeys_bonus(t_varb *var)
{
    var->keyPerssed->keyW = 0;
    var->keyPerssed->keyS = 0;
    var->keyPerssed->keyD = 0;
    var->keyPerssed->keyA = 0;
    var->keyPerssed->keyTurnLeft = 0;
    var->keyPerssed->keyTurnRight = 0;
}

//   ------   The main function of parcing    ------   //

void ft_parcing_bonus(t_varb *var, char *str)
{
    ft_creatFd_bonus(var, str);
    if (!ft_check_extension(str))
        ft_messageErrorB("\033[91mInvalid extension !\033[91m");
    ft_readAndCheckB(var);

    //   ------    Part 2 : reading and parcing map    ------   //
    read_map_bonus(var);
}