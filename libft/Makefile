# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:40:03 by mbelorge          #+#    #+#              #
#    Updated: 2019/11/25 14:36:21 by mbelorge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c ft_strncmp.c \
ft_strdup.c ft_strlcat.c ft_memset.c \
ft_strlcpy.c ft_split.c ft_bzero.c \
ft_substr.c ft_strcat.c ft_calloc.c \
ft_read_tab_char.c duplicate_tab_char.c free_tab_char.c \

BONUS = $(SRC) ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c\
ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c  ft_lstmap_bonus.c

OBJ = $(subst .c,.o,$(SRC))
BONUS_OBJ = $(subst .c,.o,$(BONUS))
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

bonus :
	gcc $(CFLAGS) -c $(BONUS)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)


$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(BONUS_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
