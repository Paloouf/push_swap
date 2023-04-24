# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 14:22:58 by ltressen          #+#    #+#              #
#    Updated: 2023/04/24 15:37:51 by ltressen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

NAME = push_swap.a

EXEC= push_swap
SRC = push.c \
	swap.c \
	main.c \
	memory.c \
	rotate.c \
	r_rotate.c \
	algo.c \
	algo_v2.c \
	sorted.c \
	algo_v2_1.c \
	sorting.c \
	algo_utils.c \
	memory_utils.c
	
OBJ = ${SRC:.c=.o} 
	
all: $(NAME)

$(NAME): ${OBJ}
	make -C libft/
	mv libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJ}
	gcc ${FLAGS} -g ${SRC} ${NAME} -o ${EXEC}
	
clean:
	make clean -C libft/
	rm -f ${OBJ}

fclean:
	make clean -C libft/
	rm -f ${OBJ}
	rm -f ${NAME} ${EXEC}

re: fclean all
