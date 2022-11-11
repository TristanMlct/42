# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 21:05:27 by tmilcent          #+#    #+#              #
#    Updated: 2022/11/12 00:18:44 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRINC	=	./includes/

DIRLIB	=	./libft/

SRCS	=	ft_printf.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

NAMELIB	=	libft.a

$(NAME)		:	
				$(MAKE) ab -C ./libft
				cp $(DIRLIB)$(NAMELIB) $(DIRINC)
				cp $(DIRLIB)libft.h $(DIRINC)
				$(CC) $(CFLAGS) -c -I$(DIRINC) -o$(SRCS:.c=.o) $(SRCS)
				$(CC) $(CFLAGS) -I$(DIRINC) $(SRCS) -o test
				ar -rcs $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${NAME}

re			:	fclean ${NAME}

a			:	all clean