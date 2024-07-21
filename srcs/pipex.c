/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:26:21 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 12:12:11 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_pipex *pipex, char **envp, int i)
{
	if (pipex->cmds_path[i])
	{
		if (execve(pipex->cmds_path[i], pipex->cmds_list[i], envp) == -1)
		{
			perror("Execve");
			exit_program(pipex, 0, NULL, FAIL);
		}
	}
	else
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(pipex->cmds_list[i][0], 2);
		ft_putchar_fd('\n', 2);
		exit_program(pipex, 0, NULL, FAIL);
	}
}

void	first_cmd(char *infile, t_pipex *pipex, char **envp)
{
	pipex->child[0] = fork();
	if (pipex->child[0] == -1)
	{
		perror("Fork");
		exit_program(pipex, 0, NULL, FAIL);
	}
	else if (pipex->child[0] == 0)
	{
		(dup_stdin_to_infile(infile, pipex), dup_stdout_to_fd1(pipex));
		(close(pipex->fd[0]), close(pipex->fd[1]));
		exec_cmd(pipex, envp, 0);
	}
}

void	last_cmd(char *outfile, t_pipex *pipex, char **envp)
{
	pipex->child[1] = fork();
	if (pipex->child[1] == -1)
	{
		perror("Fork");
		exit_program(pipex, 0, NULL, FAIL);
	}
	else if (pipex->child[1] == 0)
	{
		(dup_stdin_to_fd0(pipex), dup_stdout_to_outfile(outfile, pipex));
		(close(pipex->fd[0]), close(pipex->fd[1]));
		exec_cmd(pipex, envp, 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (display_message(1, E_INV_PARAM, FAIL), FAIL);
	init_mallocs(&pipex);
	get_paths(envp, &pipex);
	get_cmds(argc, argv, &pipex);
	get_valid_cmd_paths(&pipex, argc - 3);
	if (pipe(pipex.fd) == -1)
		return (perror("Pipe"), free_malloced_ptrs(&pipex), FAIL);
	first_cmd(argv[1], &pipex, envp);
	last_cmd(argv[argc - 1], &pipex, envp);
	(close(pipex.fd[0]), close(pipex.fd[1]));
	waitpid(pipex.child[0], NULL, 0);
	waitpid(pipex.child[1], NULL, 0);
	return (free_malloced_ptrs(&pipex), SUCCESS);
}
