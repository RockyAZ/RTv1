gcc -o abu abu.c libft/libft.a -I./libft/ -I./Frameworks/SDL2.framework/Headers\
	 		   -I./Frameworks/SDL2_image.framework/Headers\
				-rpath @loader_path/Frameworks -F./Frameworks/ -framework SDL2 -framework SDL2_image