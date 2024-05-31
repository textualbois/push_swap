NAME = push_swap

SRCS = a_2_b_helpers.c arr_utils.c clear.c init.c main.c \
       operations_1.c operations_2.c parse_check.c parse_check_2.c \
       push_swap.c wild_math.c error.c


B_SRCS = $(SRCS)

OBJ_DIR = ./obj/

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

B_OBJS = $(addprefix $(OBJ_DIR), $(B_SRCS:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "all DONE"

$(NAME): ${OBJ_DIR} $(OBJS)
	make all bonus -C ./libft/
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o ${NAME}

$(OBJ_DIR)%.o: %.c | obj
	$(CC) $(CFLAGS) -g -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "OBJ_DIR DONE"

bonus: fclean $(B_OBJS)
	make all bonus -C ./libft/
	$(CC) $(CFLAGS) $(B_OBJS) libft/libft.a -o ${NAME}

clean:
	make clean -C ./libft/
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re




#$%.o: %.c
#	$(CC) $(CFLAGS) -g -c $< -o $@./

#libft:
#	make -C ./libft/
