/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checking_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:26:21 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 12:27:27 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	main_checking(int argc, char **argv, t_pipex *pipex, char **envp)
{
	init_malloced_ptrs(pipex);
	if (argc < 5 || (ft_strcmp(argv[1], "here_doc") == 0 && argc < 6))
		exit_program(pipex, 1, E_INV_PARAM, FAIL);
	init_cmd_args(argc, argv, pipex);
	(get_env_paths(envp, pipex), get_cmds_list(argv, pipex));
	get_valid_cmd_paths(pipex);
	init_pipes_and_proc(pipex);
	if (pipex->here_doc)
		make_here_doc_work(argv, pipex);
}
