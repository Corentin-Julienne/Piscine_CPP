# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 18:36:01 by cjulienn          #+#    #+#              #
#    Updated: 2022/07/12 17:03:07 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRCS = ./main.cpp \
	   ./Fixed.cpp 

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean:
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
