CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
NAME = libftprintf.a
libft_obj=	libft/ft_atoi.o libft/ft_bzero.o libft/ft_calloc.o libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o\
			libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o libft/ft_memchr.o libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o\
			libft/ft_memset.o libft/ft_putchar_fd.o libft/ft_putendl_fd.o libft/ft_putnbr_fd.o libft/ft_putstr_fd.o libft/ft_split.o\
			libft/ft_strchr.o libft/ft_strdup.o libft/ft_striteri.o libft/ft_strjoin.o libft/ft_strlcat.o libft/ft_strlcpy.o libft/ft_strlen.o\
			libft/ft_strmapi.o libft/ft_strncmp.o libft/ft_strnstr.o libft/ft_strrchr.o libft/ft_strtrim.o libft/ft_substr.o libft/ft_tolower.o\
			libft/ft_toupper.o libft/ft_lstadd_back_bonus.o libft/ft_lstadd_front_bonus.o libft/ft_lstclear_bonus.o\
			libft/ft_lstdelone_bonus.o libft/ft_lstiter_bonus.o libft/ft_lstlast_bonus.o libft/ft_lstmap_bonus.o libft/ft_lstnew_bonus.o libft/ft_lstsize_bonus.o
printf_obj=	ft_printf/ft_handlers.o  ft_printf/ft_printf.o  ft_printf/ft_utils1.o  ft_printf/ft_utils2.o  ft_printf/ft_utils3.o
TEST=test.c

all : $(NAME)

$(NAME) : $(libft_obj) $(printf_obj)
	$(AR) $@ $(libft_obj) $(printf_obj)

test : $(NAME) $(TEST)
	@$(CC) $(CFLAGS:-Werror=) $(TEST) $(NAME)
	@./a.out
	@rm a.out

clean :
	rm -rf $(libft_obj) $(printf_obj)
fclean : clean
	rm $(NAME)
re : fclean all
.PHONY : all clean fclean re