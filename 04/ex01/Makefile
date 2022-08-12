# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 12:35:15 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/12 12:35:57 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain

SRCS = ./main.cpp \
	   ./Animal.cpp \
	   ./Cat.cpp \
	   ./Dog.cpp \
	   ./Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
