# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+     #
#    By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/30 00:11:00 by rhiguita          #+#    #+#              #
#    Updated: 2026/04/30 00:11:00 by rhiguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= array

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
