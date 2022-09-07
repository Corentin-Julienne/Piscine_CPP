# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 12:35:15 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/31 11:32:03 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain

SRCS = ./main.cpp \
	   ./Animal.cpp \
	   ./Cat.cpp \
	   ./Dog.cpp \
	   ./Brain.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98

.cpp.o: 
	$(CC) $(CFLAGS) -c $<

OBJS = $(SRCS:.cpp=.o)

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

re:	fclean $(NAME)

.PHONY: all clean fclean re
