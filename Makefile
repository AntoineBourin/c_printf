#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 13:55:47 by abourin           #+#    #+#              #
#    Updated: 2019/10/18 17:40:09 by abourin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = srcs/ft_printf.c \
	srcs/ft_itoa_hex.c \
	srcs/ft_utils.c \
	srcs/ft_conv_flags_valid.c \
	srcs/ft_process_flags.c \
	srcs/ft_atoi.c \
	srcs/ft_strlen.c \
	srcs/ft_replace_identifier.c \
	srcs/ft_buffer_display.c \
	srcs/ft_process_conversion.c \
	srcs/ft_dispatcher.c \
	srcs/ft_convert_c.c \
	srcs/ft_convert_s.c \
	srcs/ft_convert_p.c \
	srcs/ft_itoa.c \
	srcs/ft_convert_d_i.c \
	srcs/ft_convert_u.c \
	srcs/ft_uitoa.c \
	srcs/ft_convert_x.c \
	srcs/ft_uitoa_base.c \
	srcs/ft_convert_n.c \
	srcs/ft_ftoa.c \
	srcs/ft_convert_f.c \
	srcs/ft_strjoin_free.c \
	srcs/ft_convert_percent.c \
	srcs/ft_strdup.c \

OBJS = ${SRCS:.c=.o}

RM = rm -f

NAME = libftprintf.a

CC = GCC

CFLAGS = -Wall -Wextra -Werror

.c .o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

all: ${NAME}

bonus: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re