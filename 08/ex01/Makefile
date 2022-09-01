# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 15:30:16 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/31 11:51:46 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

SRCS = ./main.cpp \
	   ./Span.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98

RM = rm -f

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
