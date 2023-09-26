NAME = push_swap

# Collors
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
RESET 	= \033[0m

SRC_FILES = main.c 
RM = rm -f

OBJS = $(SRC_FILES:.c=.o)

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

all: $(NAME) 

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

#§@ nome arquivo objeto
#$< nome do pre-requisito

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o $@ $^ && echo "$(GREEN)Compiled successfully"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Comando para compilar a biblioteca libft
$(LIBFT):
	make -C $(LIBFT_DIR)

clean: 
	$(RM) $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean:	clean
	$(RM) $(NAME)
	cd $(LIBFT_DIR) && make fclean

re:	fclean	all

