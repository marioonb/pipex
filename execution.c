/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/06/19 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(char **tab, char **env)
{
	char	*cpy;
	int		x;

	cpy = tab[0]; //  pour renvoyer dans l'erreur car get_path supprime
	x = get_path(tab, env);
	if (x == 1)
		execve(tab[0], tab, env);
	else if (x != -1)
		printf("error");
}

void	exec_cmd1(char *cmd, int filefd, int fd[2], char **env)
{
	char	**cmd_split;

	close(fd[0]);
	dup2(fd[1], 1);
	dup2(filefd, 0);
	close(fd[1]);
	cmd_split = ft_split(cmd, ' ');
	if (filefd != -1)
		exec_cmd(cmd_split, env);
	free_tab_char(cmd_split);
}

void	exec_cmd2(char *cmd, int filefd, int fd[2], char **env)
{
	char	**cmd_split;

	close(fd[1]);
	dup2(fd[0], 0);
	dup2(filefd, 1);
	close(fd[0]);
	cmd_split = ft_split(cmd, ' ');
	exec_cmd(cmd_split, env);
	free_tab_char(cmd_split);
}
