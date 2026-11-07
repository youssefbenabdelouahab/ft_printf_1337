NAME = libftprintf.a

CC = cc 

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_print_char.c ft_print_str.c ft_print_hex.c ft_print_nbr.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $?

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re