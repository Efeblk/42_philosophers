SRCS			= argcheck.c ft_atoi.c main_helpers.c main.c philo_create.c thread_routine.c utils.c routine_helpers.c
OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
LIB_NAME			= philo.a
NAME				= philo

all:			$(NAME) 

$(NAME):		$(LIB_NAME)
				$(CC) $(CFLAGS) -o $(NAME) $(LIB_NAME)

$(LIB_NAME):		$(OBJS)
				ar rcs $(LIB_NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME) $(LIB_NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re