# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdubois <fdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 01:06:47 by fdubois           #+#    #+#              #
#    Updated: 2018/11/07 17:10:03 by fdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

$(NAME):
	$(CC) -c *.c
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o
	
fclean: clean
	rm -f $(NAME)
	rm -f libft.so

re: fclean all

so:
	$(CC) -fPIC *.c -shared -o libft.so
