SRCS 		= *.c
OBJS 		= *.o
NAME		= fillit

all : $(NAME)

$(NAME) :
	@make -C libft 
	gcc -g -Wall -Wextra -Werror -o fillit $(SRCS) -Llibft -lft 
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
