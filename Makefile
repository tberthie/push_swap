# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 22:18:00 by tberthie          #+#    #+#              #
#    Updated: 2017/02/20 23:14:09 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = $(addsuffix .o, $(addprefix objs/, checker))
PUSH = $(addsuffix .o, $(addprefix objs/, push_swap))
COMMON = $(addsuffix .o, $(addprefix objs/, ops))

N_CHECK = checker
N_PUSH = push_swap

all: objs $(N_CHECK) $(N_PUSH)

objs:
	mkdir objs

$(N_CHECK): $(CHECK) $(COMMON)
	make -C libft
	gcc -o $(N_CHECK) $(CHECK) $(COMMON) libft/libft.a

$(N_PUSH): $(PUSH) $(COMMON)
	make -C libft
	gcc -o $(N_CHECK) $(CHECK) $(COMMON) libft/libft.a

objs/%.o: srcs/%.c
	gcc -o $@ -c $< -I includes -I libft -Weverything

clean:
	rm -rf objs

fclean: clean
	rm -f $(N_CHECK) $(N_PUSH)

re: fclean all
