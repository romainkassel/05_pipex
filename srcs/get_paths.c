/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:05:23 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/20 17:03:20 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_paths_len(char **env_paths)
{
	int	i;

	i = 0;
	while (env_paths[i])
		i++;
	return (i);
}

char	*del_path_word(char *env_paths_0, t_pipex *pipex)
{
	char	*new_str;

	new_str = ft_strdup(env_paths_0 + 5);
	if (!new_str)
		exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
	free(env_paths_0);
	return (new_str);
}

void	get_paths(char **envp, t_pipex *pipex)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H' && envp[i][4] == '=')
		{
			pipex->env_paths = ft_split(envp[i], ':');
			if (!pipex->env_paths)
				exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
		}
		i++;
	}
	if (pipex->env_paths)
		pipex->env_paths[0] = del_path_word(pipex->env_paths[0], pipex);
}

int	fill_valid_path(t_pipex *pipex, char *full_path_cmd, int i)
{
	int	j;

	pipex->cmds_path[i] = ft_strdup(full_path_cmd);
	if (!pipex->cmds_path[i])
		exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
	if (pipex->env_paths)
		j = get_paths_len(pipex->env_paths);
	else
		j = 0;
	return (j);
}

void	get_valid_cmd_paths(t_pipex *pipex, int cmd_nb)
{
	int			i;
	int			j;

	(init_cmds_path(pipex, cmd_nb), i = 0);
	while (pipex->cmds_list[i])
	{
		j = 0;
		if (access(pipex->cmds_list[i][0], X_OK) == 0)
			j = fill_valid_path(pipex, pipex->cmds_list[i][0], i);
		if (pipex->env_paths)
		{
			while (pipex->env_paths[j])
			{
				join_paths_and_cmds(pipex, i, j);
				j++;
				if (access(pipex->full_path_cmd, X_OK) == 0)
					j = fill_valid_path(pipex, pipex->full_path_cmd, i);
				(free(pipex->slash), pipex->slash = NULL);
				(free(pipex->full_path_cmd), pipex->full_path_cmd = NULL);
			}
		}
		i++;
	}
}
