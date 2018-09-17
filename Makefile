#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 14:30:13 by azaporoz          #+#    #+#              #
#    Updated: 2018/07/03 19:31:25 by azaporoz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
FLAGS = -Wall -Wextra -Werror
SOURCE = main.c 
HEADER = fractol.h
OBJECTS = $(addprefix $(OBJDIR),$(SOURCE:.c=.o))
LIBFT = include/libft.a
OBJDIR = ./obj/

all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c $(HEADER)
	@printf "\033[0;34m->    "
	gcc $(FLAGS) -I ./libft/ -o $@ -c $<
	@printf "\n"

$(NAME): $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	@make -C ./libft/
	@printf "\033[0;32m\n\n|||||||||||||||||||||\nSTART LOADING RTV\n|||||||||||||||||||||\n\n\n\n"

clean:
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -rf $(OBJDIR)
	@make clean -C ./libft/

fclean: clean
	@make fclean -C ./libft/
	@/bin/rm -f $(NAME)

re: fclean all
