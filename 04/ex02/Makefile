# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 15:11:10 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/31 15:13:44 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = VirtualAnimal

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

.c.o: $(CC) $(CFLAGS) -c $<

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
