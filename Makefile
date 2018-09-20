#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 19:53:10 by azaporoz          #+#    #+#              #
#    Updated: 2018/09/18 19:53:10 by azaporoz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# all:
# 	gcc -o RTv1 main.c ray.c vector.c figure.c scene3_4.c scene1_2.c libft/libft.a -I./libft/ -I./Frameworks/SDL2.framework/Headers\
# 	 		   -I./Frameworks/SDL2_image.framework/Headers\
# 				-rpath @loader_path/Frameworks -F./Frameworks/ -framework SDL2 -framework SDL2_image


NAME = RTv1
FLAGS = -Wall -Wextra -Werror
SOURCE = main.c ray.c vector.c figure.c scene3_4.c scene1_2.c add.c

HEADER = rtv1.h
OBJECTS = $(addprefix $(OBJDIR),$(SOURCE:.c=.o))
OBJDIR = ./obj/

SDL = -I./Frameworks/SDL2.framework/Headers -I./Frameworks/SDL2_image.framework/Headers -rpath @loader_path/Frameworks -F./Frameworks/ -framework SDL2 -framework SDL2_image

SDL_INC = -I./Frameworks/SDL2.framework/Headers -I./Frameworks/SDL2_image.framework/Headers
SDL_LIB = -rpath @loader_path/Frameworks -F./Frameworks/ -framework SDL2 -framework SDL2_image

LIBFT_INC = -I ./libft/
LIBFT = ./libft/libft.a

all: obj $(LIBFT) $(NAME)
	@printf "\033[0;31m\
>_<\n"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c $(HEADER)
	@printf "\033[0;34m->    "
	gcc $(FLAGS) $(SDL_INC) $(LIBFT_INC) -o $@ -c $<
	@printf "\n"

$(NAME): $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) $(SDL_INC) $(SDL_LIB) $(LIBFT) $(LIBFT_INC) $(SDL_LIB)

$(LIBFT):
	@make -C ./libft/
	@printf "\033[0;32m\n\n|||||||||||||||||||||\nSTART LOADING RTv1\n|||||||||||||||||||||\n\n\n\n"

clean:
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -rf $(OBJDIR)
	@make clean -C ./libft/

fclean: clean
	@make fclean -C ./libft/
	@/bin/rm -f $(NAME)

re: fclean all