# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:32:56 by cjulienn          #+#    #+#              #
#    Updated: 2022/01/21 18:33:13 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lab_tester

SRCS = ./main.cpp \
	   ./Example.cpp 

OBJS = $(SRCS:.c=.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
