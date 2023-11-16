CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
NAME = libftprintf.a
LIBFT = libft/libft.a
PRINTF = libprintf.a
SRC = ft_handlers.c ft_printf.c ft_utils1.c ft_utils2.c ft_utils3.c
OBJ=$(SRC:.c=.o)
TEST=test.c

$(NAME) : $(LIBFT) $(PRINTF)
	$(AR) -T -o $(NAME) $(PRINTF) $(LIBFT)

$(LIBFT) :
	make bonus -C libft/
$(PRINTF) : $(OBJ)
	$(AR) -o $@ $(OBJ)

.PHONY : clean fclean all re test

test : $(SRC) $(TEST)
	@$(CC) $(CFLAGS:-Werror=) $(SRC) $(TEST)
	@./a.out
	@rm a.out

clean :
	make clean -C libft/
	rm -rf $(OBJ) $(LIBFT) $(PRINTF)
fclean : clean
	make fclean -C libft/
	rm -rf $(NAME)
all : $(NAME)
re : fclean all
