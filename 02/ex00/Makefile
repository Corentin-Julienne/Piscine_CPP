# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 18:36:01 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/12 16:15:12 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = first_cannon

SRCS = ./main.cpp \
	   ./Fixed.cpp 

OBJS = $(SRCS:.c=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98

RM = rm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

fclean:
	$(RM) $(NAME)

re:	fclean all

.PHONY: all fclean re
