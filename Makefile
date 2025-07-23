# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokson <seokson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 18:00:00 by seokson           #+#    #+#              #
#    Updated: 2025/07/23 10:03:15 by seokson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
BONUS		= pipex_bonus

INCLUDE		= includes

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE) -I$(LIBFT_DIR)

SRCS		= mandatory/main.c \
			  mandatory/pipex.c \
			  mandatory/error.c \
			  mandatory/cmd_path.c \
			  mandatory/exec.c \
			  mandatory/file_io.c \
			  mandatory/parser.c

BONUS_SRCS	= bonus/main_bonus.c \
			  bonus/pipex_bonus.c \
			  bonus/pipex_here_doc_bonus.c \
			  bonus/error_bonus.c \
			  bonus/cmd_path_bonus.c \
			  bonus/exec_bonus.c \
			  bonus/file_io_bonus.c \
			  bonus/parser_bonus.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

bonus: $(BONUS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
