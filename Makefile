# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 14:22:58 by ltressen          #+#    #+#              #
#    Updated: 2023/04/25 12:38:34 by ltressen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

NAME = push_swap.a

EXEC = push_swap
EXECB = checker

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

SRCB = checker.c \
	push.c \
	swap.c \
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
OBJB = ${SRCB:.c=.o}
	
all: $(NAME)

$(NAME): ${OBJ}
	make -C libft/
	mv libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJ}
	gcc ${FLAGS} -g ${SRC} ${NAME} -o ${EXEC}
	
bonus: ${OBJB}
	make -C libft/
	mv libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJB}
	gcc ${FLAGS} ${SRCB} ${NAME} -o ${EXECB}

clean:
	make clean -C libft/
	rm -f ${OBJ} ${OBJB}

fclean:
	make clean -C libft/
	rm -f ${OBJ} ${OBJB}
	rm -f ${NAME} ${EXEC} ${EXECB}

re: fclean all
