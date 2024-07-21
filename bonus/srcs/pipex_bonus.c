/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:26:21 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/21 12:52:25 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_program_minimalist(t_pipex *pipex)
{
	if (pipex->fd)
		close_fds(pipex);
	free_all(pipex);
	del_hd(pipex);
}

void	del_hd(t_pipex *pipex)
{
	if (pipex->heredoc_name)
	{
		if (unlink(pipex->heredoc_name) == -1)
			perror("Unlink");
		pipex->heredoc_name = NULL;
	}
}

void	make_here_doc_work(char **argv, t_pipex *pipex)
{
	int		fd_here_doc;
	char	*buff;

	fd_here_doc = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd_here_doc == -1)
	{
		(ft_putstr_fd(strerror(errno), 2), ft_putstr_fd(": ", 2));
		(ft_putstr_fd(argv[1], 2), ft_putchar_fd('\n', 2));
		exit_program(pipex, 0, NULL, FAIL);
	}
	pipex->heredoc_name = argv[1];
	pipex->limiter_with_slash_n = ft_strjoin(argv[2], "\n");
	if (!pipex->limiter_with_slash_n)
		exit_program(pipex, 1, E_NULL_MALLOC, FAIL);
	buff = get_next_line(STDIN_FILENO);
	if (ft_strcmp(buff, pipex->limiter_with_slash_n) != 0)
		ft_putstr_fd(buff, fd_here_doc);
	while (ft_strcmp(buff, pipex->limiter_with_slash_n) != 0)
	{
		free(buff);
		buff = get_next_line(STDIN_FILENO);
		if (ft_strcmp(buff, pipex->limiter_with_slash_n) != 0)
			ft_putstr_fd(buff, fd_here_doc);
	}
	(free(buff), close(fd_here_doc));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	(main_checking(argc, argv, &pipex, envp), pipex.i = 0);
	while (pipex.i < pipex.cmd_nb)
	{
		pipex.child[pipex.i] = fork();
		if (pipex.child[pipex.i] == -1)
			return (perror("Fork"), exit_program_minimalist(&pipex), FAIL);
		if (pipex.child[pipex.i] == 0)
		{
			if (pipex.i == 0)
				first_cmd(argv[1], &pipex, pipex.i);
			else if (pipex.i > 0 && pipex.i < (pipex.cmd_nb - 1))
				mid_cmd(&pipex, pipex.i);
			else if (pipex.i == (pipex.cmd_nb - 1))
				last_cmd(argv[argc - 1], &pipex, pipex.i);
			(close_fds(&pipex), exec_cmd(&pipex, pipex.i, envp));
		}
		pipex.i++;
	}
	(close_fds(&pipex), pipex.i = 0);
	while (pipex.i < pipex.cmd_nb)
		waitpid(pipex.child[pipex.i++], NULL, 0);
	return (free_all(&pipex), SUCCESS);
}
