# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 21:40:35 by tmilcent          #+#    #+#              #
#    Updated: 2022/11/30 15:01:07 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S	=	server
NAME_C	=	client

FLAGS	=	-Wall -Werror -Wextra

DIR_SRC	=	./
DIR_INC	=	./
DIR_OBJ	=	./objs/
DIR_LIB	=	./libft/

SRCS_F_S	=	server.c
SRCS_F_C	=	client.c

SRCS_S = $(addprefix $(DIR_SRC), $(SRCS_F_S))
OBJS_S = $(addprefix $(DIR_OBJ), $(SRCS_F_S:.c=.o))

SRCS_C = $(addprefix $(DIR_SRC), $(SRCS_F_C))
OBJS_C = $(addprefix $(DIR_OBJ), $(SRCS_F_C:.c=.o))

LIBFT = $(addprefix $(DIR_LIB), libft.a)
LIB = -L $(DIR_LIB) -lft

all				:	$(NAME_S) $(NAME_C)

$(NAME_C)		:	$(DIR_OBJ) $(LIBFT) $(OBJS_C)
					gcc $(OBJS_C) $(LIB) -o $(NAME_C)

$(NAME_S)		:	$(DIR_OBJ) $(LIBFT) $(OBJS_S)
					gcc $(OBJS_S) $(LIB) -o $(NAME_S)

$(DIR_OBJ)		:
					mkdir -p $(DIR_OBJ)

$(LIBFT)		:
					make a -C $(DIR_LIB)

$(DIR_OBJ)%.o	:	$(DIR_SRC)%.c
					gcc $(FLAGS) -I $(DIR_LIB) -I $(DIR_INC) -o $@ -c $<

clean			:
					rm -Rf $(DIR_OBJ)
					make -C $(DIR_LIB) clean

fclean			:	clean
					rm -f $(NAME_S)
					rm -f $(NAME_C)
					make -C $(DIR_LIB) fclean

re				:	fclean all
