NAME=cub3d
SRCS=srcs/*.c srcs/utils/*.c srcs/scene/*.c srcs/render/*.c srcs/player/*.c srcs/controls/*.c 
INC=/usr/include
MLX_FLAGS_MAC = -Imlx -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS_LINUX=-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# GCC=gcc -Wall -Wextra -Werror -g3 
GCC=gcc -Wall -Wextra -Werror -fsanitize=address -g3 #Checks for leaks (might heap overflow if user spams up and left)
 
all : 
	@echo "make [OS]"

linux : ${SRCS}
	cd mlx_linux && ./configure
	${GCC} libft/*.c ${SRCS} ${MLX_FLAGS_LINUX} -I . -o ${NAME}

mac : ${SRCS}
	${GCC} libft/*.c ${SRCS} ${MLX_FLAGS_MAC} -I . -o ${NAME}

# %.o: %.c
# 	${GCC} -I /usr/include -Imlx_linux -O3 -c $< -o $@

clean : 
	rm -f *.o libft/*.o
	make -C libft clean

fclean : 
	rm -f *.o libft/*.o ${NAME} *.out
	make -C libft fclean

re : fclean all

.PHONY : clean re fclean all
