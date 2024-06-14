NAME = push_swap
BONUS_NAME = checker

SRCS = a_2_b_helpers.c arr_utils.c b_2_a_helpers.c clear.c cmd_executer.c error.c fix_order.c init.c list_utils.c \
		operations_1.c operations_2.c operations_3.c operations_4.c parse_check.c parse_check_2.c \
		push_swap.c sort_3.c wild_math.c debug_helper.c
B_SRCS = $(SRCS) checker.c get_next_line.c
MAIN_SRCS = $(SRCS) main.c

OBJ_DIR = ./obj/

OBJS = $(addprefix $(OBJ_DIR), $(MAIN_SRCS:.c=.o))

B_OBJS = $(addprefix $(OBJ_DIR), $(B_SRCS:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "all DONE"

$(NAME): ${OBJ_DIR} $(OBJS)
	make all bonus -C ./libft/
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o ${NAME}

$(BONUS_NAME): bonus

bonus: ${OBJ_DIR} $(B_OBJS)
	make all bonus -C ./libft/
	$(CC) $(CFLAGS) $(B_OBJS) libft/libft.a -o ${BONUS_NAME}

$(OBJ_DIR)%.o: %.c | obj
	$(CC) $(CFLAGS) -g -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "OBJ_DIR DONE"

clean:
	make clean -C ./libft/
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re




#$%.o: %.c
#	$(CC) $(CFLAGS) -g -c $< -o $@./

#libft:
#	make -C ./libft/
