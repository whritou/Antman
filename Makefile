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

MAKE	=	make

FCLEAN	=	make fclean

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C antman
	make -C giantman
clean:
	rm -f lib/my/*.o

fclean: clean
	rm -f $(NAME)
	make -C antman fclean
	make -C giantman fclean

re:	clean	all
