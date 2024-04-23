NAME = push_swap

#---mandatory part---#
SRC_M = parsing.c\
		algo.c\
		apply.c\
		check.c\
		count.c\
		find_place.c\
		main.c\
		outils.c\
		max_min.c\
		print_errors.c\
		rules_0.c\
		rules_1.c\
		rules_2.c\
		rules_3.c\
		sort.c

OBJ		= 	$(SRC_M:.c=.o)
#---bonus part---#
NAME_B = checker

SRC_BONUS = bonus/main.c bonus/rules_0.c bonus/rules_1.c bonus/rules_2.c bonus/rules_3.c \
			bonus/get_next_line_utils.c bonus/get_next_line.c bonus/print_errors.c bonus/check.c \
			bonus/parsing.c

OBJ_BONUS = $(SRC_BONUS:.c=.o) 


CC = cc
CFLAGS =  -Wall -Wextra -Werror 

LIBFT_MAKE = make -C libft
LIBFT_PATH = libft

PRINTF_MAKE = make -C printf
PRINTF_PATH = printf

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFT_MAKE)
	$(PRINTF_MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_PATH)/libftprintf.a $(LIBFT_PATH)/libft.a -o $(NAME)
bonus: $(OBJ_BONUS)
	$(LIBFT_MAKE)
	$(PRINTF_MAKE)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF_PATH)/libftprintf.a $(LIBFT_PATH)/libft.a -o $(NAME_B)
clean:
	make clean -C libft
	make clean -C printf
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean 
	make fclean -C libft
	make fclean -C printf
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: all bonus clean fclean re