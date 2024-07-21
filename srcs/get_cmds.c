/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:15:19 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/20 17:02:14 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	join_paths_and_cmds(t_pipex *pipex, int i, int j)
{
	pipex->slash = ft_strjoin(pipex->env_paths[j], "/");
	if (!pipex->slash)
		exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
	pipex->full_path_cmd = ft_strjoin(pipex->slash, pipex->cmds_list[i][0]);
	if (!pipex->full_path_cmd)
		exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
}

void	init_cmds_path(t_pipex *pipex, int cmd_nb)
{
	pipex->cmds_path = (char **)ft_calloc(sizeof(char *), (cmd_nb + 1));
	if (!pipex->cmds_path)
		exit_program(pipex, 1, E_FAILED_MALLOC, FAIL);
}

void	get_cmds(int argc, char **argv, t_pipex *pipex)
{
	int			cmds_nb;
	int			i;
	int			j;

	cmds_nb = argc - 3;
	pipex->cmds_list = (char ***)ft_calloc(sizeof(char **), (cmds_nb + 1));
	if (!pipex->cmds_list)
		exit_program(pipex, 1, E_FAILED_MALLOC, FAIL);
	i = 0;
	j = 2;
	while (cmds_nb--)
	{
		pipex->cmds_list[i] = ft_split(argv[j], ' ');
		if (!pipex->cmds_list[i])
			exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
		i++;
		j++;
	}
}
