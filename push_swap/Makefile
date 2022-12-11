# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 21:40:35 by tmilcent          #+#    #+#              #
#    Updated: 2022/12/11 15:51:47 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
FLAGS	=	-Wall -Werror -Wextra -fsanitize=address

DIR_SRC	=	./
DIR_INC	=	./
DIR_OBJ	=	./objs/
DIR_LIB	=	./libft/

SRCS_F	=	push_swap.c args.c error.c utils.c pile_utils.c swap_utils.c \
			push_utils.c rotate_utils.c rev_rotate_utils.c algo_utils.c  \
			other_algo.c

SRCS = $(addprefix $(DIR_SRC), $(SRCS_F))
OBJS = $(addprefix $(DIR_OBJ), $(SRCS_F:.c=.o))
LIBFT = $(addprefix $(DIR_LIB), libft.a)
LIB = -L $(DIR_LIB) -lft

all				:	$(NAME)

$(NAME)			:	$(DIR_OBJ) $(LIBFT) $(OBJS)
					gcc -fsanitize=address $(OBJS) $(LIB) -o $(NAME)

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
					rm -f $(NAME)
					make -C $(DIR_LIB) fclean

re				:	fclean all
