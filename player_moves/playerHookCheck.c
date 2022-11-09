/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:37:41 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/09 18:19:47 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"






//     ----------------------- Function of hooking on the key pressed ---------------------------- //

int	key_hook(int key,t_var *var)
{
	
	if (key == 123)
        var->keyPerssed->keyTurnLeft = 1;
	if (key == 124)
        var->keyPerssed->keyTurnRight = 1;
	if (key == 13)
        var->keyPerssed->keyW = 1;
    if (key == 1)
        // move back
        var->keyPerssed->keyS = 1;
    if (key == 0)
        // move left
        var->keyPerssed->keyA = 1;
    if (key == 2)
        // move right
        var->keyPerssed->keyD = 1;
    if (key == 46)
        var->miniMapHook = 1;   // for bonus
    if (key == 53)
		cross(var);
	return (0);
}

// -------------------------------------------------------------------------------------------------------- //


//     ----------------------- Function of hooking on the key releasted ---------------------------- //

int    key_release(int key, t_var *var)
{

	if (key == 123)
    {
        // // left view  (rotation)
        var->player->turnLeftRight = 0;
        var->keyPerssed->keyTurnLeft = 0;
        
    }
	if (key == 124)
    {
        // // right view  (rotation)
        var->player->turnLeftRight = 0;
        var->keyPerssed->keyTurnRight = 0;

    }
    if (key == 13)
    {
        // move forward
        var->player->walkBackForward = 0;
        var->keyPerssed->keyW = 0;
    }
    if (key == 1)
    {
            // move back
        var->player->walkBackForward = 0;
        var->keyPerssed->keyS = 0;
    }
    if (key == 0)
    { 
           // move left
        var->player->walkBackForward = 0;
        var->keyPerssed->keyA = 0;
    }
    if (key == 2)
    {
            // move right
        var->player->walkBackForward = 0;
        var->keyPerssed->keyD = 0;
    }
    
    if (key == 53)
		cross(var);
	return (0);
}



void    normilizeAngle(t_var *var)
{

    var->player->rotationAngle = fmod(var->player->rotationAngle, 2 * M_PI);
    if (var->player->rotationAngle < 0)
        var->player->rotationAngle += 2 * M_PI;
    
}

void    normalizingRayAngle(t_var *var)
{
    var->ray->rayAngle = fmod(var->ray->rayAngle, 2 * M_PI);
    if (var->ray->rayAngle < 0)
        var->ray->rayAngle += 2 * M_PI;
}


int checkIfWall(t_var *var, int status)
{
    int posX = 0;
    int posY = 0;

    
    if (status == 1)
    {
        posX = floor((var->player->x + cos(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
        posY = floor((var->player->y + sin(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
    }
    
    else if (status == 2)
    {
        posX = floor((var->player->x - cos(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
        posY = floor((var->player->y - sin(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
    }
    else if (status == 3)
    {
        posX = floor((var->player->x - sin(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
        posY = floor((var->player->y + cos(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
    }
    else if (status == 4)
    {
        posX = floor((var->player->x + sin(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
        posY = floor((var->player->y - cos(var->player->rotationAngle) * var->player->moveSpeed) / TILE_SIZE);
    }
    
    if (var->map[posY][posX] == '1')
        return (1);
                // ----------------- protect cases when player move between intersection of walls --------------------
    if (var->map[posY][posX - 1] == '1' && var->map[posY + 1][posX] == '1')
        if ((floor((var->player->y / TILE_SIZE)) == posY + 1) && (floor((var->player->x / TILE_SIZE)) == posX - 1))
            return (1);
    if (var->map[posY][posX + 1] == '1' && var->map[posY - 1][posX] == '1')
        if ((floor((var->player->y / TILE_SIZE)) == posY - 1) && (floor((var->player->x / TILE_SIZE)) == posX + 1))
            return (1);
    if (var->map[posY][posX + 1] == '1' && var->map[posY][posX + 1] == '1')
        if ((floor((var->player->y / TILE_SIZE)) == posY + 1) && (floor((var->player->x / TILE_SIZE)) == posX + 1))
            return (1);
    if (var->map[posY][posX - 1] == '1' && var->map[posY - 1][posX] == '1')
        if ((floor((var->player->y / TILE_SIZE)) == posY - 1) && (floor((var->player->x / TILE_SIZE)) == posX - 1))
            return (1);
    return (0);
}


void    keyPressedAction(t_var *var)
{
    
    normilizeAngle(var);
    
    if (var->keyPerssed->keyW == 1)
    {
        if (checkIfWall(var,1) == 0)
        {
            var->player->walkBackForward = 1;
            var->player->moveStep =  var->player->walkBackForward * var->player->moveSpeed;
            var->player->x += cos(var->player->rotationAngle) * var->player->moveSpeed;
            var->player->y += sin(var->player->rotationAngle) * var->player->moveSpeed;
        }
    }
    if (var->keyPerssed->keyS == 1)
    {
        if (checkIfWall(var,2) == 0)
        {
            var->player->walkBackForward = -1;
            var->player->moveStep =  var->player->walkBackForward * var->player->moveSpeed;
            var->player->x -= cos(var->player->rotationAngle) * var->player->moveSpeed;
            var->player->y -= sin(var->player->rotationAngle) * var->player->moveSpeed;
        }
    }
    if ( var->keyPerssed->keyD == 1)
    {
        if (checkIfWall(var,3) == 0)
        {
            var->player->walkBackForward = 1;
            var->player->moveStep =  var->player->walkBackForward * var->player->moveSpeed;
            var->player->x -= sin(var->player->rotationAngle) * var->player->moveSpeed;
            var->player->y += cos(var->player->rotationAngle) * var->player->moveSpeed;
        }
    }
    if (var->keyPerssed->keyA == 1)
    {
        if (checkIfWall(var,4) == 0)
        {
            var->player->walkBackForward = -1;
            var->player->moveStep =  var->player->walkBackForward * var->player->moveSpeed;
            var->player->x += sin(var->player->rotationAngle) * var->player->moveSpeed;
            var->player->y -= cos(var->player->rotationAngle) * var->player->moveSpeed;
        }
    }
    if (var->keyPerssed->keyTurnLeft == 1)
    {
        var->player->turnLeftRight = -1;
        // the data will be updated before printing the line
    }
    if (var->keyPerssed->keyTurnRight == 1)
    {
        var->player->turnLeftRight = 1;
        // the data will be updated before printing the line
    }
}
