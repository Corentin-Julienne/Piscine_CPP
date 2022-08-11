# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:05:44 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/11 15:38:25 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap

SRCS = ./main.cpp \
	   ./ClapTrap.cpp \
	   ./ScavTrap.cpp

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
