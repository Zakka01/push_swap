NAME = push_swap.a

FLAGS = -Wall -Wextra -Werror

SRC := $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

AR = ar rcs

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ) 

%.o : %.c push_swap.h
	@cc $(FLAGS) -c $< -o $@

clean : 
	@$(RM) $(OBJ)

fclean : clean 
	@$(RM) $(NAME) push_swap


re : fclean all



# test role
test :	$(OBJ) $(NAME)
	@cc $(FLAGS) push_swap.c $(NAME) -o push_swap