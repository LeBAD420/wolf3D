CC			= gcc

NAME		= wolf3d

INCLUDE		= ./includes/

SRCS		= 	main.c				\
				camera_fct.c		\
				error_fct.c			\
				hook_fct.c			\
				map_fct.c			\
				ft_get_next_line.c	\
				env_fct.c			\
				img_fct.c			\
				move_fct.c			\
				pos_fct.c			\
				detect_fct.c		\
				draw_fct.c			\

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra -g

CLFLAGS     += -L/usr/X11/lib -lmlx -lXext -lX11
CLFLAGS     += -L libft -lft
LDFLAGS 	= -I $(DIR_LIBFT)/includes

DIR_LIBFT	= ./libft

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -I $(INCLUDE) -L -lft

$(NAME):	$(DIR_LIBFT)/libft.a $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CLFLAGS) $(CFLAGS) $(LDFLAGS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

$(DIR_LIBFT)/libft.a:
	make  -f Makefile -C $(DIR_LIBFT)

re:			fclean all

.PHONY:		all clean re fclean
