/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:14:54 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 12:06:10 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup_stdout_to_outfile(char *out, t_pipex *pipex)
{
	int	outfile;
	int	dup_out;

	if (pipex->here_doc)
		outfile = open(out, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		outfile = open(out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(out, 2);
		ft_putchar_fd('\n', 2);
		exit_program(pipex, 0, NULL, FAIL);
	}
	dup_out = dup2(outfile, 1);
	if (dup_out == -1)
	{
		perror("Dup2");
		exit_program(pipex, 0, NULL, FAIL);
	}
	close(outfile);
}

void	dup_stdin_to_infile(char *in, t_pipex *pipex)
{
	int	infile;
	int	dup_in;

	infile = open(in, O_RDONLY);
	if (infile == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(in, 2);
		ft_putchar_fd('\n', 2);
		exit_program(pipex, 0, NULL, FAIL);
	}
	dup_in = dup2(infile, 0);
	if (dup_in == -1)
	{
		perror("Dup2");
		exit_program(pipex, 0, NULL, FAIL);
	}
	close(infile);
	del_hd(pipex);
}

void	dup_stdout_to_fd1(t_pipex *pipex, int i)
{
	int	dup_fd1;

	dup_fd1 = dup2(pipex->fd[i][1], 1);
	if (dup_fd1 == -1)
	{
		perror("Dup2");
		exit_program(pipex, 0, NULL, FAIL);
	}
}

void	dup_stdin_to_fd0(t_pipex *pipex, int i)
{
	int	dup_fd0;

	dup_fd0 = dup2(pipex->fd[i][0], 0);
	if (dup_fd0 == -1)
	{
		perror("Dup2");
		exit_program(pipex, 0, NULL, FAIL);
	}
}

void	close_fds(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_nb)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		i++;
	}
}
