/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:45:37 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/14 15:47:33 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CUB3D_BONUS
#define H_CUB3D_BONUS

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <mlx.h>
#include <math.h>
#include <limits.h>

#include "../get_next_line/get_next_line.h"

#define T_S 64
#define SCALE_MINI_MAP 0.2

typedef struct s_imgb
{
    void *img;
    char *addr;
    int bpp; /* bits per pixel */
    int line_len;
    int endian;
} t_imgb;

typedef struct s_mlxb
{
    void *init;
    void *win;
    t_imgb img;
    t_imgb *imgWall;
    t_imgb *miniMap;
    int max_len;
    int width;
    int height;
} t_mlxb;

typedef struct s_playerb
{

    double x;
    double y;
    double sizePlayer;
    int turnLeftRight;
    int walkBackForward;
    double rotationAngle; // depends on The symbole of player on the map
    double moveSpeed;
    double moveStep;
    double rotationSpeed; // means 3deg of retation per each click
    double tempX;
    double tempY;
} t_playerb;

typedef struct s_keyPressedb
{
    int keyW;
    int keyS;
    int keyD;
    int keyA;
    int keyTurnLeft;
    int keyTurnRight;

} t_keyPressedb;

typedef struct s_raycastingb
{
    //  ------------- horizontal variables -------------- //
    double fov;
    double rayAngle;
    double yWallHit;
    double xWallHit;
    double xintercept;
    double yintercept;
    double xstep;
    double ystep;
    double horizDistance;
    int horizontalWallFound;
    double horizontalWallHitX;
    double horizontalWallHitY;

    //  ------------- vertical variables -------------- //
    double verticalWallHitX;
    double verticalWallHitY;
    double xVerticalIntercept;
    double yVerticalIntercept;
    double xVerticalStep;
    double yVerticalStep;
    double verticDistance;
    int verticalWallFound;

    int wasHitVertical;

    double distance;

} t_raycastingb;

typedef struct s_viewb
{
    int facingUp;
    int facingDown;
    int facingRight;
    int facingLeft;

} t_viewb;

typedef struct s_txtDatab
{
    char *id;
    char *path;
    int onlyOne;
} t_txtDatab;

typedef struct s_txtb
{
    t_txtDatab *n_txt;
    t_txtDatab *w_txt;
    t_txtDatab *s_txt;
    t_txtDatab *e_txt;

} t_txtb;

typedef struct s_floorDatab
{
    char id;
    int *color;
    int onlyF;
} t_floorDatab;

typedef struct s_ceillibDatab
{
    char id;
    int *color;
    int onlyC;
} t_ceillibDatab;

typedef struct s_varb
{
    int fd;
    char *tmp;
    char **tmpMap;
    char **tmpRgb;
    char **map;
    int components;
    int status;
    t_mlxb *mlx;
    t_playerb *player;
    t_txtb *txt;
    t_floorDatab *floor;
    t_ceillibDatab *ceilling;
    t_keyPressedb *keyPerssed;
    t_raycastingb *ray;
    t_viewb *view;

    char **idtxts;

    int unsedAvoid;
    int firstDraw;
    int spaceCase;

    int miniMapHook;
    //  -----------    Brahim Part    -----------  //
    int count_line;
    char *buff;
    char *save;
    char *mapInLine;
    int count_player;
    int nothing;

} t_varb;

int reprint_map_bonus(void *var);
void draw_all_bonus(t_varb *var);
void drawLineBonus(t_varb *var);
void draw_mini_mapB(t_varb *var);
void draw_player_bonus(t_varb *var);
void draw_cube_bonus(t_varb *var, int width, int height, char *color);
void drawCeillingFloorB(t_varb *var);
void my_img_pix_put_bonus(t_varb *var, int x, int y, int color);
void draw_wall_bonus(double x1, double y1, double y2, double x2, t_varb *var);
int cross_bonus(t_varb *var);
void keyPressedAction_bonus(t_varb *var);
void ft_init_bonus(t_varb *var);
void initKeys_bonus(t_varb *var);
void ft_parcing_bonus(t_varb *var, char *str);
void set_map_size_bonus(t_varb *var);
void set_up_all_bonus(t_varb *var);
int reprint_map_bonus(void *var);
void check_walls_bonus(t_varb *var);
void handle_space_in_linesB(t_varb *var, int x, char *str);
void handle_space_inside_mapB(t_varb *var, int y, int x);
void check_line_size_bonus(t_varb *var, int y);
void getPlayerPosition_bonus(t_varb *var, int x, int y);
void getAngleValue_bonus(char c, t_varb *var);
void check_map_bonus(t_varb *var);
void ft_messageErrorB(char *msg);
void ft_allocation_varB(t_varb *var);
void ft_init_txts_varB(t_varb *var);
void ft_init_raycasting_varB(t_varb *var);
void ft_whichId_bonus(t_varb *var);
void storeDatatxtB(t_varb *var);
void ft_validValueB(int nbr);
void ft_checkValidRgbB(t_varb *var);
void ft_splitConvertRgbB(t_varb *var);
void storeDataFloorCeillingB(t_varb *var);
void ft_calculComponentsB(t_varb *var);
void ft_checktxtsB(t_varb *var);
void ft_checkFloorCeillingB(t_varb *var);
void ft_checkDoubleIdB(t_varb *var);
void ft_check_idB(t_varb *var);
void ft_freeArray2dB(char **arr);
void ft_read_bonus(t_varb *var);
void ft_readAndCheckB(t_varb *var);
int key_hook_bonus(int key, t_varb *var);
int key_release_bonus(int key, t_varb *var);
void normilizeAngleB(t_varb *var);
void normalizingRayAngleB(t_varb *var);
int checkIfWallB(t_varb *var, int status);
void initialize_dataB(t_varb *var);
int checkMapSratB(char *str);
void read_map_bonus(t_varb *var);
void rendering_3d_bonus(t_varb *var);
void facingUpDownB(t_varb *var);
void whereFacingB(t_varb *var);
void getIntersectionHorizontalB(t_varb *var);
double getHorizDistanceB(t_varb *var);
double getVerticDistanceB(t_varb *var);
void getIntersectionVerticalB(t_varb *var);
char **ft_splitB1(char *s, char c);
char *ft_strdupB1(char *str);
int ft_strcmpB1(char *str, char *ptr);
char *mystrdupB(char *src);
int ft_atoiB(const char *str);
int ft_check_extension(char *str);
char **ft_multisplit(char *str, char *charset);
char **ft_split(char const *s, char c);
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *src, int j);
char *mystrdupB(char *src);
int ft_strlen1(const char *str);
void error_mapB1(char *msg, t_varb *var);

#endif