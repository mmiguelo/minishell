# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 15:04:25 by frbranda          #+#    #+#              #
#    Updated: 2025/03/07 13:28:53 by mmiguelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                    NAMES                                     #
#==============================================================================#

CC = cc
FLAGS = -g -Wall -Wextra -Werror
INC = -I./includes
RM = rm -rf

VAL = valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=definite

GENERAL = main.c
BUILTIN = builtin_utils.c cd.c echo.c exit.c pwd.c
PARSING = quote_handler.c tokenizer.c token_list_tools.c initialize_structs.c
FREE = free.c free_shell.c
HEREDOC = heredoc.c
PRINT = print_token.c print_token_list.c

NAME = minishell

#==============================================================================#
#                                    EXTRA                                     #
#==============================================================================#

ECHO = @echo
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

VPATH += src
VPATH += src/builtin
VPATH += src/heredoc
VPATH += src/parsing
VPATH += src/frees
VPATH += src/prints

#==============================================================================#
#                                    FILES                                     #
#==============================================================================#

SRC +=	$(GENERAL)
SRC +=	$(BUILTIN)
SRC +=	$(HEREDOC)
SRC +=	$(PARSING)
SRC +=	$(FREE)
SRC +=	$(PRINT)

# Library Paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Objects Paths
OBJ_DIR = obj
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	@$(ECHO) "$(GREEN)----------------- minishell created$(RESET)"

# Make and run
r: all
	./minishell

# Make and run with valgrind
rv: all
	$(VAL) ./minishell

# Executable minishell with valgrind
v: re
	$(VAL) ./minishell

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(RED)----------------- OBJECTS deleted$(RESET)"

fclean: clean
	$(RM) $(NAME) $(OBJ_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)----------------- minishell deleted$(RESET)"

re: fclean all

# Phony Targets
.PHONY: all clean fclean re
