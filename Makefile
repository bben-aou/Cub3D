# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 11:06:04 by bben-aou          #+#    #+#              #
#    Updated: 2022/11/11 16:14:03 by iomayr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
NAME_BONUS = cub3d_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address 

src =   main.c \
	  ./get_next_line/get_next_line.c \
	  ./get_next_line/get_next_line_utils.c \
	  ./utils/ft_atoi.c \
	  ./utils/ft_checkExtension.c \
	  ./utils/ft_multisplit.c \
	  ./utils/ft_split.c \
	  ./utils/ft_strcmp.c \
	  ./utils/ft_strlen.c \
	  ./utils/ft_strdup.c \
	  ./utils/messages.c \
	  ./Parcing/ft_parcing.c \
	  ./Utils_parcing/utiles_libft.c \
	  ./Utils_parcing/ft_splitBrahim.c \
	  ./Parcing/readMap.c \
	  ./Parcing/check_map.c \
	  ./player_moves/playerHookCheck.c \
	  ./player_moves/playerTools.c \
	  ./raycasting/compare_distance.c \
	  ./raycasting/rendering3D.c \
	  ./FoorAndCeilling/drawFloorAndCeilling.c \
	  ./raycasting/vert_intercept.c \
	  ./raycasting/horz_intercept.c \
	  ./raycasting/draw_texture.c \

src_bonus = ./bonus/cub3d_bonus.c \
			./get_next_line/get_next_line.c \
	        ./get_next_line/get_next_line_utils.c \
	        ./bonus/utils/ft_atoi.c \
	        ./bonus/utils/ft_checkExtension.c \
	        ./bonus/utils/ft_multisplit.c \
	        ./bonus/utils/ft_split.c \
	        ./bonus/utils/ft_strcmp.c \
	        ./bonus/utils/ft_strlen.c \
	        ./bonus/utils/ft_strdup.c \
	        ./bonus/utils/messages.c \
	        ./bonus/Utils_parcing/utiles_libft.c \
	        ./bonus/Utils_parcing/ft_splitBrahim.c \
	        ./bonus/ft_parcing_bonus.c \
	        ./bonus/readMap_bonus.c \
	        ./bonus/check_map_bonus.c \
			./bonus/direction_line_bonus.c \
			./bonus/draw_mini_map_bonus.c \
			./bonus/drawFloorAndCeilling_bonus.c \
			./bonus/showMiniMap.c \
			./bonus/renderingToolsBonus.c \
			./bonus/playerToolsBonus.c \
			./bonus/playerHookBonus.c \
			./bonus/cast_rays_bonus.c \


	
HDRS = ./Cub3d.h \
	   ./bonus/cub3d_bonus.h \
	   ./get_next_line.h \
	   
OBJ = $(src:.c=.o)
OBJB = $(src_bonus:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $^  -lmlx -framework OpenGL -framework AppKit -o $@
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"

bonus : $(OBJB)
	@gcc $(CFLAGS) $(OBJB)  -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "\033[1;32m##########BONUS COMPILED SUCCESSFULY##########\033[0m"

%.o: %.c $(HDRS)
	@gcc $(CFLAGS) -c $< -o $@ 

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