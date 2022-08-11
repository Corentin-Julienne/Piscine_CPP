# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 12:22:51 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/11 15:37:44 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap

SRCS = ./main.cpp \
	   ./ClapTrap.cpp \
	   ./ScavTrap.cpp \
	   ./FragTrap.cpp

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
