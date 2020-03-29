##
## EPITECH PROJECT, 2019
## PSU_tetris_2019
## File description:
## Libmy Makefile
##

CC 		= 	gcc

SRC		=	my_count_char.c \
			my_atoi.c \
			my_pow.c \
			my_count_until_sep.c \
			my_free_str_array.c \
			my_putchar.c \
			my_putstr.c \
			my_puterr.c \
			my_strcpy.c \
			my_str_to_word_array.c \
			my_strdup.c \
			my_strtol.c \
			my_strlen.c \
			my_strcmp.c \
			my_strdupcat.c \
			my_strncmp.c \
			my_strcpy_a.c \
			str_to_word_tab.c\
			my_strdup_a.c\
			my_put_nbr.c\
			my_strcat.c \
			my_swap_int.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

DBFLAGS	=	-g -g3 -ggdb

HEADER	=	my.h

NAME	=	libmy.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
