# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 09:55:24 by cjulienn          #+#    #+#              #
#    Updated: 2023/03/16 09:55:35 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRCS = ./main.cpp \
	   ./RPN.cpp

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
