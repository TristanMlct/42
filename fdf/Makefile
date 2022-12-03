# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 21:40:35 by tmilcent          #+#    #+#              #
#    Updated: 2022/12/03 22:19:22 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

FLAGS	=	-Wall -Werror -Wextra

DIR_SRC	=	./
DIR_INC	=	./
DIR_OBJ	=	./objs/
DIR_LIB	=	./libft/
DIR_MLX	=	./mlx_linux/

SRCS_F	=	main.c draw_utils.c parsing.c utils.c init.c isometric.c

SRCS = $(addprefix $(DIR_SRC), $(SRCS_F))
OBJS = $(addprefix $(DIR_OBJ), $(SRCS_F:.c=.o))

LIBFT = $(addprefix $(DIR_LIB), libft.a)
LIB = -L $(DIR_LIB) -lft -Ift

MLX = $(addprefix $(DIR_MLX), libmlx_Linux.a)
INCMLX = -L $(DIR_MLX) -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

all				:	$(NAME)

$(NAME)			:	$(DIR_OBJ) $(LIBFT) $(OBJS) $(MLX)
					gcc $(OBJS) $(LIB) $(INCMLX) -o $(NAME)

$(DIR_OBJ)		:
					mkdir -p $(DIR_OBJ)

$(LIBFT)		:
					make a -C $(DIR_LIB)

$(DIR_OBJ)%.o	:	$(DIR_SRC)%.c
					gcc $(FLAGS) -I $(DIR_LIB) -I $(DIR_INC) -I $(DIR_MLX) -O3 -o $@ -c $<

clean			:
					rm -Rf $(DIR_OBJ)
					make -C $(DIR_LIB) clean

fclean			:	clean
					rm -f $(NAME)
					make -C $(DIR_LIB) fclean

re				:	fclean all
