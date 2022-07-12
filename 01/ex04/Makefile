# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 12:19:26 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/05 17:22:59 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace_cpp

SRCS = ./main.cpp

OBJS = $(SRCS:.c=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

fclean:
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
