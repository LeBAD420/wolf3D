CC			= gcc

NAME		= wolf3d

INCLUDE		= ./includes/

SRCS		= 	main.c				\
				camera_fct.c		\
				hook_fct.c			\
				error_fct.c			\
				read.c				\

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

CLFLAGS     += -L/usr/X11/lib -lmlx -lXext -lX11

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -I $(INCLUDE)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CLFLAGS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
