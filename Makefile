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

all:
	gcc -g -o RTv1 main.c ray.c vector.c error.c libft/libft.a -I libft/ -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit