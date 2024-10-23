# Project name
NAME = fractol
F1 := mandelbrot
F2 := julia
F3 := "burning ship"

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDES := -Imlx_linux

# Source files and object files
SRC := ft_event.c ft_initf.c ft_renderf.c ft_math_utilities.c ft_libft.c main.c ft_errormsg.c
OBJ := $(SRC:.c=.o)

# Colors for terminal output
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
NC := \033[0m

# Commands to create the executable
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)Successfully Built $(NAME)$(NC) $(GREEN)[...ok]"

# Rule to compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@ -fPIE
	@echo "$(YELLOW)Compiled $<$(NC) $(GREEN)[...ok]"

# Rule to build all targets
all: $(NAME)

valgrind_mandelbrot: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(F1)

valgrind_julia: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(F2) "-0.8" "+0.156"

valgrind_burning: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(F3)

mandelbrot : $(NAME)
	./$(NAME) $(F1)
julia : $(NAME)
	./$(NAME) $(F2) "-0.8" "+0.156"
burning : $(NAME)
	./$(NAME) $(F3)

# Clean up object files
clean:
	@rm -f $(OBJ)

# Clean up object files and the executable
fclean: clean
	@rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony targets for build and cleanup
.PHONY: all clean fclean re