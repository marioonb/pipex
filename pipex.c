/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/06/19 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(int index, char *string)
{
	if (index == 1)
		printf("%s d'arguments\n", string);
	else if (index == 2)
		printf("echec malloc\n");
	else if (index == 3)
		printf("erreur d'ouverture de pipe\n");
	else if (index == 4)
		printf("fichier introuvable ou echec ouverture du fichier %s\n", string);
	else if (index == 5)
		printf("command not found");
	else if (index == 6)
		printf("permission non accordee");
	exit(EXIT_FAILURE);
}

void	check_argument(char **tab)
{
	if (tab[2][0] == ' ')
		ft_error(5, tab[2]);
	if (tab[3][0] == ' ')
		ft_error(5, tab[3]);
	if (tab[2][0] == '\0' || tab[3][0] == '\0')
		ft_error(6, "");
}

void	fill_cmd(char **tab, t_cmd *cmd)
{
	cmd->cmd1 = ft_strdup(tab[2]);
	cmd->filefd1 = open(tab[1], O_RDONLY);
	cmd->cmd2 = ft_strdup(tab[3]);
	cmd->filefd2 = open(tab[4], O_WRONLY | O_CREAT | O_TRUNC, 00700);
	if (cmd->filefd1 == -1)
		printf("fichier introuvable ou echec ouverture du fichier %s\n", tab[1]);
	if (cmd->filefd2 == -1)
		ft_error(4, tab[4]);
}

void	free_struct(t_cmd *cmd)
{
	free(cmd->cmd1);
	free(cmd->cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	pid_t	pid;
	int		fd[2];

	if (argc > 5)
		ft_error(1, "trop");
	if (argc < 5)
		ft_error(1, "pas assez");
	check_argument(argv);
	fill_cmd(argv, &cmd);
	pipe(fd);
	pid = fork();
	if (pid == 0)
		exec_cmd1(cmd.cmd1, cmd.filefd1, fd, envp);
	else
		exec_cmd2(cmd.cmd2, cmd.filefd2, fd, envp);
	close(cmd.filefd1);
	close(cmd.filefd2);
	free_struct(&cmd);
	return (0);
}
