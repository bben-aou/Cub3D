# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 11:06:04 by bben-aou          #+#    #+#              #
#    Updated: 2022/11/15 20:15:51 by iomayr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
NAME_BONUS = Cub3d_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx 

src =   main.c \
	  ./get_next_line/get_next_line.c \
	  ./get_next_line/get_next_line_utils.c \
	  ./utils/ft_utiles.c \
	  ./utils/ft_multisplit.c \
	  ./utils/ft_split.c \
	  ./utils/ft_strdup.c \
	  ./Parcing/ft_malloc.c \
	  ./Parcing/ft_check_textures.c \
	  ./Parcing/ft_rgb.c \
	  ./Parcing/ft_check_f_c.c \
	  ./Parcing/ft_init.c \
	  ./Parcing/utils_check.c \
	  ./Parcing/ft_parcing.c \
	  ./Utils_parcing/utiles_libft.c \
	  ./Utils_parcing/ft_split_brahim.c \
	  ./Parcing/read_map.c \
	  ./Parcing/check_map.c \
	  ./Parcing/check_utiles.c \
	  ./player_moves/normalize_angles.c \
	  ./player_moves/key_hook_release.c \
	  ./player_moves/check_pos_in_map.c \
	  ./player_moves/check_wall.c \
	  ./player_moves/key_actions.c \
	  ./player_moves/set_up_player_data.c \
	  ./raycasting/compare_distance.c \
	  ./raycasting/rendering_3d.c \
	  ./floor_and_ceilling/drawFloorAndCeilling.c \
	  ./raycasting/vert_intercept.c \
	  ./raycasting/horz_intercept.c \
	  ./raycasting/draw_texture.c \
	  ./raycasting/utiles_raycasting.c 

src_bonus = ./bonus/main_bonus.c \
			./bonus/get_next_lineb/get_next_line.c \
	  		./bonus/get_next_lineb/get_next_line_utils.c \
			./bonus/dda.c \
			./bonus/draw_mini_map.c \
	  		./bonus/utils/ft_utiles.c \
	  		./bonus/utils/ft_multisplit.c \
	  		./bonus/utils/ft_split.c \
	  		./bonus/utils/ft_strdup.c \
	  		./bonus/Parcing/ft_malloc.c \
	  		./bonus/Parcing/ft_check_textures.c \
	  		./bonus/Parcing/ft_rgb.c \
	  		./bonus/Parcing/ft_check_f_c.c \
	  		./bonus/Parcing/ft_init.c \
	  		./bonus/Parcing/utils_check.c \
	  		./bonus/Parcing/ft_parcing.c \
	  		./bonus/Utils_parcing/utiles_libft.c \
	  		./bonus/Utils_parcing/ft_split_brahim.c \
	  		./bonus/Parcing/read_map.c \
	  		./bonus/Parcing/check_map.c \
	  		./bonus/Parcing/check_utiles.c \
	  		./bonus/player_moves/normalize_angles.c \
	  		./bonus/player_moves/key_hook_release.c \
	  		./bonus/player_moves/check_pos_in_map.c \
	  		./bonus/player_moves/check_wall.c \
	  		./bonus/player_moves/key_actions.c \
	  		./bonus/player_moves/set_up_player_data.c \
	  		./bonus/raycasting/compare_distance.c \
	  		./bonus/raycasting/rendering_3d.c \
	  		./bonus/floor_and_ceilling/drawFloorAndCeilling.c \
	  		./bonus/raycasting/vert_intercept.c \
	  		./bonus/raycasting/horz_intercept.c \
	  		./bonus/raycasting/draw_texture.c \
	  		./bonus/raycasting/utiles_raycasting.c \
			./bonus/raycasting/show_mini_map.c \


	
HDRS = ./Cub3d.h \
	   ./bonus/cub3d_bonus.h \
	   ./get_next_line.h \
	   ./bonus/get_next_lineb\ get_next_line.h
	   
OBJ = $(src:.c=.o)
OBJB = $(src_bonus:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@cc $(CFLAGS) $^  -lmlx -framework OpenGL -framework AppKit -o $@
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"

bonus : $(OBJB)
	@cc $(CFLAGS) $(OBJB)  -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "\033[1;32m##########BONUS COMPILED SUCCESSFULY##########\033[0m"

%.o: %.c $(HDRS)
	@cc $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJB)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(OBJ)
	@rm -f $(OBJB)
	@echo "\033[1;32m##########CLEANED SUCCESSFULY##########\033[0m"

re: fclean all

.PHONY : all clean fclean re