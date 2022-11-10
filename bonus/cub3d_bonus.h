/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:45:37 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/10 11:09:56 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CUB3D_BONUS
#define H_CUB3D_BONUS

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <mlx.h> 
# include <math.h>
# include <limits.h>

# include "../get_next_line/get_next_line.h"
# include "../cub3d.h"


#define TILE_SIZE 36 
#define SCALE_MINI_MAP 0.2

int     reprint_map_bonus(void *var);
void    draw_all_bonus(t_varb *var);
void	drawLineBonus(t_varb *var);
void    draw_mini_mapB(t_varb *var);
void    draw_player_bonus(t_varb *var);
void    draw_cube_bonus(t_varb *var, int width, int height, char *color);
void    drawCeillingFloorB(t_varb *var);
void    my_img_pix_put_bonus(t_varb *var, int x, int y, int color);
void	draw_wall_bonus(double x1, double y1, double y2, double x2 ,t_varb *var);
int     cross_bonus(t_varb *var);
void    keyPressedAction_bonus(t_varb *var);
void    ft_init_bonus(t_varb *var);
void    initKeys_bonus(t_varb *var);
void    ft_parcing_bonus(t_varb *var, char *str);
void    set_map_size_bonus(t_varb *var);
void    set_up_all_bonus(t_varb *var);
int     reprint_map_bonus(void *var);
void    check_walls_bonus(t_varb *var);
void    handle_space_in_linesB(t_varb *var, int x, char *str);
void    handle_space_inside_mapB(t_varb *var, int y, int x);
void    check_line_size_bonus(t_varb *var, int y);
void    getPlayerPosition_bonus(t_varb *var ,int x, int y);
void    getAngleValue_bonus(char c, t_varb *var);
void    check_map_bonus(t_varb *var);
void    ft_messageErrorB(char *msg);
void    ft_allocation_varB(t_varb *var);
void    ft_init_textures_varB(t_varb *var);
void    ft_init_raycasting_varB(t_varb *var);
void    ft_whichId_bonus(t_varb *var);
void    storeDataTextureB(t_varb *var);
void    ft_validValueB(int nbr);
void    ft_checkValidRgbB(t_varb *var);
void    ft_splitConvertRgbB(t_varb *var);
void    storeDataFloorCeillingB(t_varb *var);
void    ft_calculComponentsB(t_varb *var);
void    ft_checkTexturesB(t_varb *var);
void    ft_checkFloorCeillingB(t_varb *var);
void    ft_checkDoubleIdB(t_varb *var);
void    ft_check_idB(t_varb *var);
void    ft_freeArray2dB(char **arr);
void    ft_read_bonus(t_varb *var);
void    ft_readAndCheckB(t_varb   *var);
int     key_hook_bonus(int key,t_varb *var);
int     key_release_bonus(int key, t_varb *var);
void    normilizeAngleB(t_varb *var);
void    normalizingRayAngleB(t_varb *var);
int     checkIfWallB(t_varb *var, int status);
void	initialize_dataB(t_varb *var);
int     checkMapSratB(char *str);
void	read_map_bonus(t_varb *var);
void    rendering3D_bonus(t_varb *var);
void    facingUpDownB(t_var *var);
void    whereFacingB(t_var *var);
void    getIntersectionHorizontalB(t_var *var);
double  getHorizDistanceB(t_var *var);
double  getVerticDistanceB(t_var *var);
void    getIntersectionVerticalB(t_var *var);







typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_imgb;

typedef struct s_mlx
{
    void    *init;
    void    *win;
    t_img   img;
    t_img   *imgWall;
    t_img   *miniMap;
    int     max_len;
    int     width;
    int     height;
} t_mlxb;

typedef struct s_player{
    
    double  x;
    double  y;
    double  sizePlayer;
    int     turnLeftRight;
    int     walkBackForward; 
    double  rotationAngle;// depends on The symbole of player on the map 
    double  moveSpeed;
    double  moveStep;
    double  rotationSpeed; // means 3deg of retation per each click 
    double  tempX;
    double  tempY;
} t_playerb;


typedef struct s_keyPressed
{
    int keyW;
    int keyS;
    int keyD;
    int keyA;
    int keyTurnLeft;
    int keyTurnRight;

} t_keyPressedb;

typedef struct s_raycasting
{
    //  ------------- horizontal variables -------------- //
    double  fov;
    double  rayAngle;
    double  yWallHit;
    double  xWallHit;
    double  xintercept;
    double  yintercept;
    double  xstep;
    double  ystep;
    double  horizDistance;
    int     horizontalWallFound;
    double  horizontalWallHitX;
    double  horizontalWallHitY;

    //  ------------- vertical variables -------------- //
    double  verticalWallHitX;
    double  verticalWallHitY;
    double  xVerticalIntercept;
    double  yVerticalIntercept;
    double  xVerticalStep;
    double  yVerticalStep;
    double  verticDistance;
    int     verticalWallFound;



    int  wasHitVertical;

    double  distance;

} t_raycastingb;

typedef struct s_view
{
    int facingUp;
    int facingDown;
    int facingRight;
    int facingLeft;

} t_viewb;

typedef struct s_textureData
{
    char    *id;
    char    *path;
    int     onlyOne;
} t_textureDatab;

typedef struct s_texture
{
    t_textureData   *north_texture;
    t_textureData   *west_texture;
    t_textureData   *south_texture;
    t_textureData   *east_texture;

} t_textureb;

typedef struct s_floorData
{
    char    id;
    int     *color;
    int     onlyF;
}  t_floorDatab;

typedef struct s_ceillibData
{
    char    id;
    int     *color;
    int     onlyC;
}  t_ceillibDatab;    

typedef struct s_var
{
    int              fd;
    char            *tmp;
    char            **tmpMap;
    char            **tmpRgb;
    char            **map;
    int             components;
    int             status;
    t_mlxb           * mlx;
    t_playerb        *player;
    t_textureb       *texture;
    t_floorDatab     *floor;
    t_ceillibDatab   *ceilling;
    t_keyPressedb    *keyPerssed;
    t_raycastingb    *ray;
    t_viewb          *view;

    char            **idTextures;

    int             unsedAvoid;
    int             firstDraw;
    int             spaceCase;

    int             miniMapHook;
    //  -----------    Brahim Part    -----------  //
    int     count_line;
    char    *buff;
    char    *save;
    char    *mapInLine; 
    int     count_player;
    int     nothing;

} t_varb;



#endif