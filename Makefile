
NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

SRC = ft_printf.c ft_put_chars.c ft_put_nbr.c ft_put_nbr_utils.c main.c

OBJ = $(SRC:%.c=%.o)

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	ar crs $@ $^

all : $(NAME)
	$(CC) $(FLAGS) $(NAME)
	@clear
	@./a.out
bonus : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean fclean re
