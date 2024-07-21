/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes_proc_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:15:19 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/20 19:53:57 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_proc(t_pipex *pipex)
{
	pipex->child = (pid_t *)ft_calloc(sizeof(pid_t), pipex->cmd_nb);
	if (!pipex->child)
		exit_program(pipex, 1, E_FAILED_MALLOC, FAIL);
}

void	init_pipes(t_pipex *pipex)
{
	int	i;

	pipex->pipe_nb = pipex->cmd_nb - 1;
	pipex->fd = (int **)ft_calloc(sizeof(int *), pipex->pipe_nb);
	if (!pipex->fd)
		exit_program(pipex, 1, E_FAILED_MALLOC, FAIL);
	i = 0;
	while (i < pipex->pipe_nb)
	{
		pipex->fd[i] = (int *)ft_calloc(sizeof(int), 2);
		if (pipe(pipex->fd[i]) == -1)
			(perror("Pipe"), free_all(pipex), exit(FAIL));
		i++;
	}
}

void	init_pipes_and_proc(t_pipex *pipex)
{
	init_pipes(pipex);
	init_proc(pipex);
}

void	free_double_fd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_nb)
		free(pipex->fd[i++]);
	free(pipex->fd);
}
