# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 13:40:03 by mbelorge          #+#    #+#              #
#    Updated: 2020/06/10 14:36:21 by mbelorge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	pipex.c \
			execution.c \
			get_path.c \

NAME	= pipex

OBJS	= ${SRCS:.c=.o}

LIBFT	= libft/libft.a

CFLAGS	=	-Wall -Werror -Wextra -g
LOGFILE = $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`
MSG = auto save

%.o: %.c
		gcc $(CFLAGS) -o $@ -c $<

$(NAME):	${OBJS}
			make -C libft
			gcc -g -o $(NAME) $(OBJS) $(LIBFT)

all:		${NAME}

clean:
			rm -f ${OBJS}
			make clean -C libft

fclean:		clean
			rm -f ${NAME}
			make fclean -C libft

git : fclean
	@(make fclean -C libft)
	@(git add *)
	@(git commit -m "$(LOGFILE) : $(MSG)")
	@(git push)

re:			fclean all

.PHONY:		all clean fclean
