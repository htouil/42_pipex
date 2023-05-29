NAME 	= pipex

SRCS	= pipex.c pipex_utils.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strnstr.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY = all clean fclean re