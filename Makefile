NAME	=	philo

SRCS	=	init.c main.c utils.c philo_life.c events.c

OBJ		=	$(SRCS:%.c=%.o)

INCLUDE	=	include/

HEADER	=	philo.h

CC		=	gcc

FLAGS	=	-g -Wall -Wextra -Werror #-fsanitize=thread

RM		= rm -rf

.PHONY:		all	clean	fclean	re	libft

all:		libft $(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			@echo "$(GRN) $(END)"

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

clean:
			@$(RM) $(OBJ) $(OBJ_B)

fclean:		clean

re:			fclean all
			@echo "$(BLUE) $(END)"