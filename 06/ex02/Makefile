# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 17:28:29 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/27 18:11:48 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Identifier

SRCS = ./main.cpp \
	   ./A.cpp \
	   ./B.cpp \
	   ./C.cpp \
	   ./Base.cpp

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
