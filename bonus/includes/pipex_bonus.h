/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:59:07 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 12:18:11 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// header includes

# include "../../libft/libft.h"
# include "../../libft/ft_printf/includes/ft_printf.h"
# include "../../libft/get_next_line/get_next_line.h"
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <errno.h>

// return status

# define SUCCESS 0
# define FAIL 1

// error messages

# define E_NULL_MALLOC "Null value due to a failed malloc."
# define E_FAILED_MALLOC "Failed malloc."
# define E_INV_PARAM "Invalid argument number."

typedef struct s_pipex
{
	int		i_first_cmd;
	int		cmd_nb;
	int		pipe_nb;
	int		**fd;
	int		here_doc;
	char	**env_paths;
	char	***cmds_list;
	char	**cmds_path;
	char	*limiter_with_slash_n;
	char	*slash;
	char	*full_path_cmd;
	int		i;
	char	*heredoc_name;
	pid_t	*child;
}	t_pipex;

// main checking

void	main_checking(int argc, char **argv, t_pipex *pipex, char **envp);
void	make_here_doc_work(char **argv, t_pipex *pipex);
void	del_hd(t_pipex *pipex);

// get_paths

int		get_env_paths_len(char **env_paths);
char	*del_path_word(char *env_paths_0, t_pipex *pipex);
void	get_env_paths(char **envp, t_pipex *pipex);
void	get_valid_cmd_paths(t_pipex *pipex);

// get_cmds

void	join_paths_and_cmds(t_pipex *pipex, int i, int j);
void	init_cmds_path(t_pipex *pipex);
void	init_cmd_args(int argc, char **argv, t_pipex *pipex);
void	get_cmds_list(char **argv, t_pipex *pipex);

// cmd_stuff

void	first_cmd(char *infile, t_pipex *pipex, int i);
void	mid_cmd(t_pipex *pipex, int i);
void	last_cmd(char *outfile, t_pipex *pipex, int i);
void	exec_cmd(t_pipex *pipex, int i, char **envp);

// dup_fd

void	dup_stdout_to_outfile(char *out, t_pipex *pipex);
void	dup_stdin_to_infile(char *in, t_pipex *pipex);
void	dup_stdout_to_fd1(t_pipex *pipex, int i);
void	dup_stdin_to_fd0(t_pipex *pipex, int i);
void	close_fds(t_pipex *pipex);
void	free_double_fd(t_pipex *pipex);

// exit program

void	init_malloced_ptrs(t_pipex *pipex);
void	exit_program(t_pipex *pipex, int word, char *message, int status);
void	free_all(t_pipex *pipex);
void	free_triple_tab(char ***tab);
void	display_message(int word, char *message, int status);

// init_proc

void	init_pipes_and_proc(t_pipex *pipex);

#endif
