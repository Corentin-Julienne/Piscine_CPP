# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 12:28:56 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/01 12:13:23 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = ./megaphone.cpp

OBJS = $(SRCS:.c=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) ./megaphone.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
