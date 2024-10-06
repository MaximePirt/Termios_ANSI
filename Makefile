#############################################################################
#									OS										#
#############################################################################

ifeq ($(OS), Windows_NT)
	DIRSEP	= \\
	CP		= copy
	RM		= del -f
else
	DIRSEP	= /
	CP		= cp
	RM		= rm -f
endif

NAME					= minishell

#############################################################################
#									SOURCES									#
#############################################################################

SRCS			= main.c memory_alloc.c erase_put.c move_cursor.c term_utils.c

#############################################################################
#									FOLDERS									#
#############################################################################

SRCS			:= $(addprefix src$(DIRSEP), $(SRCS))

#############################################################################

OBJ_PATH		= obj$(DIRSEP)

OBJ_NAME		= $(SRCS:%.c=%.o)

OBJS			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC				= gcc

HEAD			= include

LIBFT_DIR		= libft

CFLAGS = -I $(HEAD) -MMD -MP -Wall -Wextra -Werror

# COLORS
DEFCOLOR = \033[0;39m
GREEN    = \033[1;92m
YELLOW   = \033[0;93m
PURPLE   = \033[0;95m
RED		 = \033[0;91m

$(NAME): $(OBJS) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -lncurses
	@echo "$(GREEN)$(NAME) has been created successfully.$(DEFCOLOR)"

libft:
	@make -C $(LIBFT_DIR)

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

all: $(NAME)

$(OBJ_PATH)%.o : %.c
	@mkdir -p $(@D) 2> $(DIRSEP)dev$(DIRSEP)null || true
	@echo "$(YELLOW)Compiling $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean: libft_clean
	@$(RM) -r $(OBJ_PATH) 2> $(DIRSEP)dev$(DIRSEP)null || true
	@echo "$(PURPLE)Object files have been removed.$(DEFCOLOR)"

fclean: libft_fclean
	@$(RM) -r $(OBJ_PATH) 2> $(DIRSEP)dev$(DIRSEP)null || true
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) has been removed.$(DEFCOLOR)"

re: fclean all

run:
	$(MAKE) DEBUG=0
	./minishell

norm:
	@norminette src libft | grep Error || echo "$(GREEN)Success"

.PHONY: libft libft_clean libft_fclean all clean fclean re run norm
