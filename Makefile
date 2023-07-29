NAME	=	philo

SRCS	=	srcs/init_all.c\
			srcs/utils.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I include -pthread

rm		=	rm -Rf

all		:	$(NAME)


$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)
