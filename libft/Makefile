NAME = libft.a

GNL_FOLDER = ./get_next_line/
FT_PRINTF_FOLDER = ./ft_printf/srcs/

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_atol.c ft_calloc.c ft_strdup.c ft_strdup_int.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstprint.c ft_lstsize_circular.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_print_double_tab.c ft_print_triple_tab.c free_double_tab.c
GNL_SRCS = $(GNL_FOLDER)get_next_line.c $(GNL_FOLDER)get_next_line_utils.c
FT_PRINTF_SRCS = $(FT_PRINTF_FOLDER)ft_print_char.c $(FT_PRINTF_FOLDER)ft_print_hex.c $(FT_PRINTF_FOLDER)ft_print_int.c $(FT_PRINTF_FOLDER)ft_print_perc.c $(FT_PRINTF_FOLDER)ft_print_ptr.c $(FT_PRINTF_FOLDER)ft_print_str.c $(FT_PRINTF_FOLDER)ft_print_uns.c $(FT_PRINTF_FOLDER)ft_printf.c $(FT_PRINTF_FOLDER)ft_putnbr_dec_to_hex.c $(FT_PRINTF_FOLDER)ft_set_data.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	ar rcs $(NAME) $(OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(GNL_FOLDER)%.o: %.c $(GNL_FOLDER)get_next_line.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(FT_PRINTF_FOLDER)%.o: %.c $(FT_PRINTF_FOLDER)includes/ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJS)
	rm -f $(GNL_OBJS)
	rm -f $(FT_PRINTF_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME) 

.PHONY: all clean fclean re
