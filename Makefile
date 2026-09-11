CC = cc
CFLAGS = -Wall -Wextra -Werror 
SANITIZE = -fsanitize=address -g


RM = rm -rf
SRC = main.c \
	utilities.c \

DEPENDS = libft/libft.a

TARGET = main

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)


all: $(TARGET)

$(TARGET): $(OBJ) 
	@$(CC) $(CFLAGS) $(SANITIZE) $(OBJ) $(DEPENDS)  -o $(TARGET)


$(OBJ_DIR)/%.o: %.c $(DEPENDS)
	@echo "Compiling $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DEPENDS):
	@make -C ./libft

clean:
	@make -C ./libft clean
	@$(RM) $(OBJ_DIR)

fclean:
	@make -C ./libft fclean
	@$(RM) $(OBJ_DIR) $(TARGET)



.PHONY: all clean fclean re

re: fclean all

