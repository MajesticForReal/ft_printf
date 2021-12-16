# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 20:01:46 by anrechai          #+#    #+#              #
#    Updated: 2021/12/16 20:38:43 by anrechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c \
				ft_print_it.c \
				ft_print_it_2.c \
				ft_utils.c

OBJS		=	${SRCS:.c=.o}

NAME		=	libftprintf.a

HEADER		=	ft_printf.h

.c.o:
			gcc -Wall -Wextra -Werror -c $< -o $@ -I./
			@echo "\033[92mstatus ${<:.c=.o} is [OK]\033[0m"

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			@echo "\033[92mstatus ${NAME} is [OK]\033[0m"

all:		${NAME}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

clean:
			rm -f ${OBJS} ${OBJS_BONUS}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

fclean:		clean
			rm -f ${NAME}
			@echo "\033[92mstatus $@ [OK]\033[0m"

re:			fclean all
			@echo "\033[92mstatus $@ [OK]\033[0m"

.PHONY:		fclean clean re all bonus
