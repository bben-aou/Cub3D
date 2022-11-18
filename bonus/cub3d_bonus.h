/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:59:04 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:14:59 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

# include "./get_next_lineb/get_next_line.h"

# define T_S 32

typedef struct s_imgb
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imgb_txtb;

typedef struct s_img_txtb
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imgb;

typedef struct s_mlxb
{
	void	*init;
	void	*win;
	t_imgb	img;
	t_imgb	*full_img;
	t_imgb	*mini_map;
	int		max_len;
	int		width;
	int		height;
}	t_mlxb;

typedef struct s_playerb
{
	double	x;
	double	y;
	double	size_player;
	int		turn_left_right;
	int		walk_back_forward;
	double	rotatin_angle;
	double	move_speed;
	double	move_step;
	double	rotation_speed;
}	t_playerb;

typedef struct s_key_pressedb
{
	int	key_w;
	int	key_s;
	int	key_d;
	int	key_a;
	int	key_turn_left;
	int	key_turn_right;
}	t_key_pressedb;

typedef struct s_raycastingb
{
	double	fov;
	double	ray_angle;
	double	y_wall_hit;
	double	x_wall_hit;
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;
	double	horz_distance;
	double	horz_wall_hit_x;
	double	horz_wall_hit_y;
	bool	horz_wall_found;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	double	x_vert_intercept;
	double	y_vert_intercept;
	double	x_vert_step;
	double	y_vert_step;
	double	vert_distance;
	bool	vert_wall_found;
	bool	was_hit_vert;
	double	wall_height;
	double	distance;
	double	offset_x;
	double	offset_y;
	int		p_color;
	double	wall_top;
	double	wall_bottom;
}	t_raycastingb;

typedef struct s_viewb
{
	int	facing_up;
	int	facing_down;
	int	facing_right;
	int	facing_left;
}	t_viewb;

typedef struct s_txtb_datab
{
	t_imgb_txtb	*img;
	char		*id;
	char		*path;
	int			width_txt;
	int			height_txtb;
	int			only_one;
}	t_txtb_datab;

typedef struct s_txtb
{
	t_txtb_datab	*n_txt;
	t_txtb_datab	*w_txt;
	t_txtb_datab	*s_txt;
	t_txtb_datab	*e_txt;
}	t_txtb;

typedef struct s_floorDatab
{
	char	id;
	int		*color;
	int		only_f;
	int		f_color;
}	t_floor_datab;

typedef struct s_ceillibDatab
{
	char	id;
	int		*color;
	int		only_c;
	int		c_color;
}	t_ceillib_datab;

typedef struct s_mouse
{
	int	x_mouse;
	int	y_mouse;
	int	mouse_move;
	int	mouse_stable;
}	t_mouse;

typedef struct s_dda
{
	double	delta_x;
	double	delta_y;
	double	new_x;
	double	new_y;
	double	step;
	double	xr;
	double	yr;
}	t_dda;

typedef struct s_varb
{
	int				fd;
	char			*tmp;
	char			**tmp_map;
	char			**tmp_rgb;
	char			**map;
	int				components;
	int				status;
	t_mlxb			*mlx;
	t_playerb		*player;
	t_txtb			*txt;
	t_floor_datab	*floor;
	t_ceillib_datab	*ceilling;
	t_key_pressedb	*key_pressed;
	t_raycastingb	*ray;
	t_viewb			*view;
	t_mouse			mouse;
	t_dda			dda_data;
	int				mini_map_hook;
	char			**id_textures;
	int				count_line;
	char			*buff;
	char			*save;
	char			*map_in_line;
	int				count_playerb;
	int				nothing;
	void			*n_txt;
	void			*s_txt;
	void			*e_txt;
	void			*w_txt;
}	t_varb;

int		reprint_map(void *var);
void	draw_all(t_varb *var);
int		crossb(t_varb *var);
void	ft_msg_errorb(char *msg, t_varb *var);
void	ft_initb(t_varb *var);
void	init_keysb(t_varb *var);
void	ft_parcingb(t_varb *var, char *str);
void	set_map_sizeb(t_varb *var);
void	set_up_allb(t_varb *var);
int		create_rgbb(int r, int g, int b);
void	init_txtb_imgb(t_varb *var);
int		key_hookb(int key, t_varb *var);
int		key_releaseb(int key, t_varb *var);
double	get_horz_distanceb(t_varb *var);
double	get_vert_distanceb(t_varb *var);
void	compare_distanceb_hereb(t_varb *var);
void	compare_distanceb(t_varb *var);
void	calcul_xoffsetb(t_varb *var);
void	get_color_from_txtb(t_varb *var);
void	draw_txtb(t_varb *var, int id);
void	calcul_steps_hb(t_varb *var);
void	calcul_intercept_steps_hb(t_varb *var, double *next_x, double *next_y);
void	get_intersectionb_horzb(t_varb *var);
void	facing_up_downb(t_varb *var);
void	facing_right_leftb(t_varb *var);
void	get_intersectionb(t_varb *var);
void	calcul_for_3db(t_varb *var);
void	rendering_3db(t_varb *var);
bool	check_if_wallb(t_varb *var, int next_x, int next_y);
void	my_img_pix_putb(t_varb *var, int x, int y, int color);
void	init_rest_of_txtsb(t_varb *var);
void	calcul_steps_vb(t_varb *var);
void	calcul_intercept_steps_vb(t_varb *var, double *next_x, double *next_y);
void	get_intersectionb_vertb(t_varb *var);
int		check_wallb_case1b(t_varb *var, int *ps_x, int *ps_y);
int		check_wallb(t_varb *var, int status);
void	check_wallb_forwardb(t_varb *var, int *ps_x, int *ps_y);
void	check_wallb_backb(t_varb *var, int *ps_x, int *ps_y);
void	check_wallb_right_sideb(t_varb *var, int *ps_x, int *ps_y);
void	check_wallb_left_sideb(t_varb *var, int *ps_x, int *ps_y);
void	wall_statusb(t_varb *var, int status, int *ps_x, int *ps_y);
void	move_forwardb(t_varb *var);
void	move_backb(t_varb *var);
void	move_right_sideb(t_varb *var);
void	move_left_sideb(t_varb *var);
void	key_pressed_actionb(t_varb *var);
void	key_releaseb_part1b(int key, t_varb *var);
int		key_releaseb(int key, t_varb *var);
void	normalize_angleb(t_varb *var);
void	normalizingray_angleb(t_varb *var);
void	handle_space_inside_mapb(t_varb *var, int y, int x);
void	check_line_sizeb(t_varb *var, int y);
void	get_angle_valueb(char c, t_varb *var);
void	check_charb(t_varb *var, int y, int x);
void	check_mapb(t_varb *var);
void	get_playerb_postionb(t_varb *var, int x, int y);
void	check_last_lineb(t_varb *var, int x);
void	check_wallbsb(t_varb *var);
void	handle_space_in_linesb(t_varb *var, int x, char *str);
void	check_linesb(t_varb *var);
void	ft_check_floor_ceilblingb(t_varb *var, int *valid_id);
void	ft_check_floor_ceilb(t_varb *var);
void	store_data_floor_ceilb(t_varb *var);
void	ft_check_double_idb(t_varb *var);
void	ft_check_txtsb(t_varb *var);
void	store_data_txtb(t_varb *var);
void	ft_calcul_componentsb(t_varb *var);
void	ft_freeb_array2db(char **arr);
void	ft_freeb_part1b(t_varb *var);
void	ft_freeb_part2b(t_varb *var);
void	ft_freeb(t_varb *var);
void	ft_initb_txtbs_varb(t_varb *var);
void	ft_initb_raycastingb_varb(t_varb *var);
void	ft_initb_facing_varb(t_varb *var);
void	ft_initb(t_varb *var);
void	init_keysb(t_varb *var);
void	ft_malloc_texturesb(t_varb *var);
void	ft_malloc_f_cb(t_varb *var);
void	ft_malloc_imgb(t_varb *var);
void	ft_malloc_structb(t_varb *var);
void	ft_allocation_varb(t_varb *var);
void	ft_creat_fdb(t_varb *var, char *str);
void	ft_check_idb(t_varb *var);
void	ft_readb(t_varb *var);
void	ft_readb_and_checkb(t_varb *var);
void	ft_parcingb(t_varb *var, char *str);
void	ft_split_bonus_convert_rgbb_p1b(t_varb *var);
void	ft_split_bonus_convert_rgbb(t_varb *var);
void	ft_check_valid_rgb(t_varb *var);
void	initialize_datab(t_varb *var);
int		check_mapb_startb(char *str, t_varb *var);
void	read_mapb(t_varb *var);
int		count_commab(char *str);
int		create_rgbb(int r, int g, int b);

char	**ft_split_bonus_b(char *s, char c);
char	*ft_strdup_bonus_b(char *str);
int		ft_strcmp_bnb(char *str, char *ptr);
char	**ft_multisplitb(char *str, char *charset);
char	**ft_split_bonus(char const *s, char c);
char	*ft_strdup_bonus(char *src, int j);
char	*mystrdupb(char *src);
int		ft_atoi_b(const char *str);
int		ft_check_extensionb(char *str);
int		ft_strlenb(const char *str);
void	ft_msg_errorb(char *msg, t_varb *var);
int		ft_strcmp_bn(char *s1, char *s2);
void	dda_line(t_varb *var);
int		mouse_moves(int x, int y, t_varb *var);
int		ft_mouse_release(int mouse, int x, int y, t_varb *var);
int		mouse_hook(int mouse, int x, int y, t_varb *var);
void	my_img_pix_putb(t_varb *var, int x, int y, int color);
void	draw_cube(t_varb *var, int width, int height, char *color);
void	draw_player(t_varb *var);
void	draw_mini_map(t_varb *var);
void	error_map_b(char *msg, t_varb *var);
void	ft_valid_valueb(int nbr, t_varb *var);
void	ft_which_idb(t_varb *var);
void	draw_ceil_floorb(t_varb *var);
void	show_mini_map(t_varb *var);
#endif