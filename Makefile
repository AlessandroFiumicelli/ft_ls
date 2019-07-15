NAME = ft_ls

SRC = srcs/errors.c srcs/get_info.c srcs/init_free_info.c srcs/len_info.c\
srcs/ls_args.c srcs/main.c srcs/par_init_free.c srcs/parser.c\
srcs/parser_re_sorter.c srcs/parser_sorter.c srcs/parser_utils.c\
srcs/print_l_end.c srcs/print_l_start.c srcs/recursion.c srcs/sort_info.c\
srcs/start.c srcs/utils.c srcs/print_start.c

OBF = $(SRC:.c=.o)

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror -o

.PHONY = all clean fclean re

all : $(NAME)

$(NAME) : $(OBF)
	@echo "compiling library"
	@make -C libft
	@echo "done"
	@echo "linking object files"
	@gcc $(FLAGS) $(NAME) $(OBF) $(LIB)
	@echo "done"

$(OBF):

clean :
	@echo "executing clean"
	@rm -rf $(OBF)
	@make clean -C libft
	@echo "done"

fclean : clean
	@echo "exexuting fclean"
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo "done"

re : fclean all
