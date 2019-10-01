# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:14:09 by vmanzoni          #+#    #+#              #
#    Updated: 2019/09/28 13:43:31 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls

SRC_PATH	=	./srcs/
OBJ_PATH	=	./objs/
INC_PATH	=	-I./includes/
LIB_DIR		=	./lib/

SRCS_NAME	=	main.c\
				ft_ls.c\
				ft_error.c

OBJS_NAME	=	$(SRCS:.c=.o)
LIB_NAME	=	#file.h

SRCS		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

LDFLAGS		=	libft/libft.a
LFT			=	-lft
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(CFLAGS)

all:	$(NAME)

$(NAME):
	@$(CC) $(LDFLAGS) $(SRCS) -c $(NAME)
	@$(CC) $(OBJS) -o $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)

lib:
	@make re -C./libft/

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

norme:
	norminette $(SRCS)

.PHONY: all clean fclean re norme
