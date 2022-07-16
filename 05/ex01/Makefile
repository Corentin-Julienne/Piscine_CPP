# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 16:13:21 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/15 16:16:24 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Forms

SRCS = ./main.cpp \
	   ./Bureaucrat.cpp

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
