### VARIABLES ###

# Names
NAME 	= 	HAL

# Instructions
CC 		=	gcc -Wall -Wextra -Werror -ILibft
RM 		= 	rm -f

# Files
SOURCES = 	$(wildcard *.c)
OBJECTS =	$(SOURCES:.c=.o)


### RULES ###

# Main rules
all: libft $(OBJECTS)
	@$(CC) -o $(NAME) $(OBJECTS) Libft/libft.a
	@echo "Calculator '$(NAME)' created."

libft:
	@make -C Libft

clean:
	@$(RM) $(OBJECTS)
	@make -C Libft clean
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@make -C Libft fclean
	@echo "File '$(NAME)' removed."

re: fclean all
	@echo "Project recompiled."

.PHONY: all clean fclean re

%.o: %.c
	@$(CC) -c $< -o $@
	@echo "* File '$<' compiled."