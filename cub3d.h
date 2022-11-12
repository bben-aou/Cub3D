/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:45:57 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/12 17:34:04 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CUB3D
#define H_CUB3D

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <mlx.h> 
# include <math.h>
# include <limits.h>
# include <stdbool.h>

# include "./get_next_line/get_next_line.h"

#define TILE_SIZE 32
#define SCALE_MINI_MAP 0.2

typedef struct s_img
{
	void	*img;
	int     *addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img_txt;

typedef struct s_img_txt
{
	void	*img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

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
} t_mlx;

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
} t_player;


typedef struct s_keyPressed
{
    int keyW;
    int keyS;
    int keyD;
    int keyA;
    int keyTurnLeft;
    int keyTurnRight;

} t_keyPressed;

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
    double  horizontalWallHitX;
    double  horizontalWallHitY;
    bool     horz_wall_found;

    //  ------------- vertical variables -------------- //
    double  vert_wall_hit_x;
    double  vert_wall_hit_y;
    double  x_vert_intercept;
    double  y_vert_intercept;
    double  x_vert_step;
    double  y_vert_step;
    double  verticDistance;
    bool     vert_wall_found;
    bool  	wasHitVertical;

	double 	wall_height;
    double  distance;

	double offset_x;
	double offset_y;

	int		p_color;

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
    t_img_txt	*img;
    char		*id;
    char		*path;
	int			width_txt;
	int			height_txt;
    int			onlyOne;
} t_textureData;

typedef struct s_texture
{
    t_textureData   *north_texture;
    t_textureData   *west_texture;
    t_textureData   *south_texture;
    t_textureData   *east_texture;

} t_texture;

typedef struct s_floorData
{
    char    id;
    int     *color;
    int     onlyF;
}  t_floorData;

typedef struct s_ceillibData
{
    char    id;
    int     *color;
    int     onlyC;
}  t_ceillibData;    

typedef struct s_colors
{
    char    *hex_color;
    char    *r_hex;
    char    *g_hex;
    char    *b_hex;
    int     i;
} t_colors;

typedef struct s_var
{
    int              fd;
    char            *tmp;
    char            **tmpMap;
    char            **tmpRgb;
    char            **map;
    int             components;
    int             status;
    t_mlx           * mlx;
    t_player        *player;
    t_texture       *texture;
    t_floorData     *floor;
    t_ceillibData   *ceilling;
    t_keyPressed    *keyPerssed;
    t_raycasting    *ray;
    t_view          *view;
    t_colors        *clrf;
    t_colors        *clrc;

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
	// ----------------- TExture ------------------ //
	void	*n_texture;
	void	*s_texture;
	void	*e_texture;
	void	*w_texture;

} t_var;


    //  ================ init functions ================//

void    ft_allocation_var(t_var *var);
void    ft_init_textures_var(t_var *var);
void    ft_init_raycasting_var(t_var *var);
void    ft_init_facing_var(t_var *var);
void    ft_init(t_var *var);
void    initKeys(t_var *var);
void	initialize_data(t_var *var);
void    getAngleValue(char c, t_var *var);
void    getPlayerPosition(t_var *var ,int x, int y);

    //  ================ parcing textures and Ceilling/Floot functions ================//
void    ft_whichId(t_var *var);
void    storeDataTexture(t_var *var);
void    ft_validValue(int nbr);
void    ft_checkValidRgb(t_var *var);
void    ft_splitConvertRgb(t_var *var);
void    storeDataFloorCeilling(t_var *var);
void    ft_calculComponents(t_var *var);
void    ft_checkTextures(t_var *var);
void    ft_checkFloorCeilling(t_var *var);
void    ft_checkDoubleId(t_var *var);
void    ft_check_id(t_var *var);
void    ft_read(t_var *var);
void    ft_readAndCheck(t_var   *var);
void    ft_parcing(t_var *var, char *str);

    //  ================ free functions ================//
void    ft_freeArray2d(char **arr);

    //  ================ rading , parcing and checking Map :  ================//
void	read_map(t_var *var);
int     checkMapSrat(char *str);
void    check_map(t_var *var);
void    check_lines(t_var *var);
void    check_walls(t_var *var);
void    handle_space_in_lines(t_var *var, int x, char *str);
void    check_line_size(t_var *var, int y);
void    check_char(t_var *var, int y, int x);
void    handle_space_inside_map(t_var *var, int y, int x);

    //  ================ message functions ================//
void    ft_messageError(char *msg);
void    error_mapB(char *msg, t_var *var);



    //  ================ Raycasting functions ================//
void    getIntersectionHorizontal(t_var *var);
double  getHorizDistance(t_var *var);
double  getVerticDistance(t_var *var);
void    getIntersectionVertical(t_var *var);

    //  ================ rendring 3D functions ================//
int    reprint_map(void *var);
void    set_map_size(t_var *var);
void    rendering3D(t_var *var);








    //  ---------------   Bilal Part   ------------- //

int     ft_strlen1(const char *str);
char	*ft_strdup(char *src, int j);
char	**ft_split(char const *s, char c);
char	**ft_multisplit(char *str, char *charset);
char	*ft_strtrim(char  *s1, char const *set);
int     ft_strcmp(char *s1, char *s2);
int     ft_atoi(const char *str);
void    ft_messageError(char *msg);
void    ft_creatFd(t_var *var, char *str);
void    ft_readingData(t_var *var);
void    ft_parcing(t_var *var, char *str);
int     ft_check_extension(char *str);
void    ft_readAndCheck(t_var   *var);
void    ft_read(t_var *var);
void    ft_check_id(t_var *var);
void    ft_checkTextures(t_var *var);
void    ft_calculComponents(t_var *var);
void    storeDataFloorCeilling(t_var *var);
void    ft_splitConvertRgb(t_var *var);
void    ft_validValue(int nbr);
void    storeDataTexture(t_var *var);
void    ft_whichId(t_var *var);
void    ft_freeArray2d(char **arr);
void    ft_splitConvertRgb(t_var *var);
char	*mystrdup(char *src);

     //    ............... The mlx and player functions ...............

int     cross(t_var *var);
void    setUpPlayer(t_var *var);
int     key_hook(int key,t_var *var);
int     key_release(int key, t_var *var);

int key_mini_map_hook(int key,t_var *var);
int	key_release_mp(int key,t_var *var);

 //    ............... The setUp function of player  ...............

void    drawAll(t_var *var);
void    updatePlayerData(t_var *var);
void    setUpAll(t_var *var);
void    updateAll(t_var *var);
void	drawLine(t_var *var);

    //  -----------    Brahim part    -----------  //



/**************Utiles Function****************/
char    **ft_splitB(char *s, char c);
int     ft_strlen(char const *str);
char    *ft_strdupB(char *str);
int     ft_strcmpB(char *str, char *ptr);
void    error_mapB(char *msg, t_var *var);
/**************Check_Map Functions************/
void    check_map(t_var *var);
// char	*get_next_lineB(int fd, t_var *var);
void    initialize_data(t_var *var);
void    read_map(t_var *var);
// int     ft_strlen(char const *str);
char    *ft_strdupB(char *str);
int     ft_strcmpB(char *str, char *ptr);
void    error_mapB(char *msg, t_var *var);
void    check_map(t_var *var);
void    check_line_size(t_var *var, int y);
void    check_char(t_var *var, int y, int x);
void    handle_space_inside_map(t_var *var, int y, int x);
void    check_lines(t_var *var);
void    handle_space_in_lines(t_var *var, int x, char *str);
void    check_walls(t_var *var);
int     checkMapSrat(char *str);
/**************Print map Function****************/
void    ft_draw_map(t_var *var);
void	draw_direction_line(t_var *var, int x, int y);
void    my_img_pix_put(t_var *var, int x, int y, int color);




void	drawLine2(t_var *var);
void draw_map(t_var *var);
void draw_player2(t_var *var);
void    keyPressedAction(t_var *var);
void    initKeys(t_var *var);



void    setUpRay(t_var *var);
void    raycatsing(t_var *var);
void    normalizingRayAngle(t_var *var);
void    normilizeAngle(t_var *var);




void ddrawline(t_var *var);


void	drawWall(double x1, double y1, double y2, double x2,t_var *var);
void    rendering_walls(t_var *var);


void my_img_pix_put2(t_var *var, int x, int y, int color);
void drawCeillingFloor(t_var *var);
void    initMapImg(t_var *var);

void compare_distance(t_var *var);
void draw_texture(t_var *var, int id);

// void draw_map1(t_var *var);
// void draw_cube1(t_var *var, int width, int height, char *color);
// double  getDistanceMiniMap(t_var *var, double xCenter, double yCenter);
// void draw_mini_map(t_var *var, double distance);
// void    drawMiniMap(t_var *var);




// void	my_mlx_pixel_put(t_var *var, int x, int y, int color);
// void    ft_block2(t_var *var, double x, double y, int color)
// int draw_minimap(t_var *var);

 int    draw_minimap(t_var *var);

 bool   check_if_wall(t_var *var, int next_x, int next_y);
 void   ft_init_colors(t_var *var);
void    convert_floor_colors(t_var *var);
void    convert_ceilling_colors(t_var *var);

void init_texture_img(t_var *var);
#endif