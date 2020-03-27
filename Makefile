##
## EPITECH PROJECT, 2020
## PSU_tetris_2019
## File description:
## Makefile
##

CC			=	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
MAIN_F		=	main.c
OBJ_M		=	$(MAIN:.c=.o)

SRC			=	$(addprefix $(SRC_D), $(SRC_F))
OBJ			=	$(SRC:.c=.o)
SRC_D		=	src/
SRC_F		=	tetris.c \
				ncurses_init.c \
				clear_zone.c \
				get_tetriminos_from_dir.c \
				display_next_tetrimino.c \
				display_box.c \
				display_game_info.c \
				options/print_help.c \
				file_reading/get_file_buffer.c \
				file_reading/get_file_lines.c \
				file_reading/get_file_size.c \
				file_reading/get_nb_files_in_dir.c \
				file_reading/get_pretty_filename.c \
				structures/game/game_create.c \
				structures/game/game_info_create.c \
				structures/game/game_destroy.c \
				structures/grid/grid_create.c \
				structures/grid/grid_destroy.c \
				structures/grid/grid_display.c \
				structures/grid/grid_put_tetrimino.c \
				structures/tetrimino/tetrimino_create.c \
				structures/tetrimino/tetrimino_create_from_file.c \
				structures/tetrimino/tetrimino_dup.c \
				structures/tetrimino/tetrimino_destroy.c \
				structures/tetrimino/tetrimino_can_fall.c \
				structures/tetrimino/tetrimino_move.c \
				structures/tetrimino/tetrimino_display.c \
				structures/tetrimino/tetrimino_shape_create.c \
				structures/tetrimino/tetrimino_shape_dup.c \

SRC_UT		=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT		=	$(SRC_UT:.c=.o)
SRC_UT_D	=	tests/
SRC_UT_F	=

INC			=	-I./include -I./include/enumerations -I./include/structures

CFLAGS		=	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS)

LDFLAGS		=	-L./lib -lmy -lncurses

LDFLAGS_UT  =	-lcriterion --coverage

DBFLAGS		=	-g -g3 -ggdb

NAME		=	tetris

NAME_UT		=	unit_tests

all: $(NAME)

$(NAME): makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS)

tests_run: makelib clean $(SRC) $(OBJ_UT)
	$(CC) -o $(NAME_UT) $(SRC) $(OBJ_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)

makelib:
	make -C ./lib/my all

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my fclean

re: fclean all