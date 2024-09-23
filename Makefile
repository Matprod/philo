# Standard
NAME				= philo

# Directories
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -I
RM					= rm -f

# Concatenate all source files
SRCS 				= srcs/end_data.c\
					srcs/print.c\
					srcs/main.c\
					srcs/ft_usleep.c\
					srcs/end_data.c\
					srcs/init.c\
					srcs/parsing.c\
					srcs/philo.c\
					srcs/philo_utils.c\
					srcs/utils.c\

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					make all


all: 				$(NAME)

$(NAME): 			$(OBJ)
					$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
