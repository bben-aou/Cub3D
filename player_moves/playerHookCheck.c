/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerHookCheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:37:41 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 12:04:51 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//     ----------------------- Function of hooking on the key pressed ---------------------------- //

int key_hook(int key, t_var *var)
{
    if (key == 123)
        var->keyPerssed->key_turn_left = 1;
    if (key == 124)
        var->keyPerssed->key_turn_right = 1;
    if (key == 13)
        var->keyPerssed->key_w = 1;
    if (key == 1)
        // move back
        var->keyPerssed->key_s = 1;
    if (key == 0)
        // move left
        var->keyPerssed->key_a = 1;
    if (key == 2)
        // move right
        var->keyPerssed->key_d = 1;
    if (key == 53)
        cross(var);
    return (0);
}

// -------------------------------------------------------------------------------------------------------- //

//     ----------------------- Function of hooking on the key releed ---------------------------- //

int key_release(int key, t_var *var)
{

    if (key == 123)
    {
        // // left view  (rotation)
        var->player->turn_left_right = 0;
        var->keyPerssed->key_turn_left = 0;
    }
    if (key == 124)
    {
        // // right view  (rotation)
        var->player->turn_left_right = 0;
        var->keyPerssed->key_turn_right = 0;
    }
    if (key == 13)
    {
        // move forward
        var->player->walk_back_forward = 0;
        var->keyPerssed->key_w = 0;
    }
    if (key == 1)
    {
        // move back
        var->player->walk_back_forward = 0;
        var->keyPerssed->key_s = 0;
    }
    if (key == 0)
    {
        // move left
        var->player->walk_back_forward = 0;
        var->keyPerssed->key_a = 0;
    }
    if (key == 2)
    {
        // move right
        var->player->walk_back_forward = 0;
        var->keyPerssed->key_d = 0;
    }
    if (key == 53)
        cross(var);
    return (0);
}

void normalize_angle(t_var *var)
{

    var->player->rotatin_angle = fmod(var->player->rotatin_angle, 2 * M_PI);
    if (var->player->rotatin_angle < 0)
        var->player->rotatin_angle += 2 * M_PI;
}

void normalizingray_angle(t_var *var)
{
    var->ray->ray_angle = fmod(var->ray->ray_angle, 2 * M_PI);
    if (var->ray->ray_angle < 0)
        var->ray->ray_angle += 2 * M_PI;
}

int checkIfWall(t_var *var, int status)
{
    int posX = 0;
    int posY = 0;

    if (status == 1)
    {
        posX = floor((var->player->x + cos(var->player->rotatin_angle) * var->player->move_speed) / T_S);
        posY = floor((var->player->y + sin(var->player->rotatin_angle) * var->player->move_speed) / T_S);
    }

    else if (status == 2)
    {
        posX = floor((var->player->x - cos(var->player->rotatin_angle) * var->player->move_speed) / T_S);
        posY = floor((var->player->y - sin(var->player->rotatin_angle) * var->player->move_speed) / T_S);
    }
    else if (status == 3)
    {
        posX = floor((var->player->x - sin(var->player->rotatin_angle) * var->player->move_speed) / T_S);
        posY = floor((var->player->y + cos(var->player->rotatin_angle) * var->player->move_speed) / T_S);
    }
    else if (status == 4)
    {
        posX = floor((var->player->x + sin(var->player->rotatin_angle) * var->player->move_speed) / T_S);
        posY = floor((var->player->y - cos(var->player->rotatin_angle) * var->player->move_speed) / T_S);
    }

    if (var->map[posY][posX] == '1')
        return (1);
    // ----------------- protect cases when player move between intersection of walls --------------------
    if (var->map[posY][posX - 1] == '1' && var->map[posY + 1][posX] == '1')
        if ((floor((var->player->y / T_S)) == posY + 1) && (floor((var->player->x / T_S)) == posX - 1))
            return (1);
    if (var->map[posY][posX + 1] == '1' && var->map[posY - 1][posX] == '1')
        if ((floor((var->player->y / T_S)) == posY - 1) && (floor((var->player->x / T_S)) == posX + 1))
            return (1);
    if (var->map[posY][posX + 1] == '1' && var->map[posY][posX + 1] == '1')
        if ((floor((var->player->y / T_S)) == posY + 1) && (floor((var->player->x / T_S)) == posX + 1))
            return (1);
    if (var->map[posY][posX - 1] == '1' && var->map[posY - 1][posX] == '1')
        if ((floor((var->player->y / T_S)) == posY - 1) && (floor((var->player->x / T_S)) == posX - 1))
            return (1);
    return (0);
}

void key_pressed_action(t_var *var)
{

    normalize_angle(var);

    if (var->keyPerssed->key_w == 1)
    {
        if (checkIfWall(var, 1) == 0)
        {
            var->player->walk_back_forward = 1;
            var->player->move_step = var->player->walk_back_forward * var->player->move_speed;
            var->player->x += cos(var->player->rotatin_angle) * var->player->move_speed;
            var->player->y += sin(var->player->rotatin_angle) * var->player->move_speed;
        }
    }
    if (var->keyPerssed->key_s == 1)
    {
        if (checkIfWall(var, 2) == 0)
        {
            var->player->walk_back_forward = -1;
            var->player->move_step = var->player->walk_back_forward * var->player->move_speed;
            var->player->x -= cos(var->player->rotatin_angle) * var->player->move_speed;
            var->player->y -= sin(var->player->rotatin_angle) * var->player->move_speed;
        }
    }
    if (var->keyPerssed->key_d == 1)
    {
        if (checkIfWall(var, 3) == 0)
        {
            var->player->walk_back_forward = 1;
            var->player->move_step = var->player->walk_back_forward * var->player->move_speed;
            var->player->x -= sin(var->player->rotatin_angle) * var->player->move_speed;
            var->player->y += cos(var->player->rotatin_angle) * var->player->move_speed;
        }
    }
    if (var->keyPerssed->key_a == 1)
    {
        if (checkIfWall(var, 4) == 0)
        {
            var->player->walk_back_forward = -1;
            var->player->move_step = var->player->walk_back_forward * var->player->move_speed;
            var->player->x += sin(var->player->rotatin_angle) * var->player->move_speed;
            var->player->y -= cos(var->player->rotatin_angle) * var->player->move_speed;
        }
    }
    if (var->keyPerssed->key_turn_left == 1)
        var->player->turn_left_right = -1;
    // the data will be updated before printing the line
    if (var->keyPerssed->key_turn_right == 1)
        var->player->turn_left_right = 1;
    // the data will be updated before printing the line
}
