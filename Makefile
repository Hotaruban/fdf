# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 16:37:56 by jhurpy            #+#    #+#              #
#    Updated: 2023/05/23 13:37:15 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -g
D_FLAGS = -MMD -MP -MF $(OBJ_DIR)/$*.d
M_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
#S_FLAGS = -g -fsanitize=address,undefined,leak

# Commands
RM = rm -rf
AR = ar rc

# Target library name and directories
NAME = fdf.a
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBS_DIR = ../libft ./mlx

# Sources, objects and dependencies
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target, build the library
all: $(LIBS_DIR) $(NAME)

# Object file build rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(D_FLAGS) $(S_FLAGS) -I $(INC_DIR) -c $< -o $@

# Target library build rule
$(NAME): $(OBJECTS)
	make -C $(LIBS_DIR)
	cp ../libft/libft.a $(NAME)
	$(AR) $(NAME) $(M_FLAGS) $(OBJECTS)
	ranlib $(NAME)

# Rule to build each personal library
$(LIBS_DIR):
	$(MAKE) -C $@

# Clean object files
clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBS_DIR)

# Clean object files and target library
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBS_DIR)/libft.a
	make fclean -C $(LIBS_DIR)

# Clean and rebuild the target library
re: fclean all

# Check code style
norm:
	norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c ; \
	norminette -R CheckDefine $(INC_DIR)/*.h

# Phony targets
.PHONY: all clean fclean re norm
