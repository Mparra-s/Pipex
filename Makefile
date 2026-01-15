NAME	=	pipex					

SRCS	=  	pipex.c\
			pipex_path.c\
			pipex_utils.c\
			pipex_errors.c\
		
OBJS	=	$(SRCS:.c=.o)					

CC	=	cc									

RM	=	rm -f								

CFLAGS	=	-Wall -Wextra -Werror

LIBFT_DIR =	Libft

LIBFT = $(LIBFT_DIR)/libft.a

all	:	$(NAME)									

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -v -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)		

%.o: %.c									
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	make clean -C $(LIBFT_DIR)									
	$(RM) $(OBJS)

fclean	: clean
	make fclean -C $(LIBFT_DIR)							
	$(RM) $(NAME)

re	:	fclean all							

.PHONY	:	all clean fclean re	