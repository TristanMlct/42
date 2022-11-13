# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 21:05:27 by tmilcent          #+#    #+#              #
#    Updated: 2022/11/13 12:59:59 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRINC	=	./includes/

DIRLIB	=	./libft/

SRCS	=	ft_printf.c utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

NAMELIB	=	libft.a

$(NAME)		:	
				$(MAKE) a -C $(DIRLIB)
				cp $(DIRLIB)$(NAMELIB) $(NAME)
				cp $(DIRLIB)$(NAMELIB:.a=.h) $(DIRINC)
				$(CC) $(CFLAGS) -c $(SRCS)
				ar -rcs $(NAME) $(OBJS)	

all			:	$(NAME)

clean		:
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${NAME}

re			:	fclean ${NAME}

a			:	all clean
