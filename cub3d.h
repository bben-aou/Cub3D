/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:45:57 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/13 14:21:13 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CUB3D
#define H_CUB3D

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <mlx.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include "./get_next_line/get_next_line.h"

#define TILE_SIZE 32
#define SCALE_MINI_MAP 0.2

typedef struct s_img
{
    void *img;
    int *addr;
    int bpp; /* bits per pixel */
    int line_len;
    int endian;
} t_img_txt;

typedef struct s_img_txt
{
    void *img;
    char *addr;
    int bpp; /* bits per pixel */
    int line_len;
    int endian;
} t_img;

typedef struct s_mlx
{
    void *init;
    void *win;
    t_img img;
    t_img *full_img;
    t_img *mini_map;
    int max_len;
    int width;
    int height;
} t_mlx;

typedef struct s_player
{

    double x;
    double y;
    double size_player;
    int turn_left_right;
    int walk_back_forward;
    double rotatin_angle; // depends on The symbole of player on the map
    double move_speed;
    double move_step;
    double rotation_speed; // means 3deg of retation per each click
} t_player;

typedef struct s_keyPressed
{
    int key_w;
    int key_s;
    int key_d;
    int key_a;
    int key_turn_left;
    int key_turn_right;

} t_keyPressed;

typedef struct s_raycasting
{
    //  ------------- horizontal variables -------------- //
    double fov;
    double ray_angle;
    double y_wall_hit;
    double x_wall_hit;
    double xintercept;
    double yintercept;
    double xstep;
    double ystep;
    double horz_distance;
    double horz_wall_hit_x;
    double horz_wall_hit_y;
    bool horz_wall_found;

    //  ------------- vertical variables -------------- //
    double vert_wall_hit_x;
    double vert_wall_hit_y;
    double x_vert_intercept;
    double y_vert_intercept;
    double x_vert_step;
    double y_vert_step;
    double vert_distance;
    bool vert_wall_found;
    bool was_hit_vert;

    double wall_height;
    double distance;

    double offset_x;
    double offset_y;

    int p_color;

    double wall_top;
    double wall_bottom;
} t_raycasting;

typedef struct s_view
{
    int facing_up;
    int facing_down;
    int facing_right;
    int facing_left;

} t_view;

typedef struct s_textureData
{
    t_img_txt *img;
    char *id;
    char *path;
    int width_txt;
    int height_txt;
    int only_one;
} t_textureData;

typedef struct s_texture
{
    t_textureData *north_texture;
    t_textureData *west_texture;
    t_textureData *south_texture;
    t_textureData *east_texture;

} t_texture;

typedef struct s_floorData
{
    char id;
    int *color;
    int only_f;
} t_floorData;

typedef struct s_ceillibData
{
    char id;
    int *color;
    int only_c;
} t_ceillibData;

typedef struct s_colors
{
    char *hex_color;
    char *r_hex;
    char *g_hex;
    char *b_hex;
    int i;
} t_colors;

typedef struct s_var
{
    int fd;
    char *tmp;
    char **tmp_map;
    char **tmp_rgb;
    char **map;
    int components;
    int status;
    t_mlx *mlx;
    t_player *player;
    t_texture *texture;
    t_floorData *floor;
    t_ceillibData *ceilling;
    t_keyPressed *keyPerssed;
    t_raycasting *ray;
    t_view *view;
    t_colors *clrf;
    t_colors *clrc;

    char **id_textures;

    int unsed_avoid;
    int first_draw;
    int space_case;

    int mini_mapHook;
    //  -----------    Brahim Part    -----------  //
    int count_line;
    char *buff;
    char *save;
    char *mapInLine;
    int count_player;
    int nothing;
    // ----------------- TExture ------------------ //
    void *n_texture;
    void *s_texture;
    void *e_texture;
    void *w_texture;

} t_var;

//  ================ init functions ================//

void ft_allocation_var(t_var *var);
void ft_init_textures_var(t_var *var);
void ft_init_raycasting_var(t_var *var);
void ft_init_facing_var(t_var *var);
void ft_init(t_var *var);
void initialize_data(t_var *var);
void get_angle_value(char c, t_var *var);
void get_player_postion(t_var *var, int x, int y);

//  ================ parcing textures and Ceilling/Floot functions ================//
void ft_which_id(t_var *var);
void store_data_texture(t_var *var);
void ft_valid_value(int nbr);
void ft_check_valid_rgb(t_var *var);
void ft_split_convert_rgb(t_var *var);
void store_data_floor_ceil(t_var *var);
void ft_calcul_components(t_var *var);
void ft_check_textures(t_var *var);
void ft_check_floor_ceil(t_var *var);
void ft_check_double_id(t_var *var);
void ft_check_id(t_var *var);
void ft_read(t_var *var);
void ft_read_and_check(t_var *var);
void ft_parcing(t_var *var, char *str);

//  ================ free functions ================//
void ft_free_array_2d(char **arr);

//  ================ rading , parcing and checking Map :  ================//
void read_map(t_var *var);
int check_map_start(char *str);
void check_map(t_var *var);
void check_lines(t_var *var);
void check_walls(t_var *var);
void handle_space_in_lines(t_var *var, int x, char *str);
void check_line_size(t_var *var, int y);
void check_char(t_var *var, int y, int x);
void handle_space_inside_map(t_var *var, int y, int x);

//  ================ message functions ================//
void ft_msg_error(char *msg);
void error_map(char *msg, t_var *var);

//  ================ Raycasting functions ================//
void get_intersection_horz(t_var *var);
double get_horz_distance(t_var *var);
double get_vert_distance(t_var *var);
void get_intersection_vert(t_var *var);

//  ================ rendring 3D functions ================//
int reprint_map(void *var);
void set_map_size(t_var *var);
void rendering3D(t_var *var);

//  ---------------   Bilal Part   ------------- //

int ft_strlen1(const char *str);
char *ft_strdup(char *src, int j);
char **ft_split(char const *s, char c);
char **ft_multisplit(char *str, char *charset);
char *ft_strtrim(char *s1, char const *set);
int ft_strcmp(char *s1, char *s2);
int ft_atoi(const char *str);
void ft_msg_error(char *msg);
void ft_creat_fd(t_var *var, char *str);
void ft_parcing(t_var *var, char *str);
int ft_check_extension(char *str);
void ft_read_and_check(t_var *var);
void ft_read(t_var *var);
void ft_check_id(t_var *var);
void ft_check_textures(t_var *var);
void ft_calcul_components(t_var *var);
void store_data_floor_ceil(t_var *var);
void ft_split_convert_rgb(t_var *var);
void ft_valid_value(int nbr);
void store_data_texture(t_var *var);
void ft_which_id(t_var *var);
void ft_free_array_2d(char **arr);
void ft_split_convert_rgb(t_var *var);
char *mystrdup(char *src);

//    ............... The mlx and player functions ...............

int cross(t_var *var);
int key_hook(int key, t_var *var);
int key_release(int key, t_var *var);

int key_mini_mapHook(int key, t_var *var);
int key_release_mp(int key, t_var *var);

//    ............... The setUp function of player  ...............

void draw_all(t_var *var);
void set_up_all(t_var *var);
void draw_line(t_var *var);

//  -----------    Brahim part    -----------  //

/**************Utiles Function****************/
char **ft_split_b(char *s, char c);
int ft_strlen(char const *str);
char *ft_strdup_b(char *str);
int ft_strcmp_b(char *str, char *ptr);
void error_map(char *msg, t_var *var);
/**************Check_Map Functions************/
void check_map(t_var *var);
void initialize_data(t_var *var);
void read_map(t_var *var);
void error_map(char *msg, t_var *var);
void check_map(t_var *var);
void check_line_size(t_var *var, int y);
void check_char(t_var *var, int y, int x);
void handle_space_inside_map(t_var *var, int y, int x);
void check_lines(t_var *var);
void handle_space_in_lines(t_var *var, int x, char *str);
void check_walls(t_var *var);
int check_map_start(char *str);
/**************Print map Function****************/
void ft_draw_map(t_var *var);
void draw_direction_line(t_var *var, int x, int y);
void my_img_pix_put(t_var *var, int x, int y, int color);

void draw_line2(t_var *var);
void draw_map(t_var *var);
void draw_player2(t_var *var);
void key_pressed_action(t_var *var);
void init_keys(t_var *var);

void normalizingray_angle(t_var *var);
void normalize_angle(t_var *var);

void ddraw_line(t_var *var);

void rendering_walls(t_var *var);

void my_img_pix_put2(t_var *var, int x, int y, int color);
void draw_ceil_floor(t_var *var);

void compare_distance(t_var *var);
void draw_texture(t_var *var, int id);

int draw_mini_map(t_var *var);

bool check_if_wall(t_var *var, int next_x, int next_y);
void ft_init_colors(t_var *var);
void convert_floor_colors(t_var *var);
void convert_ceilling_colors(t_var *var);

void init_texture_img(t_var *var);
#endif