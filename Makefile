
NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

SRC = ft_printf.c ft_put_hexa.c ft_put_nbr_utils.c ft_printf_utils.c \
	ft_put_nbr_base.c ft_put_pointer.c ft_put_char.c ft_put_str.c \
	ft_put_nbr.c ft_put_unsigned.c 

OBJ = $(SRC:%.c=%.o)

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	ar crs $@ $^

all : $(NAME)

bonus : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
