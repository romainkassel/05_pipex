/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:15:19 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 11:46:07 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	join_paths_and_cmds(t_pipex *pipex, int i, int j)
{
	pipex->slash = ft_strjoin(pipex->env_paths[j], "/");
	if (!pipex->slash)
		exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
	pipex->full_path_cmd = ft_strjoin(pipex->slash, pipex->cmds_list[i][0]);
	if (!pipex->full_path_cmd)
		exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
}

void	init_cmds_path(t_pipex *pipex)
{
	pipex->cmds_path = (char **)ft_calloc(sizeof(char *), (pipex->cmd_nb + 1));
	if (!pipex->cmds_path)
		exit_program(pipex, 1, E_FAILED_MALLOC, FAIL);
}

void	init_cmd_args(int argc, char **argv, t_pipex *pipex)
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		pipex->here_doc = 1;
		pipex->i_first_cmd = 3;
		pipex->cmd_nb = argc - 4;
	}
	else
	{
		pipex->i_first_cmd = 2;
		pipex->cmd_nb = argc - 3;
	}
}

void	get_cmds_list(char **argv, t_pipex *pipex)
{
	int			cmds_nb;
	int			i;
	int			j;

	cmds_nb = pipex->cmd_nb;
	pipex->cmds_list = (char ***)ft_calloc(sizeof(char **), (cmds_nb + 1));
	if (!pipex->cmds_list)
		exit_program(pipex, 1, E_FAILED_MALLOC, FAIL);
	i = 0;
	j = pipex->i_first_cmd;
	while (cmds_nb--)
	{
		pipex->cmds_list[i] = ft_split(argv[j], ' ');
		if (!pipex->cmds_list[i])
			exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
		i++;
		j++;
	}
}
