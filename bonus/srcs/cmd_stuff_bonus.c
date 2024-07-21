/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stuff_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:26:21 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 12:07:43 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_cmd(char *infile, t_pipex *pipex, int i)
{
	dup_stdin_to_infile(infile, pipex);
	dup_stdout_to_fd1(pipex, i);
}

void	mid_cmd(t_pipex *pipex, int i)
{
	dup_stdin_to_fd0(pipex, i - 1);
	dup_stdout_to_fd1(pipex, i);
}

void	last_cmd(char *outfile, t_pipex *pipex, int i)
{
	dup_stdin_to_fd0(pipex, i - 1);
	dup_stdout_to_outfile(outfile, pipex);
}

void	exec_cmd(t_pipex *pipex, int i, char **envp)
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
