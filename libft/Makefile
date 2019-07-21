# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 15:02:47 by ommadhi           #+#    #+#              #
#    Updated: 2019/04/09 23:04:15 by ommadhi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OC = *.c\

OB = *.o\

NAME = libft.a

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(OC)
	ar rc libft.a $(OB)
clean :
	rm -f $(OB)
fclean : clean
	rm -f $(NAME)
re : fclean all

