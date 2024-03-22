CLFAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
AR = ar rcs
SRC_DIR = src
SRC2_DIR = push_swap_main
SRCB_DIR = srcb
INC_DIR = inc
OBJ_DIR = obj
OBJ2_DIR = obj2
OBJB_DIR = objb
LIBFT = libft.a
LIBFT_DIR = libft
NAME = push_swap
BONUS = checker

SRC =	handle_errors.c\
		init_a_to_b.c\
		init_b_to_a.c\
		push_swap_utils.c\
		push.c\
		rev_rotate.c\
		rotate.c\
		sort_stacks.c\
		sort_three.c\
		stack_init.c\
		stack_utils.c\
		swap.c\
		push_cost.c

SRCB =	checker_bonus.c\

SRC2 = push_swap.c\

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ2 = $(addprefix $(OBJ2_DIR)/, $(SRC2:.c=.o))

OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

all : $(NAME) $(BONUS)

$(NAME): $(LIBFT) $(OBJ) $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ2) $(LIBFT) -o $(NAME)

$(BONUS): $(LIBFT) $(OBJ) $(OBJB)
	$(CC) $(CFLAGS) $(OBJ) $(OBJB) $(LIBFT) -o $(BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ2_DIR)/%.o: $(SRC2_DIR)/%.c | $(OBJ2_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c | $(OBJB_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ2_DIR):
	mkdir -p $(OBJ2_DIR)

$(OBJB_DIR):
	mkdir -p $(OBJB_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .

clean:
	$(RM) $(OBJ_DIR) $(OBJ2_DIR) $(OBJB_DIR) $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

bonus: $(BONUS)

.PHONY: all clean fclean re bonus
