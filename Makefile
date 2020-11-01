# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 23:18:55 by louise            #+#    #+#              #
#    Updated: 2020/11/01 02:19:46 by louise           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libftprintf.a
SRC_DIR=	srcs/
SRC_FILES=	ft_printf.c \
			ft_printf_utils.c \
			parse_comb.c \
			print_fct.c \
			set_comb.c \
			conv_fct_int.c \
			conv_fct_uint.c \
			conv_fct_char.c \
			conv_fct_str.c \
			conv_fct_ptr.c \
			conv_fct_n.c \
			conv_fct_mod.c \
			process_fct.c \
			pf_itoa_base.c \
			setchar_unicode.c
OBJS=		${addprefix ${SRC_DIR},${SRC_FILES:.c=.o}}
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
HEAD=		-I includes -I libft
OBJS_LIBFT= ${OBJS} \
			libft/*.o

.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			make -C libft/
			ar -rcs ${NAME} ${OBJS_LIBFT}
all:		${NAME}
bonus:		${NAME}
clean:
			rm -f ${OBJS}
fclean: 	clean
			rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re
