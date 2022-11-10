/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:00:31 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/10 11:10:10 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    facingUpDownB(t_var *var)
{
        if (var->ray->rayAngle > 0 && var->ray->rayAngle < M_PI)
    {
        var->view->facingDown = 1;
        var->view->facingUp = 0;
    }
    else
    {
        var->view->facingDown = 0;
        var->view->facingUp = 1;
    }
}

void    whereFacingB(t_var *var)
{

    if (var->ray->rayAngle < (0.5 * M_PI) || var->ray->rayAngle > (1.5 * M_PI))
    {
        var->view->facingRight = 1;
        var->view->facingLeft = 0;
    }
    else
    {
        var->view->facingLeft = 1;
        var->view->facingRight = 0;
        
    }
}


void    getIntersectionHorizontalB(t_var *var)
{
    double  nextHorizontalX;
    double  nextHorizontalY;

    whereFacingB(var);
    facingUpDownB(var);
        var->ray->horizontalWallFound = 0;
    var->ray->yintercept = floor(var->player->y / TILE_SIZE) * TILE_SIZE;
    if ( var->view->facingDown == 1)
        var->ray->yintercept += TILE_SIZE;
    var->ray->xintercept = var->player->x + (var->ray->yintercept - var->player->y) / tan(var->ray->rayAngle);
    var->ray->ystep = TILE_SIZE;
    if (var->view->facingUp == 1)
        var->ray->ystep *= -1;
    var->ray->xstep = var->ray->ystep / tan(var->ray->rayAngle);
    if (var->view->facingLeft && var->ray->xstep > 0)
        var->ray->xstep *= -1;
    if (var->view->facingRight && var->ray->xstep < 0)
        var->ray->xstep *= -1; 

    nextHorizontalX = var->ray->xintercept;
    nextHorizontalY = var->ray->yintercept;
    if (var->view->facingUp == 1)
        nextHorizontalY -= 1;
    while (nextHorizontalX >= 0 && nextHorizontalX <= var->mlx->width && nextHorizontalY >= 0 && nextHorizontalY <= var->mlx->height )
    {
        if (var->map[(int)floor(nextHorizontalY / TILE_SIZE)][(int)floor(nextHorizontalX / TILE_SIZE)] == '1')
        {
            var->ray->horizontalWallFound = 1;
            var->ray->horizontalWallHitX = nextHorizontalX;
            var->ray->horizontalWallHitY = nextHorizontalY + 1 ;
            break;
        }
        else
        {
            nextHorizontalX += var->ray->xstep;
            nextHorizontalY += var->ray->ystep;
        }
    }
}

double  getHorizDistanceB(t_var *var)
{
    double  value;
    double  deltaX;
    double  deltaY;
    
    deltaX = pow(var->ray->horizontalWallHitX - var->player->x, 2);
    deltaY = pow(var->ray->horizontalWallHitY - var->player->y, 2);
    value = sqrt(deltaX + deltaY);
    return (value);
}

double  getVerticDistanceB(t_var *var)
{
    double  value;
    double  deltaX;
    double deltaY;

    deltaX = pow(var->ray->verticalWallHitX - var->player->x, 2);
    deltaY = pow(var->ray->verticalWallHitY - var->player->y, 2);
    value = sqrt(deltaX + deltaY);
    return (value);
}


void    getIntersectionVerticalB(t_var *var)
{
    double  nextVerticalX;
    double  nextVerticalY;

    
        var->ray->verticalWallFound = 0;
    var->ray->xVerticalIntercept = floor(var->player->x / TILE_SIZE) * TILE_SIZE;
    if (var->view->facingRight == 1)
        var->ray->xVerticalIntercept += TILE_SIZE;
    var->ray->yVerticalIntercept = var->player->y + (var->ray->xVerticalIntercept - var->player->x) * tan(var->ray->rayAngle);
    var->ray->xVerticalStep = TILE_SIZE;
    if (var->view->facingLeft == 1)
        var->ray->xVerticalStep *= -1;
    var->ray->yVerticalStep = var->ray->xVerticalStep * tan(var->ray->rayAngle);
    if (var->view->facingUp && var->ray->yVerticalStep > 0)
        var->ray->yVerticalStep *= -1;
    if (var->view->facingDown && var->ray->yVerticalStep < 0)
        var->ray->yVerticalStep *= -1;
    nextVerticalX  = var->ray->xVerticalIntercept;
    nextVerticalY  = var->ray->yVerticalIntercept;
    if (var->view->facingLeft)
         nextVerticalX -= 1 ;
    while (nextVerticalX >= 0 && nextVerticalX <= var->mlx->width && nextVerticalY >= 0 && nextVerticalY <= var->mlx->height)
    {
      
        if (var->map[(int)floor(nextVerticalY/ TILE_SIZE)][(int)floor(nextVerticalX / TILE_SIZE)] == '1')
        {
            var->ray->verticalWallFound = 1;
            var->ray->verticalWallHitX = nextVerticalX  + 1;
            var->ray->verticalWallHitY = nextVerticalY ;
            break;
        }
        else
        {
            nextVerticalX += var->ray->xVerticalStep;
            nextVerticalY += var->ray->yVerticalStep;

        }
    }
    if (var->ray->horizontalWallFound == 1)
        var->ray->horizDistance = getHorizDistanceB(var);
    else
        var->ray->horizDistance = LONG_MAX;
    if (var->ray->verticalWallFound == 1)
        var->ray->verticDistance = getVerticDistanceB(var);
    else
        var->ray->verticDistance = LONG_MAX;
    if (var->ray->horizDistance < var->ray->verticDistance)
    {
        var->ray->xWallHit = var->ray->horizontalWallHitX;
        var->ray->yWallHit = var->ray->horizontalWallHitY;

    }
    else
    {
        var->ray->xWallHit = var->ray->verticalWallHitX;
        var->ray->yWallHit = var->ray->verticalWallHitY;

    }
    if (var->ray->horizDistance < var->ray->verticDistance)
        var->ray->distance = var->ray->horizDistance;
    else  
        var->ray->distance = var->ray->verticDistance;
    
    if (var->ray->verticDistance < var->ray->horizDistance)
        var->ray->wasHitVertical = 1;
}
