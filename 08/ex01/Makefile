# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 15:30:16 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/29 15:30:46 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

SRCS = ./main.cpp \
	   ./Span.cpp

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
