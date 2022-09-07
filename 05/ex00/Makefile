# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 12:19:05 by cjulienn          #+#    #+#              #
#    Updated: 2022/08/31 11:41:43 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

SRCS = ./main.cpp \
	   ./Bureaucrat.cpp

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
