# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 19:22:08 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/04 16:52:41 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moar_brainz

SRCS = ./main.cpp \
	   ./Zombie.cpp \
	   ./ZombieHorde.cpp

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

.PHONY: all fclean re
