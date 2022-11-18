/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:45:57 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 18:52:58 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

# define T_S 32
# define SCALE_MINI_MAP 0.2

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img_txt;

typedef struct s_img_txt
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	t_img	img;
	t_img	*full_img;
	t_img	*mini_map;
	int		max_len;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_player
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
}	t_player;

typedef struct s_key_pressed
{
	int	key_w;
	int	key_s;
	int	key_d;
	int	key_a;
	int	key_turn_left;
	int	key_turn_right;
}	t_key_pressed;

typedef struct s_raycasting
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
}	t_raycasting;

typedef struct s_view
{
	int	facing_up;
	int	facing_down;
	int	facing_right;
	int	facing_left;
}	t_view;

typedef struct s_txtData
{
	t_img_txt	*img;
	char		*id;
	char		*path;
	int			width_txt;
	int			height_txt;
	int			only_one;
}	t_txt_data;

typedef struct s_txt
{
	t_txt_data	*n_txt;
	t_txt_data	*w_txt;
	t_txt_data	*s_txt;
	t_txt_data	*e_txt;
}	t_txt;

typedef struct s_floorData
{
	char	id;
	int		*color;
	int		only_f;
	int		f_color;
}	t_floorData;

typedef struct s_ceillibData
{
	char	id;
	int		*color;
	int		only_c;
	int		c_color;
}	t_ceillibData;

typedef struct s_var
{
	int				fd;
	char			*tmp;
	char			**tmp_map;
	char			**tmp_rgb;
	char			**map;
	int				components;
	int				status;
	t_mlx			*mlx;
	t_player		*player;
	t_txt			*txt;
	t_floorData		*floor;
	t_ceillibData	*ceilling;
	t_key_pressed	*key_pressed;
	t_raycasting	*ray;
	t_view			*view;
	char			**id_textures;
	int				count_line;
	char			*buff;
	char			*save;
	char			*map_in_line;
	int				count_player;
	int				nothing;
	void			*n_txt;
	void			*s_txt;
	void			*e_txt;
	void			*w_txt;
}	t_var;

int		reprint_map(void *var);
void	draw_all(t_var *var);
int		cross(t_var *var);
void	ft_msg_error(char *msg, t_var *var);
void	ft_init(t_var *var);
void	init_keys(t_var *var);
void	ft_parcing(t_var *var, char *str);
void	set_map_size(t_var *var);
void	set_up_all(t_var *var);
int		create_rgb(int r, int g, int b);
void	init_txt_img(t_var *var);
int		key_hook(int key, t_var *var);
int		key_release(int key, t_var *var);
double	get_horz_distance(t_var *var);
double	get_vert_distance(t_var *var);
void	compare_distance_here(t_var *var);
void	compare_distance(t_var *var);
void	calcul_xoffset(t_var *var);
void	get_color_from_txt(t_var *var);
void	draw_txt(t_var *var, int id);
void	calcul_steps_h(t_var *var);
void	calcul_intercept_steps_h(t_var *var, double *next_x, double *next_y);
void	get_intersection_horz(t_var *var);
void	facing_up_down(t_var *var);
void	facing_right_left(t_var *var);
void	get_intersection(t_var *var);
void	calcul_for_3d(t_var *var);
void	rendering_3d(t_var *var);
bool	check_if_wall(t_var *var, int next_x, int next_y);
void	my_img_pix_put2(t_var *var, int x, int y, int color);
void	init_rest_of_txts(t_var *var);
void	calcul_steps_v(t_var *var);
void	calcul_intercept_steps_v(t_var *var, double *next_x, double *next_y);
void	get_intersection_vert(t_var *var);
int		check_wall_case1(t_var *var, int *ps_x, int *ps_y);
int		check_wall(t_var *var, int status);
void	check_wall_forward(t_var *var, int *ps_x, int *ps_y);
void	check_wall_back(t_var *var, int *ps_x, int *ps_y);
void	check_wall_right_side(t_var *var, int *ps_x, int *ps_y);
void	check_wall_left_side(t_var *var, int *ps_x, int *ps_y);
void	wall_status(t_var *var, int status, int *ps_x, int *ps_y);
void	move_forward(t_var *var);
void	move_back(t_var *var);
void	move_right_side(t_var *var);
void	move_left_side(t_var *var);
void	key_pressed_action(t_var *var);
void	key_release_part1(int key, t_var *var);
int		key_release(int key, t_var *var);
void	normalize_angle(t_var *var);
void	normalizingray_angle(t_var *var);
void	handle_space_inside_map(t_var *var, int y, int x);
void	check_line_size(t_var *var, int y);
void	get_angle_value(char c, t_var *var);
void	check_char(t_var *var, int y, int x);
void	check_map(t_var *var);
void	get_player_postion(t_var *var, int x, int y);
void	check_last_line(t_var *var, int x);
void	check_walls(t_var *var);
void	handle_space_in_lines(t_var *var, int x, char *str);
void	check_lines(t_var *var);
void	ft_check_floor_ceilling(t_var *var, int *valid_id);
void	ft_check_floor_ceil(t_var *var);
void	store_data_floor_ceil(t_var *var);
void	ft_check_double_id(t_var *var);
void	ft_check_txts(t_var *var);
void	store_data_txt(t_var *var);
void	ft_calcul_components(t_var *var);
void	ft_free_array2d(char **arr);
void	ft_free_part1(t_var *var);
void	ft_free_part2(t_var *var);
void	ft_free(t_var *var);
void	ft_init_txts_var(t_var *var);
void	ft_init_raycasting_var(t_var *var);
void	ft_init_facing_var(t_var *var);
void	ft_init(t_var *var);
void	init_keys(t_var *var);
void	ft_malloc_textures(t_var *var);
void	ft_malloc_f_c(t_var *var);
void	ft_malloc_img(t_var *var);
void	ft_malloc_struct(t_var *var);
void	ft_allocation_var(t_var *var);
void	ft_creat_fd(t_var *var, char *str);
void	ft_check_id(t_var *var);
void	ft_read(t_var *var);
void	ft_read_and_check(t_var *var);
void	ft_parcing(t_var *var, char *str);
void	ft_split_convert_rgb_p1(t_var *var);
void	ft_split_convert_rgb(t_var *var);
void	ft_check_valid_rgb(t_var *var);
void	initialize_data(t_var *var);
int		check_map_start(char *str, t_var *var);
void	read_map(t_var *var);
int		count_comma(char *str);
int		create_rgb(int r, int g, int b);
void	ft_valid_value(int nbr, t_var *var);
char	**ft_split_b(char *s, char c);
char	*ft_strdup_b(char *str);
int		ft_strcmp_b(char *str, char *ptr);
char	**ft_multisplit(char *str, char *charset);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src, int j);
char	*mystrdup(char *src);
int		ft_atoi(const char *str);
int		ft_check_extension(char *str);
int		ft_strlen1(const char *str);
void	ft_msg_error(char *msg, t_var *var);
int		ft_strcmp(char *s1, char *s2);
void	error_map(char *msg, t_var *var);
void	ft_which_id(t_var *var);
void	draw_ceil_floor(t_var *var);

#endif