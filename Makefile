NAME = push_swap

# FLAGS = -Wall -Wextra -Werror
# FLAGS = -fsanitize=address

SRC := $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

AR = ar rcs

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	@cc $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h
	@cc $(FLAGS) -c $< -o $@

clean : 
	@$(RM) $(OBJ)

fclean : clean 
	@$(RM) $(NAME) push_swap

re : fclean all
