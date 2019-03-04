# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:01:51 by jdiaz             #+#    #+#              #
#    Updated: 2018/10/07 18:34:14 by jdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  *.c

OBJ = *.o

all: $(NAME)

$(NAME): 
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)
	
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
