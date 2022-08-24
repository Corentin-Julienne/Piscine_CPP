# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 18:32:18 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/10 16:05:52 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

SRCS = ./main.cpp \
	   ./Zombie.cpp \
	   ./newZombie.cpp \
	   ./randomChump.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
