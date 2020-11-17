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
			conv_fct_other.c \
			process_fct.c \
			pf_itoa_base.c \
			setchar_unicode.c
OBJS=		${addprefix ${SRC_DIR},${SRC_FILES:.c=.o}}
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
LIBFT=		libft.a
LIBDIR=		libft
HEAD=		-I includes -I ${LIBDIR}

.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			make -C ${LIBDIR}
			cp ${LIBDIR}/${LIBFT} ${NAME}
			ar -vrc ${NAME} ${OBJS}
all:		${NAME}
bonus:		${NAME}
clean:
			make fclean -C ${LIBDIR}
			rm -f ${OBJS}
fclean: 	clean
			rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re bonus
