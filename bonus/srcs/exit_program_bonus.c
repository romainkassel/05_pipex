/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:08:07 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 12:33:10 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_malloced_ptrs(t_pipex *pipex)
{
	pipex->env_paths = NULL;
	pipex->cmds_list = NULL;
	pipex->cmds_path = NULL;
	pipex->child = NULL;
	pipex->fd = NULL;
	pipex->limiter_with_slash_n = NULL;
	pipex->slash = NULL;
	pipex->full_path_cmd = NULL;
	pipex->here_doc = 0;
	pipex->heredoc_name = NULL;
}

void	free_triple_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free_double_tab(tab[i++]);
	free(tab);
}

void	free_all(t_pipex *pipex)
{
	int	i;

	if (pipex->env_paths)
		free_double_tab(pipex->env_paths);
	if (pipex->cmds_list)
		free_triple_tab(pipex->cmds_list);
	if (pipex->fd)
		free_double_fd(pipex);
	i = 0;
	if (pipex->cmds_path)
	{
		while (i <= pipex->cmd_nb)
			free(pipex->cmds_path[i++]);
		free(pipex->cmds_path);
	}
	if (pipex->child)
		free(pipex->child);
	if (pipex->limiter_with_slash_n)
		free(pipex->limiter_with_slash_n);
	if (pipex->slash)
		free(pipex->slash);
	if (pipex->full_path_cmd)
		free(pipex->full_path_cmd);
}

void	exit_program(t_pipex *pipex, int word, char *message, int status)
{
	display_message(word, message, status);
	if (pipex->fd)
		close_fds(pipex);
	free_all(pipex);
	del_hd(pipex);
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
