##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile cs
##

SRC 	=	$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	 libmy.a

MY 	=	my.h

BINARY	=	giantman

all:	$(NAME)

$(NAME):	$(OBJ)
	mkdir -p include
	ar rc $(NAME) $(OBJ)
	gcc *.c -g -L. -lmy -o  $(BINARY)

clean:
	rm -f lib/my/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(BINARY)

re:	clean	all
