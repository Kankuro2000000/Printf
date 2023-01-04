NAME = libftprintf.a
SRCS = libftprintf.c utils_c_s.c utils_d.c utils_u.c utils_x_X_p.c

HEADER = ft_printf.h

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGC = -Wall -Wextra -Werror -I.

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
