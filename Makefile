CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_put_chars.c ft_put_nbr.c ft_put_nbr_utils.c main.c 
OBJ = $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

all :$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o main
	rm -fr $^
	clear
	./main
m : main.c
	$(CC) $(FLAGS) main.c -o main
	clear
	@./main
