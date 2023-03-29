# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 14:22:58 by ltressen          #+#    #+#              #
#    Updated: 2023/03/29 15:52:58 by ltressen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

NAME = push_swap.a

EXEC= push_swap
SRC = push.c \
	swap.c \
	main.c \
	memory.c
OBJ = ${SRC:.c=.o} 
	
all: $(NAME)  clean

$(NAME):
	make -C libft/
	mv libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJ}
	gcc ${FLAGS} ${SRC} ${NAME} -o ${EXEC}
	
clean:
	make clean -C libft/
	rm -f ${OBJ}

fclean:
	make clean -C libft/
	rm -f ${OBJ}
	rm -f ${NAME} ${EXEC}

re: fclean all
