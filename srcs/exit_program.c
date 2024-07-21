/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:08:07 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/20 17:04:22 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_mallocs(t_pipex *pipex)
{
	pipex->env_paths = NULL;
	pipex->cmds_list = NULL;
	pipex->cmds_path = NULL;
	pipex->slash = NULL;
	pipex->full_path_cmd = NULL;
}

void	free_triple_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free_double_tab(tab[i++]);
	free(tab);
}

void	free_malloced_ptrs(t_pipex *pipex)
{
	int	i;

	if (pipex->env_paths)
		free_double_tab(pipex->env_paths);
	if (pipex->cmds_list)
		free_triple_tab(pipex->cmds_list);
	if (pipex->slash)
		free(pipex->slash);
	if (pipex->full_path_cmd)
		free(pipex->full_path_cmd);
	i = 0;
	if (pipex->cmds_path)
	{
		while (i < 3)
		{
			free(pipex->cmds_path[i]);
			i++;
		}
		free(pipex->cmds_path);
	}
}

void	exit_program(t_pipex *pipex, int word, char *message, int status)
{
	display_message(word, message, status);
	free_malloced_ptrs(pipex);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	exit(status);
}

void	display_message(int word, char *status_message, int status)
{
	if (status == FAIL)
	{
		if (word == 1)
			ft_putstr_fd("Error\n", 2);
		if (status_message)
		{
			ft_putstr_fd(status_message, 2);
			ft_putchar_fd('\n', 2);
		}
	}
	else
	{
		if (word == 1)
			ft_putstr_fd("Success\n", 1);
		if (status_message)
		{
			ft_putstr_fd(status_message, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}
