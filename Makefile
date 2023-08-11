NAME	=	philo

SRCS	=	srcs/init_all.c\
			srcs/utils.c\
			srcs/utils_2.c\
			srcs/thread.c\
			srcs/thread_2.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I include -pthread
#CFLAGS	=	-Wall -Werror -Wextra -I include -pthread -fsanitize=thread

rm		=	rm -Rf

all		:	$(NAME)


$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)
