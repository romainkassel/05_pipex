/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:59:07 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/20 17:03:49 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// header includes

# include "../libft/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <stdio.h>
# include <sys/wait.h>
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
	char	**env_paths;
	char	***cmds_list;
	char	**cmds_path;
	char	*slash;
	char	*full_path_cmd;
	int		fd[2];
	pid_t	child[2];
}	t_pipex;

// get_paths

int		get_env_paths_len(char **env_paths);
char	*del_path_word(char *env_paths_0, t_pipex *pipex);
void	get_paths(char **envp, t_pipex *pipex);
void	get_valid_cmd_paths(t_pipex *pipex, int cmd_nb);

// get_cmds

void	join_paths_and_cmds(t_pipex *pipex, int i, int j);
void	init_cmds_path(t_pipex *pipex, int cmd_nb);
void	get_cmds(int argc, char **argv, t_pipex *pipex);

// dup_fd

void	dup_stdout_to_outfile(char *out, t_pipex *pipex);
void	dup_stdin_to_infile(char *in, t_pipex *pipex);
void	dup_stdout_to_fd1(t_pipex *pipex);
void	dup_stdin_to_fd0(t_pipex *pipex);

// exit program

void	init_mallocs(t_pipex *pipex);
void	exit_program(t_pipex *pipex, int word, char *message, int status);
void	free_malloced_ptrs(t_pipex *pipex);
void	free_triple_tab(char ***tab);
void	display_message(int word, char *message, int status);

#endif
