##
## EPITECH PROJECT, 2019
## PSU_minishell2_2019
## File description:
## Makefile
##

SRCS =	./src/main.c \
		./src/ia.c \
		./src/tools.c

LIBPATH = ./lib/my/

OBJ = $(SRCS:.c=.o)

NAME = ai

RM = rm -f

LIBFLAGS = -L lib/my -lmy

CFLAGS += -W -Wall -Wextra -I include/ -Ilib/my/

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBPATH) all
	$(CC) $(OBJ) $(CFLAGS) $(LIBFLAGS) -o $(NAME)

clean :
	$(RM) $(NAME)
	$(RM) $(OBJ)

fclean : clean
	make -C $(LIBPATH) fclean

re : clean fclean all

.PHONY: all clean fclean re
