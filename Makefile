#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 13:55:47 by abourin           #+#    #+#              #
#    Updated: 2019/10/11 15:47:42 by abourin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ft_printf.c ft_itoa_hex.c ft_utils.c ft_conv_flags_valid.c ft_process_flags.c ft_atoi.c ft_strlen.c ft_replace_identifier.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

NAME = ft_printf

CC = GCC

CFLAGS = -Wall -Wextra -Werror

.c .o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re