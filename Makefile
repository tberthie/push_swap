S1 = main.c \
	 checker.c

S2 = main.c

O1 = $(addprefix srcs/checker/,$(S1:.c=.o))
O2 = $(addprefix srcs/push_swap/,$(S2:.c=.o))

N1 = checker
N2 = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCS = includes

all: $(N1) $(N2)

$(N1): $(O1)
	@echo "[compiling libft]"
	@make -C libft
	@gcc $(FLAGS) -o $(N1) libft/libft.a $(O1)
	@echo "[$(N1)]"

$(N2): $(O2)
	@echo "[compiling libft]"
	@make -C libft
	@gcc $(FLAGS) -o $(N2) libft/libft.a $(O2)
	@echo "[$(N2)]"

srcs/checker/%.o: srcs/checker/%.c
	@$(CC) $(FLAGS) -I $(INCS) -I libft/includes -o $@ -c $<
	@echo "[$@]"

srcs/push_swap/%.o: srcs/push_swap/%.c
	@$(CC) $(FLAGS) -I $(INCS) -I libft/includes -o $@ -c $<
	@echo "[$@]"

clean:
	@make clean -C libft
	@rm -f $(O1) $(O2)
	@echo "[objs removed]"

fclean: clean
	@make fclean -C libft
	@rm -f $(N1) $(N2)
	@echo "[workspace clean]"

re: fclean all
