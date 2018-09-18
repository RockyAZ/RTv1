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

all:
	gcc -o RTv1 main.c ray.c vector.c  libft/libft.a -I./libft/ -I./Frameworks/SDL2.framework/Headers\
	 		   -I./Frameworks/SDL2_image.framework/Headers\
				-rpath @loader_path/Frameworks -F./Frameworks/ -framework SDL2 -framework SDL2_image