# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <htouil@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 22:29:32 by htouil            #+#    #+#              #
#    Updated: 2023/07/13 19:03:51 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex

SRCS	= pipex.c pipex_utils.c exec_cmds.c free.c \
			libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strnstr.c libft/ft_strfchr.c libft/ft_isalnum.c \
			libft/ft_strcpy.c libft/ft_strtrim.c

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
