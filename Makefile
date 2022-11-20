##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC				=		src/main.c 									\

OBJ 			= 		$(SRC:.c=.o)

NAME 			=		csfml

CFLAGS 			= 		-Werror -Wextra -Wshadow -W -Wall -I./include/

CSFML_FLAGS 	=		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

#
# For MacOS, use CSFML from local files ( ./__OSX__ ) // Otherwise ignore
OS_NAME 		=		$(shell uname -s | tr A-Z a-z)

ifeq ($(OS_NAME), darwin)
	CSFML_LIB = -L./__OSX__/lib
	CFLAGS += -I./__OSX__/include
endif
#
#

all: $(NAME)

$(NAME): 		$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML_LIB) $(CSFML_FLAGS)

clean:
		$(RM) -f $(OBJ)
		$(RM) src/*.o

fclean:		clean
		$(RM) $(NAME)

re: 	fclean all

test:
		make -C tests/

.PHONY  : all clean fclean re test