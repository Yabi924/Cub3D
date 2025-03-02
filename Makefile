CFLAG = -Wall -Wextra -Werror
NAME = cub3D

LIBS = ./libft/libft.a -L./libft -lft -L./minilibx-linux/ -lmlx -lmlx_Linux -lX11 -lXext -lm

SRCS_PATH = ./srcs/

SRCS = $(SRCS_PATH)main.c \
	$(SRCS_PATH)utils.c \
	$(SRCS_PATH)lexer.c \
	$(SRCS_PATH)check_direction.c \
	$(SRCS_PATH)free.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

%.o: %.c
	@gcc $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	@echo compling libft...
	@make -C ./libft/ --no-print-directory
	@echo Hi libft
	@echo compling cub3D...
	@gcc $(CFLAG) -o $(NAME) $(OBJS) $(LIBS)
	@echo Hi cub3D

clean:
	@rm -rf $(OBJS)
	@echo clean *.o

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C./libft/ --no-print-directory
	@echo bye libft
	@echo bye $(NAME)

re: fclean all

mlx:
	@make -C ./minilibx-linux/ --no-print-directory

cmlx:
	@make clean -C ./minilibx-linux/ --no-print-directory

r: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./cub3D ./map/ok.cub
