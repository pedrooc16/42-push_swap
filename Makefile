NAME = push_swap

# Collors
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
RESET 	= \033[0m

SRC_FILES = main.c 
RM = rm -f

OBJS = $(SRC_FILES:.c=.o)

CC = gcc -g
FLAGS = -Wall -Wextra -Werror

all: $(NAME) 

#§@ nome arquivo objeto
#$< nome do pre-requisito

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

