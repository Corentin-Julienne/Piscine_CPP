# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 18:32:18 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/04 16:45:45 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

SRCS = ./main.cpp \
	   ./Zombie.cpp \
	   ./newZombie.cpp \
	   ./randomChump.cpp

OBJS = $(SRCS:.c=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

fclean:
	rm $(NAME)

re:	fclean all

.PHONY: all clean fclean re
