NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = ./srcs/
SRCS_BONUS = ./bonus/srcs/

LIBFT_FLAGS = -Llibft -lft

PIPEX_INCLUDES = -Iincludes
PIPEX_INCLUDES_BONUS = -Ibonus/includes
LIBFT_INCLUDES = -Ilibft
FT_PRINTF_INCLUDES = -Ilibft/ft_printf/includes

CFILES = $(SRCS)pipex.c $(SRCS)dup_fd.c $(SRCS)get_paths.c $(SRCS)get_cmds.c $(SRCS)exit_program.c
OFILES = $(CFILES:.c=.o)

CFILES_BONUS = $(SRCS_BONUS)pipex_bonus.c $(SRCS_BONUS)dup_fd_bonus.c $(SRCS_BONUS)get_paths_bonus.c $(SRCS_BONUS)get_cmds_bonus.c $(SRCS_BONUS)exit_program_bonus.c $(SRCS_BONUS)init_pipes_proc_bonus.c $(SRCS_BONUS)main_checking_bonus.c $(SRCS_BONUS)cmd_stuff_bonus.c
OFILES_BONUS = $(CFILES_BONUS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OFILES)
	make -C libft/
	$(CC) -o $(NAME) $(OFILES) $(LIBFT_FLAGS)

$(SRCS)%.o: $(SRCS)%.c
	$(CC) $(FLAGS) -c -o $@ $< $(PIPEX_INCLUDES) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

$(SRCS_BONUS)%.o: $(SRCS_BONUS)%.c
	$(CC) $(FLAGS) -c -o $@ $< $(PIPEX_INCLUDES_BONUS) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

bonus: fclean $(OFILES_BONUS)
	cd libft && $(MAKE)
	rm -f $(NAME)
	$(CC) $(WFLAGS) -o $(NAME_BONUS) $(OFILES_BONUS) $(LIBFT_FLAGS)

clean:
	rm -f $(OFILES)
	rm -f $(OFILES_BONUS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	cd libft && rm -f libft.a

re: fclean all

.PHONY: all clean fclean re bonus
