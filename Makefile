# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 11:06:04 by bben-aou          #+#    #+#              #
#    Updated: 2022/11/10 09:15:30 by bben-aou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
NAME_BONUS = cub3d_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx

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
	  ./raycasting/cast_rays.c \
	  ./raycasting/launch_rays.c \
	  ./raycasting/rendering3D.c \
	  ./raycasting/rendering_walls.c \
	  ./FoorAndCeilling/drawFloorAndCeilling.c \

src_bonus = ./bonus/cub3d_bonus.c \
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
			./bonus/direction_line.c \
			./bonus/draw_mini_map.c \
			./bonus/showMiniMap.c \
			./bonus/renderingToolsBonus.c \
			./bonus/plyaerToolsBonus.c \
			./bonus/playerHookBonus.c \ 


	
HDRS = ./Cub3d.h \
	   ./get_next_line.h \
	   ./bonus/cub3d_bonus.h \
	   
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